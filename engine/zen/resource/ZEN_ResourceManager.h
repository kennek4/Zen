#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <zen/opengl/ZEN_Shader.h>
#include <zen/textures/ZEN_Image.h>
#include <zen/textures/ZEN_Texture.h>
#include <zen/textures/ZEN_Texture2D.h>

namespace Zen {
class ResourceManager {
public:
  ResourceManager();
  ~ResourceManager();

  template <typename T> std::weak_ptr<T> getFromVector(const char *&key) {
    int32_t id = -1;
    if constexpr (std::is_same_v<T, Zen::Shader>) {
      auto const it = m_nameToShader.find(key);
      if (it != m_nameToShader.end()) {
        id = it->second;
        return m_shaders[id];
      };
    };

    if constexpr (std::is_same_v<T, Zen::Image>) {
      auto const it = m_pathToImage.find(key);
      if (it != m_pathToImage.end()) {
        id = it->second;
        return m_images[id];
      };
    };

    if constexpr (std::is_same_v<T, Zen::Texture>) {
      auto const it = m_nameToTexture.find(key);
      if (it != m_nameToTexture.end()) {
        id = it->second;
        return m_textures[id];
      };
    };

    return nullptr;
  };

  // Shaders
  bool createShader(std::string const &vertexPath,
                    std::string const &fragmentPath, std::string &shaderName);
  std::weak_ptr<Zen::Shader> loadShader(const char *shaderName);

  // Images
  bool loadImage(const char *filePath);

  // Textures
  bool createTexture(const char *filePath, const char *textureName);
  [[nodiscard]] std::weak_ptr<Zen::Texture>
  loadTexture(const char *textureName);

private:
  // Shader Storage
  std::vector<std::shared_ptr<Zen::Shader>> m_shaders{};
  std::unordered_map<std::string, uint16_t> m_nameToShader{};

  // Image Storage
  std::vector<std::shared_ptr<Zen::Image>> m_images{};
  std::unordered_map<const char *, uint16_t> m_pathToImage{};

  // Texture Storage
  std::vector<std::shared_ptr<Zen::Texture>> m_textures{};
  std::unordered_map<const char *, uint16_t> m_nameToTexture{};
};
}; // namespace Zen
