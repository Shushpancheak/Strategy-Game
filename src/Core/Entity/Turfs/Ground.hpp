#pragma once
#include "Entity/Turf.hpp"
#include "Game.hpp"
#include "Sprites.hpp"
#include "ResourceManager.hpp"

class Ground : public Turf {
 public:
  Ground(const float& x, const float& y, const std::shared_ptr<sf::RenderWindow>& window,
         const std::shared_ptr<GraphicComponent>& parent)
    : Turf(x, y, std::make_shared<GraphicComponent>(window, parent, ResourceManager::GetInstance()->GetTexture("ground"),
                                                    constants::kTextureVariants.at("ground"))) {}
};
