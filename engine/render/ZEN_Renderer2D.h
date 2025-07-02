#pragma once

#include <SDL3/SDL_video.h>

class ZEN_Renderer2D {
public:
  ZEN_Renderer2D();
  ~ZEN_Renderer2D();

  void render(SDL_Window *mainWindow);

private:
};
