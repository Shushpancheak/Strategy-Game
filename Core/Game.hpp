#pragma once
#include <SFML/Graphics.hpp>

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
  bool executed_;
  std::shared_ptr<sf::RenderWindow> window_;
};