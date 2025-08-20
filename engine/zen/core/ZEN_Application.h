#pragma once

#include <zen/zen_pch.h>
#include <zen/core/ZEN_Core.h>
#include <zen/core/ZEN_Window.h>

namespace Zen {
class Application : public EventListener {
  public:
    Application();
    virtual ~Application();

    void run();
    bool onEvent(const SDL_Event &event);

  private:
    std::unique_ptr<Window> m_window;
    bool m_isRunning = true;

    EventsDispatcher m_eventDispatcher;
};

// Defined Client Side
Application *CreateApplication();
}; // namespace Zen
