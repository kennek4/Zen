#ifndef ZEN_WINDOW_SUBSYSTEM
#define ZEN_WINDOW_SUBSYSTEM

#include <GL/gl.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <format>
#include <iostream>
#include <subsystem.h>

namespace Zen {
class WindowSubsystem : public Subsystem {
public:
  WindowSubsystem(u_int systemId) : Subsystem(systemId) {
    std::cout << std::format("[SID: {}] Hello!\n", getSystemId());
    if (!init()) {
      // SDL could not initialize properly
    };
    std::cout << "WindowSubsystem initialized!\n";
  };

  ~WindowSubsystem() {
    std::cout << std::format("[SID: {}] Bye Bye!\n", getSystemId());
    if (!shutdown()) {
      // SDL could not shutdown properly
    };
    std::cout << "WindowSubsystem destroyed!\n";
  };

  void loop() {
    bool quit{false};
    SDL_Event e;
    SDL_zero(e);

    while (!quit) {
      while (SDL_PollEvent(&e) == true) {
        // If event is quit type
        if (e.type == SDL_EVENT_QUIT) {
          // End the main loop
          quit = true;
        }
      }

      SDL_FillSurfaceRect(
          this->m_mainSurface, nullptr,
          SDL_MapSurfaceRGB(this->m_mainSurface, 0xFF, 0xFF, 0xFF));

      SDL_UpdateWindowSurface(this->m_mainWindow);
    };
  };

  void emitEvent(u_int event);
  void handleEvent(u_int event);

private:
  int m_windowHeight, m_windowWidth;
  SDL_Window *m_mainWindow{nullptr};
  SDL_Surface *m_mainSurface{nullptr};
  SDL_GLContext m_glContext;

  GLuint m_glProgramId;

  // TODO: Replace bool with custom error type in the future
  bool init() {
    bool success{true};
    if (!SDL_Init(SDL_INIT_VIDEO)) {
      SDL_Log("SDL did not initialize properly. SDL Error: %s/n",
              SDL_GetError());
      success = false;
    };

    m_mainWindow = SDL_CreateWindow("Zen", 1920, 1080, 0);
    if (m_mainWindow == nullptr) {
      SDL_Log("SDL could not create a window. SDL Error: %s/n", SDL_GetError());
      success = false;
    } else {
      m_mainSurface = SDL_GetWindowSurface(m_mainWindow);
    };

    return success;
  };

  // TODO: Replace bool with custom error type in the future
  inline bool shutdown() {
    SDL_DestroySurface(m_mainSurface);
    SDL_DestroyWindow(m_mainWindow);
    m_mainWindow = nullptr;
    m_mainSurface = nullptr;

    SDL_Quit();
    return true;
  };
};
}; // namespace Zen

#endif // !ZEN_WINDOW_SUBSYSTEM
