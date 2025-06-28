#pragma once

#include "ZEN_Types.h"
#include <GL/gl.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <iostream>

namespace Zen {

class WindowSystem {
public:
  WindowSystem(WindowSettings *windowSettings) {
    m_winSettings = windowSettings;
    m_mainWindow =
        SDL_CreateWindow(m_winSettings->title, m_winSettings->width,
                         m_winSettings->height, m_winSettings->flags);
    m_glContext = SDL_GL_CreateContext(m_mainWindow);
    std::cout << "WindowSubsystem initialized!\n";
  };

  ~WindowSystem() {
    SDL_GL_DestroyContext(m_glContext);
    SDL_DestroyWindow(m_mainWindow);
    std::cout << "WindowSubsystem destroyed!\n";
  };

  SDL_Window *getWindow();

private:
  WindowSettings *m_winSettings{nullptr};
  SDL_Window *m_mainWindow{nullptr};
  SDL_GLContext m_glContext{nullptr};
};

inline SDL_Window *WindowSystem::getWindow() { return this->m_mainWindow; };

}; // namespace Zen
