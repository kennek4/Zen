#pragma once

#include <glm/vec3.hpp>
#include <memory>
#include <zen/textures/ZEN_Texture2D.h>

namespace ZEN {
typedef struct Sprite {
  std::shared_ptr<ZEN_Texture2D> texture;
  glm::vec3 colour = glm::vec3(1.0f);
} Sprite;
}; // namespace ZEN
