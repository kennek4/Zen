#ifndef ZEN_WINDOW_TYPES_H
#define ZEN_WINDOW_TYPES_H

#include <SDL3/SDL_video.h>

namespace Zen {
typedef struct {
  const char *title;
  int height;
  int width;
  SDL_WindowFlags flags;
} WindowSettings;
} // namespace Zen

#endif // !ZEN_WINDOW_TYPES_H
