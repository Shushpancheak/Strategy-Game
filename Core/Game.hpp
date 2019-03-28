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

  /**
   * \brief Execute the main loop in render window.
   */
  void Execute();
  static std::shared_ptr<Game> GetInstance();

 private:
  Game();

  bool executed_;
  sf::RenderWindow window_;

  static std::shared_ptr<Game> instance_;
};