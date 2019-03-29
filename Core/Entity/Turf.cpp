#include "Turf.hpp"

Turf::Turf(const float& x, const float& y,
           const std::shared_ptr<GraphicComponent>& img)
  : Entity(x, y) {
  components_.push_back(img);
  std::dynamic_pointer_cast<GraphicComponent>(components_[0])->SetXy(x, y);
}

std::shared_ptr<GraphicComponent> Turf::GetGraphicComponent() {
  return std::dynamic_pointer_cast<GraphicComponent>(components_[0]);
}
