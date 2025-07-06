#pragma once

#include <GL/gl.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <zen/ZEN_Types.h>

class ZEN_WindowManager {
public:
  ZEN_WindowManager(ZEN_Window_MetaData *winMetaData,
                    ZEN_Renderer_API rendererApi);

  ~ZEN_WindowManager() {
    SDL_GL_DestroyContext(m_glContext);
    SDL_DestroyWindow(m_mainWindow);
    SDL_Quit();
  };

  inline SDL_Window *getWindow() { return m_mainWindow; };

private:
  ZEN_Window_MetaData *m_winMetaData{nullptr};
  SDL_Window *m_mainWindow{nullptr};
  SDL_GLContext m_glContext{nullptr};
};
