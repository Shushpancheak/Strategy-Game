#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

/**
 * \brief An abstract entity that holds some components (graphic, health, etc...)
 */
class Entity {
public:
  virtual ~Entity() = default;
  Entity(const float& x, const float& y);
   
protected:
  // Relative to the map.
  float x_, y_;
  std::vector<std::shared_ptr<Component>> components_;
};
