#pragma once
#include <memory>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>
#include "DrawVariant.hpp"
#include "Component.hpp"

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
class GraphicComponent : public Component {
 public:
  explicit GraphicComponent(std::shared_ptr<sf::RenderWindow> window,
                            const std::shared_ptr<GraphicComponent>& parent,
                            const DrawVariant draw_what = kAll,
                            std::shared_ptr<sf::Drawable> base_sprite = nullptr);
  ~GraphicComponent();

  void Draw();
  std::vector<std::shared_ptr<GraphicComponent>> GetChildren() const;
  void AddChild(const std::shared_ptr<GraphicComponent>& child);
  void AddChild(std::shared_ptr<GraphicComponent>&& child);
  void SetXy(const float& x, const float& y);
  void MoveXy(const float& x, const float& y);
  void SetScale(const float& scale);
  void SetRotationDegrees(const float& deg);
  float GetX() const;
  float GetY() const;
  float GetAbsX() const;
  float GetAbsY() const;
  float GetScale() const;
  float GetRotationDegrees() const;
  
  // BFS.
  static void DrawAll();

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
  // Rotation degrees.
  float deg_;
  // Scale.
  float scale_;

  std::vector<std::shared_ptr<GraphicComponent>> children_;
  std::shared_ptr<GraphicComponent> parent_;
  std::shared_ptr<sf::RenderWindow> window_;

  static std::queue<std::shared_ptr<GraphicComponent>> main_queue_;
};
