#include <iostream>
#include <memory>
#include <utility>
#include <zen/render/ZEN_GLShaderFactory.h>
#include <zen/resource/ZEN_ResourceManager.h>
#include <zen/textures/ZEN_TextureFactory2D.h>

ZEN_ResourceManager::~ZEN_ResourceManager() {
  for (auto iter : m_textures) {
    glDeleteTextures(1, &iter->getId());
  };

  for (auto iter : m_shaders) {
    glDeleteShader(iter->getId());
  };
};

bool ZEN_ResourceManager::createTexture(std::string const &path,
                                        std::string const &textureName) {
  bool success = true;

  if (loadTexture(textureName) != nullptr) {
    // TODO: Custom error handling here
    // Texture already exists
    success = false;
  };

  std::unique_ptr<ZEN_TextureFactory2D> textureFactory =
      std::unique_ptr<ZEN_TextureFactory2D>();

  // If not in m_textures, create texture and add to m_textures
  auto resourcePtr = textureFactory->createTexture(path, textureName);
  resourcePtr = m_textures.emplace_back(resourcePtr);
  m_nameToTexture.insert(std::make_pair(textureName, m_textures.size() - 1));

  return success;
};

std::shared_ptr<ZEN_Texture2D>
ZEN_ResourceManager::loadTexture(std::string const &textureName) {
  auto texturePtr = getFromVector<ZEN_Texture2D>(textureName);
  return texturePtr;
};

std::shared_ptr<ZEN_GLShader>
ZEN_ResourceManager::loadShader(std::string const &vertexPath,
                                std::string const &fragmentPath,
                                std::string const &shaderName) {

  std::stringstream stream;
  stream << vertexPath << fragmentPath;
  std::string const &key = generateKey(stream);

  auto resourcePtr = getFromVector<ZEN_GLShader>(key);

  if (resourcePtr != nullptr) {
    return resourcePtr;
  };

  std::unique_ptr<ZEN_GLShaderFactory> shaderFactory =
      std::unique_ptr<ZEN_GLShaderFactory>();

  resourcePtr = shaderFactory->createShader(vertexPath, fragmentPath);
  resourcePtr = m_shaders.emplace_back(resourcePtr);
  m_nameToShader.insert(std::make_pair(key, m_shaders.size() - 1));

  return resourcePtr;
};

std::string
ZEN_ResourceManager::generateKey(std::stringstream const &stream) const {
  return stream.str();
};
