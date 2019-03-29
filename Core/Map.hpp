#pragma once

#include "Entity/Entity.hpp"
#include <vector>
#include "Entity/Turf.hpp"
#include <memory>

class Map {
public:
  Map(
    const sf::Texture& texture = sf::Texture(),
    const std::shared_ptr<GraphicComponent>& parent = nullptr,
    const std::shared_ptr<sf::RenderWindow>& window = nullptr,
    const size_t variants = 1,
    const size_t tiles_width = 30,
    const size_t tiles_height = 30
  );
  ~Map();

private:
  std::vector<std::vector<std::shared_ptr<Turf>>> tiles_;
};
