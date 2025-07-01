#pragma once

#include <base/ZEN_Types.h>
#include <base/ZEN_WindowManager.h>
#include <renderer/2d/ZEN_2D.h>

class ZEN_Engine {
public:
  ZEN_Engine(ZEN_Window_MetaData *winMetaData, ZEN_Renderer_API api) {
    this->m_window = new ZEN_WindowManager(winMetaData);
    this->m_render = new ZEN_2D(ZEN_RENDERER_OPENGL);
  };

  ~ZEN_Engine() {
    delete this->m_render;
    delete this->m_window;
  };

  void loop();

private:
  ZEN_WindowManager *m_window;
  ZEN_2D *m_render;
};
