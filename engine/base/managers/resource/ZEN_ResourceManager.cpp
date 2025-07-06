#include <base/2d/textures/ZEN_TextureFactory2D.h>
#include <base/managers/resource/ZEN_ResourceManager.h>
#include <iostream>
#include <memory>

ZEN_ResourceManager::~ZEN_ResourceManager() {
  for (auto iter : m_textures) {
    glDeleteTextures(1, &iter->getId());
  };
};

std::shared_ptr<ZEN_Texture2D> ZEN_ResourceManager::loadAlphaTexture(
    std::string const &path, std::string const &textureName, bool hasAlpha) {
  std::stringstream stream;
  stream << path;
  std::string const &key = generateKey(stream);

  auto resourcePtr = getFromVector<ZEN_Texture2D>(key);

  if (resourcePtr != nullptr) {
    return resourcePtr;
  };

  std::unique_ptr<ZEN_TextureFactory2D> textureFactory2D =
      std::make_unique<ZEN_TextureFactory2D>();

  std::cout << "Texture " << textureName
            << " not loaded! Loading texture now..." << std::endl;

  // If not in m_textures, create texture and add to m_textures
  resourcePtr =
      textureFactory2D.get()->createTexture(path, textureName, hasAlpha);
  std::cout << "After create texture!" << std::endl;
  resourcePtr = m_textures.emplace_back(resourcePtr);
  std::cout << "After emplace_back!" << std::endl;
  nameToTexture.insert(std::make_pair(key, m_textures.size() - 1));
  std::cout << "After insert" << std::endl;

  std::cout << "Texture now loaded!" << std::endl;

  return resourcePtr;
};

std::shared_ptr<ZEN_Texture2D>
ZEN_ResourceManager::loadTexture(std::string const &path,
                                 std::string const &textureName) {
  std::stringstream stream;
  stream << path;
  std::string const &key = generateKey(stream);

  auto resourcePtr = getFromVector<ZEN_Texture2D>(key);

  if (resourcePtr != nullptr) {
    return resourcePtr;
  };

  std::unique_ptr<ZEN_TextureFactory2D> textureFactory2D =
      std::unique_ptr<ZEN_TextureFactory2D>();

  // If not in m_textures, create texture and add to m_textures
  resourcePtr = textureFactory2D->createTexture(path, textureName);
  resourcePtr = m_textures.emplace_back(resourcePtr);
  nameToTexture.insert(std::make_pair(key, m_textures.size() - 1));

  return resourcePtr;
};

std::string
ZEN_ResourceManager::generateKey(std::stringstream const &stream) const {
  return stream.str();
};
