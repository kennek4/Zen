#ifndef ZEN_ENGINE
#define ZEN_ENGINE

#include <render.h>
#include <window.h>

namespace Zen {
class Engine {
public:
  Engine() {
    this->m_window = new WindowSubsystem(1);
    this->m_render = new RenderSubsystem(2);
  };

  ~Engine() {
    delete this->m_render;
    delete this->m_window;
  };

  inline WindowSubsystem *getWindowSubsystem() { return this->m_window; };

private:
  WindowSubsystem *m_window;
  RenderSubsystem *m_render;
};
} // namespace Zen

#endif // !ZEN_ENGINE
