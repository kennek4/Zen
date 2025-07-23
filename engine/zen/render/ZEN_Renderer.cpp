#include <GL/gl.h>
#include <SDL3/SDL_video.h>
#include <array>
#include <cstddef>
#include <cstdint>

namespace Zen {
//
// #ifdef __ZEN_DEBUG__
//
// #include <sstream>
//
// void GLAPIENTRY glDebugCallback(GLenum source, GLenum type, GLuint id,
//                                 GLenum severity,
//                                 [[maybe_unused]] GLsizei length,
//                                 const GLchar *message,
//                                 [[maybe_unused]] const void *userParam) {
//   // Ignore certain verbose info messages (particularly ones on Nvidia).
//   if (id == 131169 || id == 131185 || // NV: Buffer will use video memory
//       id == 131218 ||
//       id == 131204 || // Texture cannot be used for texture mapping
//       id == 131222 ||
//       id == 131154 || // NV: pixel transfer is synchronized with 3D rendering
//       id == 0         // gl{Push, Pop}DebugGroup
//   ) {
//     return;
//   }
//
//   std::stringstream debugMessageStream;
//   debugMessageStream << message << '\n';
//
//   switch (source) {
//   case GL_DEBUG_SOURCE_API:
//     debugMessageStream << "Source: API";
//     break;
//   case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
//     debugMessageStream << "Source: Window Manager";
//     break;
//   case GL_DEBUG_SOURCE_SHADER_COMPILER:
//     debugMessageStream << "Source: Shader Compiler";
//     break;
//   case GL_DEBUG_SOURCE_THIRD_PARTY:
//     debugMessageStream << "Source: Third Party";
//     break;
//   case GL_DEBUG_SOURCE_APPLICATION:
//     debugMessageStream << "Source: Application";
//     break;
//   case GL_DEBUG_SOURCE_OTHER:
//     debugMessageStream << "Source: Other";
//     break;
//   }
//
//   debugMessageStream << '\n';
//
//   switch (type) {
//   case GL_DEBUG_TYPE_ERROR:
//     debugMessageStream << "Type: Error";
//     break;
//   case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
//     debugMessageStream << "Type: Deprecated Behaviour";
//     break;
//   case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
//     debugMessageStream << "Type: Undefined Behaviour";
//     break;
//   case GL_DEBUG_TYPE_PORTABILITY:
//     debugMessageStream << "Type: Portability";
//     break;
//   case GL_DEBUG_TYPE_PERFORMANCE:
//     debugMessageStream << "Type: Performance";
//     break;
//   case GL_DEBUG_TYPE_MARKER:
//     debugMessageStream << "Type: Marker";
//     break;
//   case GL_DEBUG_TYPE_PUSH_GROUP:
//     debugMessageStream << "Type: Push Group";
//     break;
//   case GL_DEBUG_TYPE_POP_GROUP:
//     debugMessageStream << "Type: Pop Group";
//     break;
//   case GL_DEBUG_TYPE_OTHER:
//     debugMessageStream << "Type: Other";
//     break;
//   }
//
//   debugMessageStream << '\n';
//
//   switch (severity) {
//   case GL_DEBUG_SEVERITY_HIGH:
//     debugMessageStream << "Severity: high";
//     break;
//   case GL_DEBUG_SEVERITY_MEDIUM:
//     debugMessageStream << "Severity: medium";
//     break;
//   case GL_DEBUG_SEVERITY_LOW:
//     debugMessageStream << "Severity: low";
//     break;
//   case GL_DEBUG_SEVERITY_NOTIFICATION:
//     debugMessageStream << "Severity: notification";
//     break;
//   }
//
//   // TODO: Zen_Logger Output
//   // [ERROR] - { debugMessageStream }
// }
// #endif // __ZEN_DEBUG__
//
// Renderer::Renderer() { init(); };
//
// Renderer::~Renderer() {
//
// };
//
// void Renderer::render(uint32_t indexCount) {
//
//   const std::array<Zen::GL_Vertex, Zen::GL_Batch::maxVertexCount> &vertices =
//       m_batch.getVertices();
//
//   glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//   glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), &vertices);
//
//   glClear(GL_COLOR_BUFFER_BIT);
//
//   glUseProgram(m_shader.lock()->getId());
//
//   glBindVertexArray(m_VAO);
//   glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
// };
//
// void Renderer::swapScreenBuffer(SDL_Window *window) {
//   SDL_GL_SwapWindow(window);
// };
//
// const std::weak_ptr<Zen::Shader> &Renderer::getShader() { return m_shader; };
//
// void Renderer::setShader(const std::weak_ptr<Zen::Shader> &shader) {
//   m_shader = shader;
//   shader.lock()->use();
// };
//
// void Renderer::init() {
// #ifdef __ZEN_DEBUG__
//   glDebugMessageCallback(glDebugCallback, nullptr);
//   glEnable(GL_DEBUG_OUTPUT);
//   glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
// #endif // __ZEN_DEBUG__
//
//   glEnable(GL_BLEND);
//   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//   glEnable(GL_DEPTH_TEST);
//   glEnable(GL_CULL_FACE);
//
//   glUseProgram(m_shader.lock()->getId());
//
//   // Configure VAO/VBO
//   glGenVertexArrays(1, &m_VAO);
//   glBindVertexArray(m_VAO);
//
//   glGenBuffers(1, &m_VBO);
//   glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//   glBufferData(GL_ARRAY_BUFFER, sizeof(Zen::GL_Vertex) *
//   m_batch.maxVertexCount,
//                nullptr, GL_DYNAMIC_DRAW);
//
//   glEnableVertexArrayAttrib(m_VBO, 0);
//   glVertexAttribPointer(
//       0, 2, GL_FLOAT, GL_FALSE, sizeof(Zen::GL_Vertex),
//       (const void *)(const void *)offsetof(Zen::GL_Vertex, position));
//
//   glEnableVertexArrayAttrib(m_VBO, 1);
//   glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GL_Vertex),
//                         (const void *)offsetof(Zen::GL_Vertex, color));
//
//   glEnableVertexArrayAttrib(m_VBO, 2);
//   glVertexAttribPointer(
//       2, 2, GL_FLOAT, GL_FALSE, sizeof(Zen::GL_Vertex),
//       (const void *)offsetof(Zen::GL_Vertex, texturePosition));
//
//   glEnableVertexArrayAttrib(m_VBO, 3);
//   glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Zen::GL_Vertex),
//                         (const void *)offsetof(Zen::GL_Vertex, textureId));
//
//   uint32_t indices[m_batch.maxIndexCount];
//   uint32_t offset = 0;
//   for (size_t i = 0; i < m_batch.maxIndexCount; i += 6) {
//     indices[i + 0] = 0 + offset;
//     indices[i + 1] = 1 + offset;
//     indices[i + 2] = 2 + offset;
//
//     indices[i + 3] = 2 + offset;
//     indices[i + 4] = 3 + offset;
//     indices[i + 5] = 0 + offset;
//     offset += 4;
//   };
//
//   glGenBuffers(1, &m_IBO);
//   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
//   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
//                GL_STATIC_DRAW);
// };
}; // namespace Zen
