#include "Gui.hpp"
#include <utility>

Gui::Gui(std::shared_ptr<Map> map,
         std::shared_ptr<sf::RenderWindow> window) 
  : map_(std::move(map))
  , window_(std::move(window)) {}

Gui::~Gui() = default;

void Gui::HandleMouseClick(sf::Vector2i mouse_position, std::shared_ptr<Player> player) {
  
}

void Gui::Draw() {
  
}
