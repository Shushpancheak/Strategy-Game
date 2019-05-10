#pragma once
#include <memory>
#include "Player.hpp"
#include "Map.hpp"

class Gui {
public:
  Gui(std::shared_ptr<Map> map,
      std::shared_ptr<sf::RenderWindow> window);
  ~Gui();

  void HandleMouseClick(sf::Vector2i mouse_position, std::shared_ptr<Player> player);
  void Draw();

private:
  std::shared_ptr<Map> map_;
  std::shared_ptr<sf::RenderWindow> window_;
};
