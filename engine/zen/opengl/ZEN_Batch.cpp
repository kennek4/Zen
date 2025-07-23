#pragma once

#include <zen/opengl/ZEN_Batch.h>

namespace Zen {
// void GL_Batch::addQuad(Zen::GL_Vertex *target, float x, float y,
//                        glm::vec4 color, float textureId) {
//   float size = 1.0f;
//
//   if ((m_vertices.size() + 1) > maxVertexCount) {
//     m_isFlushable = true;
//     return;
//   };
//
//   target->position = {x, y, 0.0f};
//   target->color = color;
//   target->texturePosition = {0.0f, 0.0f};
//   target->textureId = textureId;
//   target++;
//
//   target->position = {x + size, y, 0.0f};
//   target->color = color;
//   target->texturePosition = {1.0f, 0.0f};
//   target->textureId = textureId;
//   target++;
//
//   target->position = {x + size, y + size, 0.0f};
//   target->color = color;
//   target->texturePosition = {1.0f, 1.0f};
//   target->textureId = textureId;
//   target++;
//
//   target->position = {x, y + size, 0.0f};
//   target->color = color;
//   target->texturePosition = {0.0f, 1.0f};
//   target->textureId = textureId;
//   target++;
//
//   m_indexCount += 6;
// };
//
// const std::array<Zen::GL_Vertex, GL_Batch::maxVertexCount> &
// GL_Batch::getVertices() {
//   return m_vertices;
// };
}; // namespace Zen
