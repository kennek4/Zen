#include <iostream>
#include <zen/textures/ZEN_TextureFactory2D.h>

#define STB_IMAGE_IMPLEMENTATION
#include <include/stb_image/stb_image.h>

std::shared_ptr<ZEN_Texture2D> ZEN_TextureFactory2D::createTexture(
    std::string const &path, std::string const &textureName, bool hasAlpha) {

  unsigned int internalFormat;
  unsigned int imageFormat;

  if (hasAlpha) { // Swaps the default formats to include alpha channels
    internalFormat = GL_RGBA;
    imageFormat = GL_RGBA;
  };

  // Loading the image at the given filePath
  int width, height, nrChannels;
  unsigned char *dataPtr =
      stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

  if (stbi_failure_reason())
    std::cout << stbi_failure_reason() << std::endl;

  std::cout << "Width: " << width << std::endl;
  std::cout << "Height: " << height << std::endl;

  std::shared_ptr<ZEN_Texture2D> texture = std::make_shared<ZEN_Texture2D>(
      width, height, internalFormat, imageFormat, dataPtr);

  stbi_image_free(dataPtr);
  return texture;
};

std::shared_ptr<ZEN_Texture2D>
ZEN_TextureFactory2D::createTexture(std::string const &path,
                                    std::string const &textureName) {
  // Loading the image at the given filePath
  int width, height, nrChannels;
  unsigned char *dataPtr =
      stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

  std::shared_ptr<ZEN_Texture2D> texture =
      std::make_shared<ZEN_Texture2D>(width, height, dataPtr);

  stbi_image_free(dataPtr);
  return texture;
};
