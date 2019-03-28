#include "GraphicComponent.hpp"
#include <utility>
#include <iostream>

GraphicComponent::GraphicComponent(std::shared_ptr<sf::RenderWindow> window,
                                   const std::shared_ptr<GraphicComponent>& parent,
                                   const DrawVariant draw_what,
                                   std::shared_ptr<sf::Drawable> base_sprite) 
  : draw_what(draw_what)
  , base_sprite(std::move(base_sprite))
  , x_(0)
  , y_(0)
  , abs_x_(0)
  , abs_y_(0)
  , scale_(1.f)
  , deg_(0)
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

GraphicComponent::~GraphicComponent() {
  std::cout << "GraphicComponent D\n";
}

void GraphicComponent::Draw() {
  if (draw_what == kNothing) {
    return;
  }

  // Counting absolute x/y.
  if (parent_ != nullptr) {
    abs_x_ = x_ + parent_->abs_x_;
    abs_y_ = y_ + parent_->abs_y_;
  } else {
    abs_x_ = x_;
    abs_y_ = y_;
  }

  // @TODO Drawing itself only if absolute x/y don't exceed
  // @TODO certain numbers.
  if (draw_what != kOnlyChildren) {
    if (base_sprite != nullptr) {
      // If it is transformable.
      auto base_sprite_t = std::dynamic_pointer_cast<sf::Transformable, sf::Drawable>(base_sprite);
      if (base_sprite_t != nullptr) {
        base_sprite_t->setPosition(abs_x_, abs_y_);
        base_sprite_t->setRotation(deg_);
        base_sprite_t->setScale(scale_, scale_);
      }

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

std::queue<std::shared_ptr<GraphicComponent>> GraphicComponent::main_queue_;

void GraphicComponent::AddChild(const std::shared_ptr<GraphicComponent>& child) {
  children_.push_back(child);
}

void GraphicComponent::AddChild(std::shared_ptr<GraphicComponent>&& child) {
  children_.push_back(std::move(child));
}

void GraphicComponent::SetXy(const float& x, const float& y) {
  x_ = x;
  y_ = y;
}

void GraphicComponent::MoveXy(const float& x, const float& y) {
  x_ += x;
  y_ += y;
}

void GraphicComponent::SetScale(const float& scale) {
  scale_ = scale;
}

void GraphicComponent::SetRotationDegrees(const float& deg) {
  deg_ = deg;
}

float GraphicComponent::GetX() const {
  return x_;
}

float GraphicComponent::GetY() const {
  return y_;
}

float GraphicComponent::GetAbsX() const {
  return parent_->abs_x_ + x_;
}

float GraphicComponent::GetAbsY() const {
  return parent_->abs_y_ + y_;
}

float GraphicComponent::GetScale() const {
  return scale_;
}

float GraphicComponent::GetRotationDegrees() const {
  return deg_;
}

void GraphicComponent::DrawAll() {
  while (!main_queue_.empty()) {
    auto next = main_queue_.front();
    main_queue_.pop();
    next->Draw();
  }
}
