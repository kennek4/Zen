#pragma once

#include <memory>
#include <string>
#include <zen/textures/ZEN_Texture2D.h>

class ZEN_TextureFactory2D {
public:
  std::shared_ptr<ZEN_Texture2D> createTexture(std::string const &path,
                                               std::string const &textureName);

  ZEN_TextureFactory2D() {};
  ~ZEN_TextureFactory2D() {};
}; // namespace ZEN_TextureFactory2D
