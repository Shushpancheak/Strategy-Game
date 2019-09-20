#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "GraphicComponent.hpp"
#include "Strings.hpp"
#include "Constants.hpp"
#include "Sprites.hpp"
#include <fstream>
#include <iostream>
#include "ResourceManager.hpp"

// - - - - - - - - - - - - - - INITIALIZATION - - - - - - - - - - - - - -

Game::Game()
  : window_(std::make_shared<sf::RenderWindow>(
              sf::VideoMode(constants::kScreenWidth,
              constants::kScreenHeight),
              constants::ksWindowName,
              sf::Style::Fullscreen
            ))
  , executed_(false)
  , windowed_(false)
  , screen_(std::make_shared<GraphicComponent>(window_, nullptr, sf::Texture(), 1))
  , map_(nullptr)
  , entities_(0)
  , chosen_unit_(0) {
  map_ = std::make_shared<Map>(
    screen_,
    window_
  );

  map_graphic_component_ = map_->GetMapGraphicComponent();

  font_.loadFromFile("Fonts/Consolas.ttf");
  scale_percent_text_.setFont(font_);
}

Game::~Game() {
  ResourceManager::GetInstance()->Unload();
}

// - - - - - - - - - - - - - - MAIN LOOP - - - - - - - - - - - - - - - - -

void Game::Execute() {
  if (executed_) {
    return;
  }
  executed_ = true;

  while (window_->isOpen()) {
    sf::Event event{};

    while (window_->pollEvent(event)) {
      HandleEvent(event);
    }

    // Moving map using keyboard or mouse.
    auto move_vec = GetMapMoveByKeyboard();
    if (move_vec != sf::Vector2<float>(0, 0)) {
      map_graphic_component_->MoveVec2(move_vec);
    } else {
      map_graphic_component_->MoveVec2(GetMapMoveByMouse());
    }

    window_->clear();

    // Drawing everything on the screen_, mainly, the map.
    screen_->Draw();
    GraphicComponent::DrawPushed();

    DrawInfo();

    window_->display();
  }
}

sf::Vector2<float> Game::GetMapMoveByMouse() const {
  sf::Vector2<float> res(0.f, 0.f);
  auto mouse_position = sf::Mouse::getPosition();
  const auto window_position = window_->getPosition() +
                               (windowed_ ? constants::kMouseBorderError : sf::Vector2<int>(0, 0));

  // If mouse is out of window, then just don't do anything.
  if (mouse_position.x < window_position.x ||
      mouse_position.y < window_position.y ||
      mouse_position.x > window_position.x + static_cast<int>(window_->getSize().x) ||
      mouse_position.y > window_position.y + static_cast<int>(window_->getSize().y)) {
    return res;
  }

  // Counting mouse position from top left corner.
  mouse_position -= window_position;

  if (mouse_position.x < constants::kMouseBorderWidth) {
    res.x = constants::kMapMovePerFrame *
            (1.f - (static_cast<float>(mouse_position.x) /
              constants::kMouseBorderWidth));
  }
  if (mouse_position.y < constants::kMouseBorderHeight) {
    res.y = constants::kMapMovePerFrame *
            (1.f - (static_cast<float>(mouse_position.y) /
              constants::kMouseBorderHeight));
  }
  if (mouse_position.x > static_cast<int>(window_->getSize().x) -
      constants::kMouseBorderWidth) {
    res.x = -constants::kMapMovePerFrame *
            (1.f - static_cast<float>(static_cast<int>(window_->getSize().x) - mouse_position.x) /
              constants::kMouseBorderWidth);
  }
  if (mouse_position.y > static_cast<int>(window_->getSize().y) -
      constants::kMouseBorderHeight) {
    res.y = -constants::kMapMovePerFrame *
            (1.f - static_cast<float>(static_cast<int>(window_->getSize().y) - mouse_position.y) /
              constants::kMouseBorderHeight);
  }

  return res;
}

sf::Vector2<float> Game::GetMapMoveByKeyboard() const {
  sf::Vector2<float> res(0.f, 0.f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    res += {constants::kMapMovePerFrame, 0};
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    res += {-constants::kMapMovePerFrame, 0};
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H)) {
    res += {0, constants::kMapMovePerFrame};
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    res += {0, -constants::kMapMovePerFrame};
  }
  return res;
}

void Game::HandleEvent(const sf::Event& event) {
  switch (event.type) {
  case (sf::Event::Closed): {
    window_->close();
    return;
  }
    // catch the resize events
  case (sf::Event::Resized): {
    // Update the view to the new size of the window
    const sf::FloatRect visible_area(0, 0, event.size.width, event.size.height);
    window_->setView(sf::View(visible_area));
  }
  case (sf::Event::KeyPressed): {
    HandleKeyPressed(event);
  }
  case (sf::Event::MouseButtonPressed): {
    HandleMouseClicked(event);
  }
  case (sf::Event::MouseWheelScrolled): {
    // Scaling.
    const auto previous_scale = map_graphic_component_->GetGlobalScale();
    const auto scale_change = event.mouseWheelScroll.delta * constants::kMapScalePerScroll * previous_scale;
    const auto window_position = window_->getPosition() +
                               (windowed_ ? constants::kMouseBorderError : sf::Vector2<int>(0, 0));

    map_graphic_component_->ChangeGlobalScaleRecursively(scale_change);

    // Moving map view so that we're getting closer to the mouse.
    auto mouse_position = sf::Mouse::getPosition();
    // Counting mouse position from top left corner.
    mouse_position -= window_position;

    const auto scaled_part = 1.f + scale_change / previous_scale;
    const auto new_scale = map_graphic_component_->GetGlobalScale();
    const auto view_position = sf::Vector2<float>((1.f - scaled_part) * mouse_position.x / new_scale,
                                                  (1.f - scaled_part) * mouse_position.y / new_scale);
    map_graphic_component_->MoveVec2(view_position);
  }
  default: ;
  }
}

void Game::HandleKeyPressed(const sf::Event& event) {
  if (event.key.code == sf::Keyboard::Key::Escape) {
    window_->close();
    return;
  }
  if (event.key.code == sf::Keyboard::Key::Q) {
    chosen_unit_ = 0;
  }
  if (event.key.code == sf::Keyboard::Key::W) {
    chosen_unit_ = 1;
  }
  if (event.key.code == sf::Keyboard::Key::Enter &&
      sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) ||
      event.key.code == sf::Keyboard::Key::RAlt &&
      sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    window_->create(
      sf::VideoMode(constants::kScreenWidth,
                    constants::kScreenHeight),
      constants::ksWindowName,
      (windowed_ ? sf::Style::Fullscreen : sf::Style::Default)
    );
    windowed_ = !windowed_;
  }
}

void Game::HandleMouseClicked(const sf::Event& event) {
  auto mouse_pos = sf::Mouse::getPosition();
  const auto window_position = window_->getPosition() +
     (windowed_ ? constants::kMouseBorderError : sf::Vector2<int>(0, 0));

  mouse_pos -= window_position;

  std::shared_ptr<Entity> unit = std::make_shared<Entity>(mouse_pos.x, mouse_pos.y);

  if (chosen_unit_ == 0) {
    unit->GetComponents().push_back(
    std::make_shared<GraphicComponent>(
      window_,
      map_graphic_component_,
      ResourceManager::GetInstance()->GetTexture("tankb")
      )
    );
  } else {
    unit->GetComponents().push_back(
    std::make_shared<GraphicComponent>(
      window_,
      map_graphic_component_,
      ResourceManager::GetInstance()->GetTexture("tankr")
      )
    );
  }

  std::dynamic_pointer_cast<GraphicComponent>
  (unit->GetComponents()[0])->SetXy(mouse_pos.x, mouse_pos.y);

  map_->AddEntity(unit);
}

void Game::DrawInfo() {
  scale_percent_text_.setString(std::to_string(map_graphic_component_->GetGlobalScale() * 100).substr(0, 5) + "%");
  scale_percent_text_.setCharacterSize(16);
  scale_percent_text_.setFillColor(sf::Color::White);
  window_->draw(scale_percent_text_);
}
