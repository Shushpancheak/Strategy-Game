#include "gtest/gtest.h"
#include "ResourceManager.hpp"
#include "SFML/Graphics.hpp"
#include "Visitor.hpp"
#include "Map.hpp"


/*
 * Resource Manager tests.
 */
TEST(Unit, Resource_Manager_1) {
  const sf::Texture tex = ResourceManager::GetInstance()->GetTexture("ground");
  sf::Texture tex_1;
  tex_1.loadFromFile("Sprites/tileset/ground.png")
  EXPECT_EQ(tex, tex_1);
}

/*
 * Tests for visitor
 */
TEST(Unit, Visitor_1) {
  Visitor v;
  Entity e = Entity(0, 0);
  EXPECT_EQ("Entity | x == 0, y == 0", v.ForEntity(&e));
}
TEST(Unit, Visitor_2) {
  Visitor v;
  Map map = Map(nullptr, nullptr, 10, 10);
  EXPECT_EQ("Map | parent == nullptr, window == nullptr, overall 100 objects",
            v.ForMap(&map));
}
TEST(Unit, Visitor_3) {
  Visitor v;
  Turf turf = Turf(0, 0, nullptr);
  EXPECT_EQ("Turf | x == 0, y == 0, texture == nullptr", v.ForTurf(&turf));
}