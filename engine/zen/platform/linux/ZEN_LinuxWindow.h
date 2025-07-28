#pragma once

#include "zen/core/ZEN_Window.h"
#include <SDL3/SDL_video.h>
#include <zen/core/ZEN_Core.h>

namespace Zen {

// TEMP
struct WindowData {
    SDL_Window *window;
    SDL_GLContext glContext;
};

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
    void emitErrorMessage(const char *message) override;

    // TEMP
    WindowData &getWindowData();
    WindowProperties &getProperties();

  private:
    virtual void init(const WindowProperties &properties);
    virtual void shutdown();

  private:
    EventCallbackFunction m_eventCallbackFunction;

    // TEMP
    WindowData m_windowData;

    WindowProperties m_windowProperties;
};
}; // namespace Zen
