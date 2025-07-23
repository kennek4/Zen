#pragma once

#include "zen.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <glm/fwd.hpp>
#include <zen/opengl/ZEN_OpenGL.h>

namespace Zen {
class GL_Batch {
public:
  static const size_t maxQuadCount = 2000;
  static const size_t maxVertexCount = maxQuadCount * 4;
  static const size_t maxIndexCount = maxQuadCount * 6;

  GL_Batch();
  ~GL_Batch();

  void addQuad(Zen::GL_Vertex *target, float x, float y, glm::vec4 color,
               float textureId);
  const std::array<Zen::GL_Vertex, maxVertexCount> &getVertices();

private:
  bool m_isFlushable{false};
  GLuint m_currentTexture;
  std::array<Zen::GL_Vertex, maxVertexCount> m_vertices{};
  uint32_t m_indexCount;
};
}; // namespace Zen
