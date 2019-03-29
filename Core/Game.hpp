#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicComponent.hpp"
#include "Entity/Entity.hpp"
#include "Map.hpp"

/**
 * \brief A singleton main Game class.
 * \details Main interactions happen here. Use Execute() to start
 * the main loop.
 */
class Game {
 public:
  ~Game();
  Game();

  /**
   * \brief Execute the main loop in render window.
   */
  void Execute();

 private:
  std::shared_ptr<sf::RenderWindow> window_;
  bool executed_;
  // Main screen -- graphic component that holds all other.
  // GraphicComponent - composite structure, so executing Draw()
  // inside screen will execute other Draws inside tree via BFS.
  GraphicComponent screen_;
  Map map_;
  std::vector<Entity> entities_;
};