#pragma once

#include <base/2d/textures/ZEN_Texture2D.h>
#include <cstdint>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Meyer's Singleton
class ZEN_ResourceManager {
public:
  // Remove copy and assignment operator
  ZEN_ResourceManager(const ZEN_ResourceManager &) = delete;
  ZEN_ResourceManager &operator=(const ZEN_ResourceManager &) = delete;

  static ZEN_ResourceManager &getInstance() {
    static ZEN_ResourceManager instance;
    return instance;
  };

  template <typename T>
  std::shared_ptr<T> getFromVector(std::string const &key) {
    int32_t id = -1;
    if constexpr (std::is_same_v<T, ZEN_Texture2D>) {
      auto const it = nameToTexture.find(key);
      if (it != nameToTexture.end()) {
        id = it->second;
        return m_textures[id];
      };
    };

    return nullptr;
  };

  // Textures
  std::shared_ptr<ZEN_Texture2D>
  loadAlphaTexture(std::string const &path, std::string const &textureName,
                   bool hasAlpha);

  std::shared_ptr<ZEN_Texture2D> loadTexture(std::string const &path,
                                             std::string const &textureName);

private:
  ZEN_ResourceManager() {};
  ~ZEN_ResourceManager();
  [[nodiscard]] std::string generateKey(std::stringstream const &stream) const;

  // Texture Storage
  std::vector<std::shared_ptr<ZEN_Texture2D>> m_textures{};
  std::unordered_map<std::string, uint16_t> nameToTexture{};
};
