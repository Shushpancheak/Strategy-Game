#include <SFML/Graphics.hpp>

namespace constants {
  const std::vector<std::string> kTexturesPaths = {
    "Sprites/tileset/ground.png",
  };

  // How much variants a texture has (texture's name is its full name without .png)
  const std::unordered_map<std::string, size_t> kTextureVariants = {
    {"ground", 7}
  };
} // namespace constants