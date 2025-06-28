#pragma once

#include <SDL3/SDL_video.h>
#include <sys/types.h>

typedef struct {
  const char *title;
  int height;
  int width;
  SDL_WindowFlags flags;
} ZEN_Window_MetaData;

typedef enum {
  ZEN_RENDERER_OPENGL,
  ZEN_RENDERER_VULKAN, // NOT IN USE
} ZEN_Renderer_API;

typedef struct {
  const char *API_NAME;
  u_int MAJOR_VERSION;
  u_int MINOR_VERSION;
  u_int PATCH_VERSION;
} ZEN_Graphics_MetaData;
