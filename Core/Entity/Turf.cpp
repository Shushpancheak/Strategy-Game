#include "Turf.hpp"

Turf::Turf(const float& x, const float& y, const std::shared_ptr<GraphicComponent>& graphic_component)
  : Entity(x, y) {
  components_.push_back(graphic_component);
}
