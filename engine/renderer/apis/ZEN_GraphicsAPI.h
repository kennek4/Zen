#pragma once

#include <base/ZEN_Types.h>

class ZEN_GraphicsAPI {
public:
  ZEN_GraphicsAPI() = default;
  virtual ~ZEN_GraphicsAPI() {};
  virtual ZEN_Graphics_MetaData *getMetaData() = 0;
  virtual bool init() = 0;
};
