#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicComponent.hpp"
#include "Entity/Entity.hpp"
#include "Map.hpp"
#include <unordered_map>

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
  /**
   * \brief Used for map moving. Calculates move vector for map depending
   * on mouse position.
   */
  sf::Vector2<float> GetMapMoveByMouse() const;
  /**
   * Calculates move vector for map depending on keyboard input.
   */
  sf::Vector2<float> GetMapMoveByKeyboard() const;

  /**
   * \brief Handles events caught in while(poll event).
   */
  void HandleEvent(const sf::Event& event);
  /**
   * \brief Handles Event::KeyPressed.
   */
  void HandleKeyPressed(const sf::Event& event);
  void HandleMouseClicked(const sf::Event& event);

 private:
  /**
   * Draws text information (should be called after drawing other GUI).
   */
  void DrawInfo();

  std::shared_ptr<sf::RenderWindow> window_;
  bool executed_;
  bool windowed_;
  // Main screen -- graphic component that holds all other.
  // GraphicComponent - composite structure, so executing Draw()
  // inside screen will execute other Draws inside tree via BFS.
  std::shared_ptr<GraphicComponent> screen_;
  std::shared_ptr<Map> map_;
  // Map graphic component, which is moved when we want to move 'camera'.
  std::shared_ptr<GraphicComponent> map_graphic_component_;
  std::vector<Entity> entities_;

  sf::Font font_;
  sf::Text scale_percent_text_;
};