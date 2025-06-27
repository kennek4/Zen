#ifndef ZEN_ENGINE
#define ZEN_ENGINE

#include "window_types.h"
#include <render.h>
#include <window.h>

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

  void startLoop();
  void endLoop();

private:
  WindowSystem *m_window;
  RenderSystem *m_render;
};
} // namespace Zen

#endif // !ZEN_ENGINE
