#pragma once

#include <SDL3/SDL_video.h>
#include <glm/fwd.hpp>
#include <glm/mat4x4.hpp>

namespace Zen {
typedef struct {
  glm::vec3 position;
  glm::vec4 color;
  glm::vec2 texturePosition;
  float textureId;
} GL_Vertex;
}; // namespace Zen
