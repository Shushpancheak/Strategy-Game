#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "GraphicComponent.hpp"
#include "Strings.hpp"
#include <iostream>

// - - - - - - - - - - - - - - INITIALIZATION - - - - - - - - - - - - - -

Game::Game()
  : executed_(false)
  , window_(std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), constants::ksWindowName)) {}

Game::~Game() {
  std::cout << "Game D\n";
}

// - - - - - - - - - - - - - - MAIN LOOP - - - - - - - - - - - - - - - - -

void Game::Execute() {
  if (executed_) {
    return;
  }
  executed_ = true;

  // Main screen -- graphic component that holds all other.
  // GraphicComponent - composite structure, so executing Draw()
  // inside screen will execute other Draws inside tree via BFS.
  auto screen = GraphicComponent(
    window_,
    nullptr
  );

  screen.base_sprite = std::make_shared<sf::CircleShape>(100.f, 100);

  while (window_->isOpen()) {
    sf::Event event{};

    // Exit.
    while (window_->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window_->close();
      }
    }

    window_->clear();

    screen.Draw();
    GraphicComponent::DrawAll();

    window_->display();
  }
}
