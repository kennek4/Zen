#include <SDL3/SDL_video.h>
#include <cstdio>
#include <glad/gl.h>
#include <iostream>
#include <zen/window/ZEN_WindowManager.h>

ZEN_WindowManager::ZEN_WindowManager(ZEN_Window_MetaData *winMetaData,
                                     ZEN_Renderer_API rendererApi) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
    // TODO:: Add error to logging
    std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
  };

  m_winMetaData = winMetaData;
  m_mainWindow = SDL_CreateWindow(m_winMetaData->title, m_winMetaData->width,
                                  m_winMetaData->height, m_winMetaData->flags);
  if (m_mainWindow == NULL) {
    // TODO:: Add error to logging
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
  };

  m_glContext = SDL_GL_CreateContext(m_mainWindow);
  if (m_glContext == NULL) {
    // TODO:: Add error to logging
    std::cout << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
  };

  // Initialize GLAD
  int version = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
  // TODO: Add log event to show GLAD version here
  // printf("GL %d.%d\n", GLAD_VERSION_MAJOR(version),
  //        GLAD_VERSION_MINOR(version));
};
