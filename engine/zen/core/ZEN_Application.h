#pragma once

#include <SDL3/SDL_events.h>
#include <memory>
#include <zen/core/ZEN_Core.h>
#include <zen/core/ZEN_Window.h>

namespace Zen {
class Application {
  public:
    Application();
    virtual ~Application();

    void run();
    void onEvent(SDL_Event &event);

  private:
    std::unique_ptr<Window> m_window;
    bool m_isRunning = true;
};

// Defined Client Side
Application *CreateApplication();
}; // namespace Zen
