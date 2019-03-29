#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "GraphicComponent.hpp"
#include "Strings.hpp"
#include "Constants.hpp"

// - - - - - - - - - - - - - - INITIALIZATION - - - - - - - - - - - - - -

Game::Game()
  : window_(std::make_shared<sf::RenderWindow>(sf::VideoMode(constants::kScreenWidth, 
    constants::kScreenHeight), constants::ksWindowName))
  , executed_(false)
  , screen_(window_, nullptr)
  , entities_(0) {
  
}

Game::~Game() = default;

// - - - - - - - - - - - - - - MAIN LOOP - - - - - - - - - - - - - - - - -

void Game::Execute() {
  if (executed_) {
    return;
  }
  executed_ = true;

  while (window_->isOpen()) {
    sf::Event event{};

    // Exit.
    while (window_->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window_->close();
      }
    }

    window_->clear();

    screen_.Draw();
    GraphicComponent::DrawAll();

    window_->display();
  }
}
