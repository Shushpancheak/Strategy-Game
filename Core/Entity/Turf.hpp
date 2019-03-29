#pragma once
#include "Entity.hpp"
#include "GraphicComponent.hpp"

/**
 * \brief Mostly static objects, that serve as a background.
 */
class Turf : public Entity {
public:
  Turf(const float& x, const float& y, const std::shared_ptr<GraphicComponent>& img);
  virtual ~Turf() = default;

  std::shared_ptr<GraphicComponent> GetGraphicComponent();
};