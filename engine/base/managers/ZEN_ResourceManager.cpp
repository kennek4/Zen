#include <base/managers/ZEN_ResourceManager.h>
#include <map>
// #include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <include/stb_image/stb_image.h>

std::map<const char *, ZEN_Texture2D> ZEN_ResourceManager::Textures = {};

void ZEN_ResourceManager::clear() {
  // Deleting Textures from ZEN_ResourceManager storage
  for (auto iter : Textures) {
    glDeleteTextures(1, &iter.second.getId());
  };
};

ZEN_Texture2D ZEN_ResourceManager::getTexture(const char *name) {
  return Textures[name];
};

ZEN_Texture2D ZEN_ResourceManager::loadTexture(const char *filePath,
                                               bool hasAlpha,
                                               const char *name) {
  ZEN_Texture2D texture;

  if (hasAlpha) { // Swaps the default formats to include alpha channels
    texture.setInternalFormat(GL_RGBA);
    texture.setImageFormat(GL_RGBA);
  };

  // Loading the image at the given filePath
  int width, height, nrChannels;
  unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, 0);

  texture.create(width, height, data);
  stbi_image_free(data); // Frees up the image data

  // Store texture into storage
  Textures[name] = texture;

  // std::cout << "[Texture] " << name << " texture has been created
  // successfully!"
  //           << std::endl;

  return texture;
};
