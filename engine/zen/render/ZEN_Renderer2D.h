#pragma once

#include <SDL3/SDL_video.h>
#include <memory>
#include <zen/2d/ZEN_GameObject2D.h>
#include <zen/render/ZEN_GLShader.h>
#include <zen/textures/ZEN_Texture2D.h>

class ZEN_Renderer2D {
public:
  ZEN_Renderer2D();
  ~ZEN_Renderer2D();

  void render(SDL_Window *mainWindow);
  void initOpenGL();
  void renderGameObject(std::shared_ptr<ZEN_GameObject2D> gameObject);

  void setShader(std::shared_ptr<ZEN_GLShader> shader);
  std::shared_ptr<ZEN_GLShader> getShader();

private:
  std::shared_ptr<ZEN_GLShader> m_shader;
  glm::mat4 m_projection;
  GLuint m_quadVAO;
};
