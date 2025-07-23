#pragma once

#include <SDL3/SDL_video.h>
#include <cstdint>
#include <memory>
#include <zen/opengl/ZEN_Batch.h>
#include <zen/opengl/ZEN_OpenGL.h>
#include <zen/opengl/ZEN_Shader.h>

namespace Zen {
class Renderer {
public:
  Renderer();
  ~Renderer();

  void render(uint32_t indexCount);
  void swapScreenBuffer(SDL_Window *window);

  const std::weak_ptr<Zen::Shader> &getShader();
  void setShader(const std::weak_ptr<Zen::Shader> &shader);

private:
  void init();
  uint32_t m_vertexCapacity = 6000;
  GLuint m_VBO, m_VAO, m_IBO;

  Zen::GL_Batch m_batch{};

  std::weak_ptr<Zen::Shader> m_shader;
  glm::mat4 m_projection;
};
}; // namespace Zen
