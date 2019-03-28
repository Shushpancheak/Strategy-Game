#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include "../Constants/Strings.hpp"
#include "GraphicComponent/GraphicComponent.hpp"

// - - - - - - - - - - - - - - INITIALIZATION - - - - - - - - - - - - - -

Game::Game()
  : executed_(false)
  , window_(sf::VideoMode(200, 200), constants::ksWindowName) {}

Game::~Game() = default;

// - - - - - - - - - - - - - - MAIN LOOP - - - - - - - - - - - - - - - - -

void Game::Execute() {
  if (executed_) {
    return;
  }
  executed_ = true;

  // Main screen -- graphic component that holds all other.
  // GraphicComponent - composite structure, so executing Draw()
  // inside screen will execute other Draws inside tree via BFS.
  GraphicComponent screen = GraphicComponent(
    std::make_shared<sf::RenderWindow>(window_),
    nullptr
  );

  while (window_.isOpen()) {
    sf::Event event{};

    // Exit.
    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window_.close();
      }
    }

    window_.clear();

    screen.Draw();

    window_.display();
  }
}

std::shared_ptr<Game> Game::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = std::make_shared<Game>();
  }

  return instance_;
}

std::shared_ptr<Game> Game::instance_(nullptr);
