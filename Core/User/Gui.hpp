#pragma once
#include <memory>
#include "Player.hpp"
#include "Map.hpp"

class Gui {
public:
  Gui(std::weak_ptr<Player> player, std::shared_ptr<Map> map,
      std::shared_ptr<sf::RenderWindow> window);
  ~Gui();

  void HandleMouseClick(sf::Vector2i mouse_position);
  void Draw();

private:
  // To overcome cycle.
  std::weak_ptr<Player> player_;
  std::shared_ptr<Map> map_;
  std::shared_ptr<sf::RenderWindow> window_;
};
