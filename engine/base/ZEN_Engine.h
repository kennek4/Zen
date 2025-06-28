#pragma once

#include "ZEN_Types.h"
#include "ZEN_Window.h"
#include "render/ZEN_Render.h"

namespace Zen {
class Engine {
public:
  Engine(WindowSettings *windowSettings) {
    this->m_window = new WindowSystem(windowSettings);
    this->m_render = new RenderSystem();
  };

  ~Engine() {
    delete this->m_render;
    delete this->m_window;
  };

  void loop();

private:
  WindowSystem *m_window;
  RenderSystem *m_render;
};
} // namespace Zen
