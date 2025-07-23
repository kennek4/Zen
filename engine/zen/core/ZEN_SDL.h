#pragma once

#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_video.h>

namespace Zen {
typedef struct {
  SDL_Cursor *cursor;
  SDL_Window *window;
  SDL_GLContext glContext;
} SDLData;
}; // namespace Zen
