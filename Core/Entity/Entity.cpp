#include "Entity.hpp"

Entity::~Entity() = default;

Entity::Entity(const float& x, const float& y) 
  : x_(x)
  , y_(y) 
  , components_(0) {}
