#include <SDL3/SDL_video.h>
#include <base/managers/ZEN_WindowManager.h>
#include <iostream>

inline ZEN_WindowManager::ZEN_WindowManager(ZEN_Window_MetaData *winMetaData,
                                            ZEN_Renderer_API rendererApi) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
    std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
  };

  m_winMetaData = winMetaData;
  m_mainWindow = SDL_CreateWindow(m_winMetaData->title, m_winMetaData->width,
                                  m_winMetaData->height, m_winMetaData->flags);
  if (m_mainWindow == NULL) {
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
  };

  m_glContext = SDL_GL_CreateContext(m_mainWindow);
  if (m_glContext == NULL) {
    std::cout << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
  };

  m_renderer2d = new ZEN_2D();
};

void ZEN_WindowManager::render() {
  m_renderer2d->render();
  SDL_GL_SwapWindow(m_mainWindow);
};
