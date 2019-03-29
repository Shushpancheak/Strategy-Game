#include "Turf.hpp"

Turf::Turf(const float& x, const float& y,
  const GraphicComponent& img)
  : Entity(x, y) {
  components_.push_back(img);
}
