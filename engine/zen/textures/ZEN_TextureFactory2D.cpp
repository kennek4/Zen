#include <iostream>
#include <zen/textures/ZEN_TextureFactory2D.h>

#define STB_IMAGE_IMPLEMENTATION
#include <include/stb_image/stb_image.h>

std::shared_ptr<ZEN_Texture2D>
ZEN_TextureFactory2D::createTexture(std::string const &path,
                                    std::string const &textureName) {
  // Loading the image at the given filePath
  int width, height, nrChannels;
  unsigned char *dataPtr =
      stbi_load(path.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);

  if (stbi_failure_reason())
    // TODO: Custom logging error here
    std::cout << stbi_failure_reason() << std::endl;

  std::shared_ptr<ZEN_Texture2D> texture =
      std::make_shared<ZEN_Texture2D>(width, height, GL_RGBA, GL_RGBA, dataPtr);

  stbi_image_free(dataPtr);
  return texture;
};
