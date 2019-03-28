#pragma once

#include "Entity/Entity.hpp"
#include <vector>
#include "Entity/Turf.hpp"

class Map {
public:
  
private:
  std::vector<std::shared_ptr<Turf>> tiles_;
};
