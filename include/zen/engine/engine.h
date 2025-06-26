#ifndef ZEN_ENGINE
#define ZEN_ENGINE

#include "window_types.h"
#include <render.h>
#include <window.h>

namespace Zen {
class Engine {
public:
  Engine(WindowSettings *windowSettings) {
    this->m_window = new WindowSubsystem(windowSettings, 1);
    this->m_render = new RenderSubsystem(2);
  };

  ~Engine() {
    delete this->m_render;
    delete this->m_window;
  };

  void startLoop();
  void endLoop();

private:
  WindowSubsystem *m_window;
  RenderSubsystem *m_render;
};
} // namespace Zen

#endif // !ZEN_ENGINE
