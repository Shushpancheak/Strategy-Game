#include "Entity.hpp"

Entity::~Entity() = default;

Entity::Entity(const float& x, const float& y) 
  : x_(x)
  , y_(y) 
  , components_(0) {}

std::vector<std::shared_ptr<Component>>& Entity::GetComponents() {
  return components_;
}

float Entity::GetX() {
  return x_;
}

float Entity::GetY() {
  return y_;
}
