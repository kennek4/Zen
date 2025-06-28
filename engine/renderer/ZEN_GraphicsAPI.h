#pragma once

#include "base/ZEN_Types.h"

class ZEN_GraphicsAPI {
public:
  virtual const ZEN_Graphics_MetaData *getMetaData() = 0;
};
