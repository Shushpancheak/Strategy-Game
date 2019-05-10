#include "GraphicComponent.hpp"
#include <utility>
#include "Constants.hpp"

GraphicComponent::GraphicComponent(std::shared_ptr<sf::RenderWindow> window,          
                            const std::shared_ptr<GraphicComponent>& parent,
                            const sf::Texture& source_texture,
                            const size_t variants,
                            const size_t animated_frames,
                            const DrawVariant draw_what)
  : draw_what(draw_what)
  , variants(variants)
  , animated_frames(animated_frames)
  , x_(0)
  , y_(0)
  , abs_x_(0)
  , abs_y_(0)
  , deg_(0)
  , scale_(1.f)
  , global_scale_(1.f)
  , source_texture_(source_texture)
  , sprite_(source_texture)
  , animated_fps_(5.f)
  , parent_(parent)
  , window_(std::move(window)) {
  if (parent == nullptr) {
    // Then it should be the main screen. Otherwise it won't be
    // ever drawn.

    // Just a little assumption for the main screen.
    children_.reserve(200);
    return;
  } else {
    // Adding child to pattern to maintain double-joint composite tree.
    parent_->AddChild(this);

    // @TODO make variant variable.
    if (variants > 0) {
      // if variants > 0 then given texture isn't 64x64, but smth else...
      const auto variant = rand() % variants;
      sprite_.setTextureRect(
        sf::IntRect(sf::Vector2<int>(0, variant * constants::kSS), constants::kSSV)
      );
    }
  }
}

GraphicComponent::~GraphicComponent() = default;

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

  const auto window_size = window_->getView().getSize();

  const auto scaled_abs_x = abs_x_ * global_scale_;
  const auto scaled_abs_y = abs_y_ * global_scale_;
  const auto scaled_scale = scale_ * global_scale_;

  if (draw_what != kOnlyChildren &&
      scaled_abs_x < window_size.x &&
      scaled_abs_y < window_size.y &&
      scaled_abs_x > -constants::kSS * global_scale_ && 
      scaled_abs_y > -constants::kSS * global_scale_) {
    sprite_.setPosition(scaled_abs_x, scaled_abs_y);
    sprite_.setRotation(deg_);
    sprite_.setScale(scaled_scale, scaled_scale);
    window_->draw(sprite_);
  }
  
  if (draw_what != kOnlyThis) {
    // BFS-ing:
    for (auto& next_child : children_) {
      main_queue_.push(next_child);
    }
  }
}

std::vector<GraphicComponent*>
GraphicComponent::GetChildren() const {
  return children_;
}

void GraphicComponent::AddChild(GraphicComponent* child) {
  children_.push_back(child);
}

void GraphicComponent::SetXy(const float& x, const float& y) {
  x_ = x;
  y_ = y;
}

void GraphicComponent::MoveXy(const float& x, const float& y) {
  x_ += x;
  y_ += y;
}

void GraphicComponent::MoveVec2(const sf::Vector2<float> vec) {
  x_ += vec.x;
  y_ += vec.y;
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

void GraphicComponent::DrawPushed() {
  while (!main_queue_.empty()) {
    auto next = main_queue_.front();
    main_queue_.pop();
    next->Draw();
  }
}

float GraphicComponent::GetGlobalScale() {
  return global_scale_;
}

void GraphicComponent::SetGlobalScale(const float& new_global_scale) {
  global_scale_ = (new_global_scale > 0 ? new_global_scale : 1.f);
}

void GraphicComponent::ChangeGlobalScale(const float& change) {
  SetGlobalScale(global_scale_ + change);
}

void GraphicComponent::SetGlobalScaleRecursively(const float& new_global_scale) {
  // DFSing.
  for (auto& child : children_) {
    child->SetGlobalScaleRecursively(new_global_scale);
  }
  global_scale_ = new_global_scale;
}

void GraphicComponent::ChangeGlobalScaleRecursively(const float& change) {
  // DFSing.
  for (auto& child : children_) {
    child->ChangeGlobalScaleRecursively(change);
  }
  global_scale_ += change;
}

std::queue<GraphicComponent*> GraphicComponent::main_queue_;
