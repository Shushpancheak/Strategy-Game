#include "GraphicComponent.hpp"
#include <utility>

GraphicComponent::GraphicComponent(std::shared_ptr<sf::RenderWindow> window,
                                   const std::shared_ptr<GraphicComponent>& parent,
                                   const DrawVariant draw_what,
                                   std::shared_ptr<sf::Drawable> base_sprite) 
  : draw_what(draw_what)
  , base_sprite(std::move(base_sprite))
  , x_(0)
  , y_(0)
  , abs_x_(0) // Always.
  , abs_y_(0) // Always.
  , parent_(parent)
  , window_(std::move(window)) {

  if (parent == nullptr) {
    // Then it should be the main screen. Or else it won't be
    // ever drawn.

    // Just a little assumption for the main screen.
    children_.reserve(200);
    return;
  }
}

GraphicComponent::~GraphicComponent() = default;

void GraphicComponent::Draw() {
  if (draw_what == kNothing) {
    return;
  }

  // Counting absolute x/y.
  if (parent_ != nullptr) {
    abs_x_ = x_ + parent_->GetAbsX();
    abs_y_ = y_ + parent_->GetAbsY();
  }

  // @TODO Drawing itself only if absolute x/y don't exceed
  // @TODO certain numbers.
  if (draw_what != kOnlyChildren) {
    if (base_sprite != nullptr) {
      window_->draw(*base_sprite);
    }
  }

  if (draw_what != kOnlyThis) {
    // BFS-ing:
    for (auto& next_child : children_) {
      main_queue_.push(next_child);
    }
  }
}

std::vector<std::shared_ptr<GraphicComponent>>
GraphicComponent::GetChildren() const {
  return children_;
}

void GraphicComponent::AddChild(const std::shared_ptr<GraphicComponent>& child) {
  children_.push_back(child);
}
