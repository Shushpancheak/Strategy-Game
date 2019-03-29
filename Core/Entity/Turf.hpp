#pragma once
#include "Entity.hpp"
#include "GraphicComponent.hpp"

/**
 * \brief Mostly static objects, that serve as background.
 */
class Turf : public Entity {
public:
  Turf(const float& x, const float& y, const std::shared_ptr<GraphicComponent>& graphic_component);
  ~Turf() = default;
};