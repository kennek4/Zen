#pragma once

#include "zen/core/ZEN_Window.h"
#include <SDL3/SDL_video.h>

namespace Zen {
class LinuxWindow : public Window {
  public:
    LinuxWindow(const WindowProperties &properties);
    virtual ~LinuxWindow();

    void onUpdate() override;
    uint32_t getWidth() override;
    uint32_t getHeight() override;

    void setVSync(bool enabled) override;
    bool isVSyncEnabled() const override;
    void toggleFullscreen() override;

    void setEventCallback(const EventCallbackFunction &callback) override;

  private:
    virtual void init(const WindowProperties &properties);
    virtual void shutdown();

  private:
    SDL_Window *m_window;
    SDL_GLContext m_glContext;
    EventCallbackFunction m_eventCallbackFunction;
    WindowProperties m_windowProperties;
};
}; // namespace Zen
