#include <SFML/Graphics.hpp>

namespace constants {
  const std::vector<std::string> kTexturesPaths = {
    "Sprites/tileset/ground.png",
    "Sprites/tileset/tankr.png",
    "Sprites/tileset/tankb.png"
  };

  // How much variants a texture has (texture's name is its full name without .png)
  const std::unordered_map<std::string, size_t> kTextureVariants = {
    {"ground", 7},
    {"tankr", 1},
    {"tankb", 1}
  };
} // namespace constants