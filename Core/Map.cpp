#include "Map.hpp"

Map::Map(const sf::Texture& texture,
  const std::shared_ptr<GraphicComponent>& parent,
  const std::shared_ptr<sf::RenderWindow>& window,
  const size_t variants,
  const size_t tiles_width,
  const size_t tiles_height) {
  
  tiles_.resize(tiles_height);

  for (size_t i = 0; i < tiles_height; ++i) {
    tiles_[i].resize(tiles_width);
  }

  for (size_t i = 0; i < tiles_height; ++i) {
    for (size_t j = 0; j < tiles_width; ++j) {
      tiles_[i][j] = std::make_shared<GraphicComponent>(window, parent, texture, variants);
    }
  }
}

Map::~Map() = default;
