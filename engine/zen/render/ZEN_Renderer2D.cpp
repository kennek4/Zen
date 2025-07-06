#include <GLES3/gl3.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <zen/render/ZEN_Renderer2D.h>

ZEN_Renderer2D::ZEN_Renderer2D() {};

ZEN_Renderer2D::~ZEN_Renderer2D() {};

void ZEN_Renderer2D::render(SDL_Window *mainWindow) {
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(mainWindow);
};
