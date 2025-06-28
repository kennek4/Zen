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

class ZEN_WindowManager {
public:
  ZEN_WindowManager(ZEN_Window_MetaData *winMetaData) {
    m_winMetaData = winMetaData;
    m_mainWindow =
        SDL_CreateWindow(m_winMetaData->title, m_winMetaData->width,
                         m_winMetaData->height, m_winMetaData->flags);
    m_glContext = SDL_GL_CreateContext(m_mainWindow);
    std::cout << "WindowSubsystem initialized!\n";
  };

  ~ZEN_WindowManager() {
    SDL_GL_DestroyContext(m_glContext);
    SDL_DestroyWindow(m_mainWindow);
    std::cout << "WindowSubsystem destroyed!\n";
  };

  SDL_Window *getWindow();

private:
  ZEN_Window_MetaData *m_winMetaData{nullptr};
  SDL_Window *m_mainWindow{nullptr};
  SDL_GLContext m_glContext{nullptr};
};

inline SDL_Window *ZEN_WindowManager::getWindow() {
  return this->m_mainWindow;
};
