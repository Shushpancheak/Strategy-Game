#pragma once
#include "Entity/Entity.hpp"

class Visitor {
public:
  std::string ForEntity(Entity* entity);
  std::string ForTurf(Turf* turf);
  std::string ForMob(Mob* mob);
  std::string ForComponent(Component* component);
  std::string ForGraphicComponent(GraphicComponent* graphic_component);
  std::string ForMap(Map* map);
};