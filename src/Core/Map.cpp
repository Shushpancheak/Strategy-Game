#include "Map.hpp"
#include "Constants.hpp"
#include "Entity/Turfs/Ground.hpp"

Map::Map(
  const std::shared_ptr<GraphicComponent>& parent,
  const std::shared_ptr<sf::RenderWindow>& window,
  const size_t tiles_width,
  const size_t tiles_height) {
  
  tiles_.resize(tiles_height);

  for (size_t i = 0; i < tiles_height; ++i) {
    tiles_[i].resize(tiles_width);
  }

  map_graphic_component_ = std::make_shared<GraphicComponent>(window, parent);

  for (size_t i = 0; i < tiles_height; ++i) {
    for (size_t j = 0; j < tiles_width; ++j) {
      tiles_[i][j] = std::make_shared<Ground>(
        constants::kSS * static_cast<float>(j),
        constants::kSS * static_cast<float>(i),
        window, map_graphic_component_
      );
    }
  }
}

Map::~Map() = default;
std::shared_ptr<GraphicComponent> Map::GetMapGraphicComponent() const {
  return map_graphic_component_;
}
