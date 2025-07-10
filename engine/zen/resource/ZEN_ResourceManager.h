#pragma once

#include <cstdint>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <zen/render/ZEN_GLShader.h>
#include <zen/textures/ZEN_Texture2D.h>

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
      auto const it = m_nameToTexture.find(key);
      if (it != m_nameToTexture.end()) {
        id = it->second;
        return m_textures[id];
      };
    };

    if constexpr (std::is_same_v<T, ZEN_GLShader>) {
      auto const it = m_nameToShader.find(key);
      if (it != m_nameToShader.end()) {
        id = it->second;
        return m_shaders[id];
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

  // Shaders
  std::shared_ptr<ZEN_GLShader> loadShader(std::string const &vertexPath,
                                           std::string const &fragmentPath);

private:
  ZEN_ResourceManager() {};
  ~ZEN_ResourceManager();
  [[nodiscard]] std::string generateKey(std::stringstream const &stream) const;

  // Texture Storage
  std::vector<std::shared_ptr<ZEN_Texture2D>> m_textures{};
  std::unordered_map<std::string, uint16_t> m_nameToTexture{};

  // Shader Storage
  std::vector<std::shared_ptr<ZEN_GLShader>> m_shaders{};
  std::unordered_map<std::string, uint16_t> m_nameToShader{};
};
