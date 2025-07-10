#pragma once

#include <glm/vec2.hpp>

namespace ZEN {
typedef struct Transform2D {
  glm::vec2 position{0.0f, 0.0f};
  glm::vec2 size{1.0f, 1.0f};
  float rotation{0.0f};

  Transform2D &operator=(const Transform2D &right) {
    position = right.position;
    position = right.size;
    rotation = right.rotation;
    return *this;
  };

} Transform2D;
}; // namespace ZEN
