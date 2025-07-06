#pragma once

#include <base/2d/textures/ZEN_Texture2D.h>
#include <memory>
#include <string>

class ZEN_TextureFactory2D {
public:
  std::shared_ptr<ZEN_Texture2D> createTexture(std::string const &path,
                                               std::string const &textureName,
                                               bool hasAlpha);

  std::shared_ptr<ZEN_Texture2D> createTexture(std::string const &path,
                                               std::string const &textureName);

  ZEN_TextureFactory2D() {};
  ~ZEN_TextureFactory2D() {};

private:
}; // namespace ZEN_TextureFactory2D
