#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

/**
 * \brief An abstract entity that holds some components (graphic, health, etc...)
 */
class Entity {
public:
  virtual ~Entity();
  Entity(const float& x = 0, const float& y = 0);

  std::vector<std::shared_ptr<Component>>& GetComponents();
  float GetX();
  float GetY();
   
protected:
  // Relative to the map.
  float x_, y_;
  std::vector<std::shared_ptr<Component>> components_;
};
