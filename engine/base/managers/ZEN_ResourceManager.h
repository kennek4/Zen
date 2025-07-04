#pragma once

#include <base/2d/ZEN_Texture2D.h>
#include <map>

class ZEN_ResourceManager {
public:
  static void clear();

  static std::map<const char *, ZEN_Texture2D> Textures;
  static ZEN_Texture2D getTexture(const char *name);
  static ZEN_Texture2D loadTexture(const char *filePath, bool hasAlpha,
                                   const char *name);

private:
  ZEN_ResourceManager() {};
};
