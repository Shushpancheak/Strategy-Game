#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>

/**
 * \brief A singleton resource manager which loads textures, sounds, other stuff...
 */
 class ResourceManager {
 private:
  // A trick to make make_shared work.
  struct PrivateSingletonStructForMakeShared {
    PrivateSingletonStructForMakeShared() = default;
  };

 public:
  static std::shared_ptr<ResourceManager> GetInstance();
  const sf::Texture& GetTexture(const std::string& texture_name) const;

  ResourceManager(const ResourceManager&) = delete;
  ResourceManager& operator=(const ResourceManager&) = delete;
  ResourceManager(ResourceManager&&) = delete;
  ResourceManager& operator=(ResourceManager&&) = delete;

  ~ResourceManager();
  explicit ResourceManager(PrivateSingletonStructForMakeShared pr);

  void Unload();

 private:
  const std::unordered_map<std::string, sf::Texture> textures_;
  static std::unordered_map<std::string, sf::Texture> LoadTextures();
  static std::shared_ptr<ResourceManager> instance_;
 };