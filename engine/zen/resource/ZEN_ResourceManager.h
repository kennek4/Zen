#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <set>
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

  void initResources();

  // Textures
  bool createTexture(std::string const &path, std::string const &textureName);
  std::shared_ptr<ZEN_Texture2D> loadTexture(std::string const &textureName);

  // Shaders
  bool createShader(std::string const &vertexPath,
                    std::string const &fragmentPath, std::string &shaderName);
  std::shared_ptr<ZEN_GLShader> loadShader(std::string const &shaderName);

private:
  ZEN_ResourceManager() {};
  ~ZEN_ResourceManager();
  [[nodiscard]] std::string generateKey(std::stringstream const &stream) const;

  // Texture Storage
  std::unordered_map<std::string, std::shared_ptr<ZEN_Texture2D>>
      m_nameToTexture{};
  std::set<std::string> m_texturePaths{};

  // Shader Storage
  std::vector<std::shared_ptr<ZEN_GLShader>> m_shaders{};
  std::unordered_map<std::string, uint16_t> m_nameToShader{};
};
