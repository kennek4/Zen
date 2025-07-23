#include "zen/resource/ZEN_ResourceManager.h"
#include <memory>
#include <zen/opengl/ZEN_Shader.h>
#include <zen/textures/ZEN_Image.h>
#include <zen/textures/ZEN_Texture.h>
#include <zen/textures/ZEN_TextureFactory2D.h>

#define STB_IMAGE_IMPLEMENTATION
#include <include/stb_image/stb_image.h>

namespace Zen {
ResourceManager::ResourceManager() {

};

ResourceManager::~ResourceManager() {
  for (auto iter : m_textures) {
    glDeleteTextures(1, &iter->id);
  };

  for (auto iter : m_shaders) {
    glDeleteShader(iter->getId());
  };
};

bool ResourceManager::createShader(std::string const &vertexPath,
                                   std::string const &fragmentPath,
                                   std::string &shaderName) {
  bool success = true;

  if (loadShader(shaderName) != nullptr) {
    // TODO: Custom error handling here
    // Texture already exists
    success = false;
  };

  std::unique_ptr<ZEN_GLShaderFactory> shaderFactory =
      std::unique_ptr<ZEN_GLShaderFactory>();

  auto resourcePtr = shaderFactory->createShader(vertexPath, fragmentPath);
  resourcePtr = m_shaders.emplace_back(resourcePtr);
  m_nameToShader.insert(std::make_pair(shaderName, m_shaders.size() - 1));

  return success;
};

std::weak_ptr<Zen::Shader> ResourceManager::loadShader(const char *shaderName) {
  auto shaderPtr = getFromVector<Zen::Shader>(shaderName);
  return shaderPtr;
};

bool ResourceManager::loadImage(const char *filePath) {
  bool imageLoaded = true;

  if (!m_pathToImage.contains(filePath)) {
    // Loading the image at the given filePath
    int width, height, nrChannels;
    unsigned char *dataPtr =
        stbi_load(filePath, &width, &height, &nrChannels, STBI_rgb_alpha);

    const char *error = stbi_failure_reason();
    if (error) {
      // TODO: Custom error handling
      // [ERROR] - Image data from, {filePath}, failed to load.
      // {error}
      stbi_image_free(dataPtr);
      return !imageLoaded;
    };

    std::shared_ptr<Zen::Image> image =
        std::make_shared<Zen::Image>(dataPtr, width, height, filePath);
    m_images.emplace_back(image);
    m_pathToImage.insert(std::make_pair(filePath, m_pathToImage.size() - 1));

    stbi_image_free(dataPtr);
  };

  return imageLoaded;
};

bool ResourceManager::createTexture(const char *imageFilePath,
                                    const char *textureName) {

  bool textureWasCreated = true;
  if (!m_pathToImage.contains(imageFilePath)) {
    // TODO: Custom error handling
    // [WARNING] - An image with the given file path was not found. Try loading
    // the image first.
    return !textureWasCreated;
  };

  if (m_nameToTexture.contains(textureName)) {
    // TODO: Custom error handling
    // [ERROR] - The given texture name is already in use. Please use a
    // different name.
    return !textureWasCreated;
  };

  std::weak_ptr<Zen::Image> image = m_images[m_pathToImage.at(imageFilePath)];
  if (image.expired()) {
    // TODO: Custom error handling
    // [ERROR] - The given image is no longer available.
    return !textureWasCreated;
  };

  std::shared_ptr<Zen::Texture> texture =
      std::make_shared<Zen::Texture>(textureName, image);
  m_textures.emplace_back(texture);
  m_nameToTexture.insert(
      std::make_pair(textureName, m_nameToTexture.size() - 1));

  return textureWasCreated;
};

std::weak_ptr<Zen::Texture>
ResourceManager::loadTexture(const char *textureName) {
  if (!m_nameToTexture.contains(textureName)) {
    // TODO: Custom error handling
    // [WARNING] - The texture, {textureName}, does not exist.
  };
  auto texturePtr = getFromVector<Zen::Texture>(textureName);
  return texturePtr;
};
}; // namespace Zen
