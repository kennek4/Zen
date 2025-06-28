#pragma once

#include <renderer/ZEN_GraphicsAPI.h>

class ZEN_OpenGL : ZEN_GraphicsAPI {
public:
  ZEN_OpenGL() {

  };

  ~ZEN_OpenGL() {

  };

  ZEN_Graphics_MetaData *getMetaData();

private:
};
