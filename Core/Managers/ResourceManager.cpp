#include "ResourceManager.hpp"
#include <iostream>
#include "Sprites.hpp"

std::shared_ptr<ResourceManager> ResourceManager::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = std::make_shared<ResourceManager>(PrivateSingletonStructForMakeShared());
  }
  return instance_;
}

const sf::Texture& ResourceManager::GetTexture(const std::string& texture_name) const {
  return textures_.at(texture_name);
}

ResourceManager::~ResourceManager() {
  instance_ = nullptr;
}

ResourceManager::ResourceManager(PrivateSingletonStructForMakeShared pr)
  : textures_(LoadTextures()) {}

void ResourceManager::Unload() {
  instance_ = nullptr;
}

std::unordered_map<std::string, sf::Texture> ResourceManager::LoadTextures() {
  std::unordered_map<std::string, sf::Texture> map;
  /**
   * \brief Extract the name that would go to the map textures_.
   */
  const auto extract_name = [](const std::string& s) {
    size_t start = 0, finish = s.size();
    for (auto i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
      if (s[i] == '.') {
        finish = i - 1;
      }
      if (s[i] == '/') {
        start = i + 1;
        break;
      }
    }

    return s.substr(start, finish - start + 1);
  };

  for (auto& name : constants::kTexturesPaths) {
    std::cout << name << std::endl;

    sf::Texture new_tex;
    new_tex.loadFromFile(name);
    map[extract_name(name)] = new_tex;
  }

  return map;
}

std::shared_ptr<ResourceManager> ResourceManager::instance_(nullptr);
