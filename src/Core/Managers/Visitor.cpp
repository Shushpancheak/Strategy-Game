#include "Visitor.hpp"

std::string Visitor::ForEntity(Entity* entity) {
  return "Entity | x == " + std::to_string(entity->GetX()) +
         ", y == " + std::to_string(entity->GetY());
}

std::string Visitor::ForTurf(Turf* turf) {
  return "Turf | x == " + std::to_string(turf->GetX()) +
         ", y == " + std::to_string(turf->GetY());
}

std::string Visitor::ForMob(Mob* mob) {
  return "Mob | x == " + std::to_string(mob->GetX()) +
         ", y == " + std::to_string(mob->GetY());
}

std::string Visitor::ForComponent(Component* component) {
  return "Component | Just a component";
}

std::string Visitor::ForGraphicComponent(GraphicComponent* graphic_component) {
  return "Graphic Component | x == " +
         std::to_string(graphic_component->GetX()) +
         ", y == " + std::to_string(graphic_component->GetY()) +
         ", scale == " + std::to_string(graphic_component->GetScale());
}

std::string Visitor::ForMap(Map* map) {
  return ", overall " + std::to_string(map->GetTilesCount());
}
