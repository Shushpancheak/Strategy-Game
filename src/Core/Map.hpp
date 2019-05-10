#pragma once

#include "Entity/Entity.hpp"
#include <vector>
#include "Entity/Turf.hpp"
#include <memory>
#include "Constants.hpp"

class Map {
public:
  Map(
    const std::shared_ptr<GraphicComponent>& parent = nullptr,
    const std::shared_ptr<sf::RenderWindow>& window = nullptr,
    const size_t tiles_width = constants::kDefaultMapSize,
    const size_t tiles_height = constants::kDefaultMapSize
  );
  ~Map();

  std::shared_ptr<GraphicComponent> GetMapGraphicComponent() const;

private:
  std::vector<std::vector<std::shared_ptr<Turf>>> tiles_;
  std::shared_ptr<GraphicComponent> map_graphic_component_;
};
