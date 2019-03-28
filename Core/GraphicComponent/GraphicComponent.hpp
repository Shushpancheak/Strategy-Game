#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <queue>

#include "DrawVariant.hpp"
#include <SFML/Graphics/Shape.hpp>

/**
 * \brief Realizes pattern Composite: it draws itself and its children recursively.
 * \details You can set draw_what variable to select 
 * what to draw (parent, children, or nothing at all).
 * 
 * Graphic components have tree structure. The drawing should be happening as BFS with
 * drawing each component and then adding its children to a drawing queue.
 * 
 * So it is guaranteed that if a component has a greater depth in the tree than another,
 * then it will be drawn over another one.
 * 
 * Also uses fly-weight pattern for sprites.
 */
class GraphicComponent {
 public:
  explicit GraphicComponent(std::shared_ptr<sf::RenderWindow> window,
                            const std::shared_ptr<GraphicComponent>& parent,
                            const DrawVariant draw_what = kAll,
                            std::shared_ptr<sf::Drawable> base_sprite = nullptr);
  ~GraphicComponent();

  void Draw();
  std::vector<std::shared_ptr<GraphicComponent>> GetChildren() const;
  void AddChild(const std::shared_ptr<GraphicComponent>& child);
  void SetXY(const float& x, const float& y);
  void MoveXY(const float& x, const float& y);
  float GetX();
  float GetY();
  float GetAbsX();
  float GetAbsY();

  DrawVariant draw_what;
  // Fly-weight implementation.
  std::shared_ptr<sf::Drawable> base_sprite;
  
 private:
  // Relative to parent's x/y.
  float x_, y_;
  // Absolute x/y, relative to main screen's.
  // Used to pick whether or not should we draw the sprite.
  // Absolute x/y are counted on every Draw() as the sum of 
  // its x/y and parent's. So, as the drawing happens as BFS,
  // we'll have absolute x/y prior to the main screen graphic
  // component.
  float abs_x_, abs_y_;

  std::vector<std::shared_ptr<GraphicComponent>> children_;
  std::shared_ptr<GraphicComponent> parent_;
  std::shared_ptr<sf::RenderWindow> window_;

  static std::queue<std::shared_ptr<GraphicComponent>> main_queue_;
};
