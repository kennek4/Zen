#ifndef ZEN_WINDOW_SUBSYSTEM
#define ZEN_WINDOW_SUBSYSTEM

#include <GL/gl.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <iostream>
#include <subsystem.h>
#include <window_types.h>

namespace Zen {

class WindowSubsystem : public Subsystem {
public:
  WindowSubsystem(WindowSettings *windowSettings, u_int systemId)
      : Subsystem(systemId) {
    m_winSettings = windowSettings;
    m_mainWindow =
        SDL_CreateWindow(m_winSettings->title, m_winSettings->width,
                         m_winSettings->height, m_winSettings->flags);
    m_glContext = SDL_GL_CreateContext(m_mainWindow);
    std::cout << "WindowSubsystem initialized!\n";
  };

  ~WindowSubsystem() {
    SDL_GL_DestroyContext(m_glContext);
    SDL_DestroyWindow(m_mainWindow);
    std::cout << "WindowSubsystem destroyed!\n";
  };

  SDL_Window *getWindow();

  void emitEvent(u_int event);
  void handleEvent(u_int event);

private:
  WindowSettings *m_winSettings{nullptr};
  SDL_Window *m_mainWindow{nullptr};
  SDL_GLContext m_glContext{nullptr};
};

inline SDL_Window *WindowSubsystem::getWindow() { return this->m_mainWindow; };

}; // namespace Zen

#endif // !ZEN_WINDOW_SUBSYSTEM
