#include <SDL3/SDL_video.h>
#include <cstdio>
#include <glad/gl.h>
#include <iostream>
#include <zen/window/ZEN_WindowManager.h>

ZEN_WindowManager::ZEN_WindowManager(ZEN_Window_MetaData *winMetaData) {
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

  // Set OpenGL Attributes
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

  // Initialize GLAD
  int version = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
  // TODO: Add log event to show GLAD version here
  // printf("GL %d.%d\n", GLAD_VERSION_MAJOR(version),
  //        GLAD_VERSION_MINOR(version));
};
