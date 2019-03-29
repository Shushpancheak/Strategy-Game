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
 * Also uses fly-weight design pattern for sprites.
 */
class GraphicComponent : public Component {
 public:
  GraphicComponent(std::shared_ptr<sf::RenderWindow> window = nullptr,
                            const std::shared_ptr<GraphicComponent>& parent = nullptr,
                            const sf::Texture& source_texture = sf::Texture(),
                            const size_t variants = 1,
                            const size_t animated_frames = 0,
                            sf::Sprite sprite = sf::Sprite(),
                            const DrawVariant draw_what = kAll);
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

  // Sprite-related:
  size_t variants;
  // If animated, it must be != 0
  size_t animated_frames;
  
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

  // Fly-weight implementation.
  // it is a fly-weight structure because Texture (the most heavy item in structure)
  // is used as const reference, so no copying.
  sf::Sprite sprite_;

  // As for now, texture should be an image consisting of constants::.x. rectangles.
  // ++== sprites heading south.
  // || ++== north.............. !!! For now, using only south...
  // \/ \/
  // __ __ __ __
  //|__|__|__|__| < First variant. Variants are treated in different ways: they can be random or specific.
  //|__|__|__|__| < Second variant.
  //|__|__|__|__| < (If animated_frames != 0) First variant -- 2nd frame.
  //|__|__|__|__| < (If animated_frames != 0) Second variant -- 2nd frame.
  //|__|__|__|__| < ............
  const sf::Texture& source_texture_;
  
  float animated_fps_;

  std::vector<std::shared_ptr<GraphicComponent>> children_;
  std::shared_ptr<GraphicComponent> parent_;
  std::shared_ptr<sf::RenderWindow> window_;

  static std::queue<std::shared_ptr<GraphicComponent>> main_queue_;
};
