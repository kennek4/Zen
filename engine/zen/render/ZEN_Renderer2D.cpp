#include "zen/2d/ZEN_Transform2D.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <cstdio>
#include <glad/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <zen/render/ZEN_Renderer2D.h>

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id,
                                GLenum severity, GLsizei length,
                                const GLchar *message, const void *userParam) {
  fprintf(stderr,
          "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
          (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity,
          message);
};

ZEN_Renderer2D::ZEN_Renderer2D() {
  m_projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
};

ZEN_Renderer2D::~ZEN_Renderer2D() {};

void ZEN_Renderer2D::setShader(std::shared_ptr<ZEN_GLShader> shader) {
  m_shader = shader;
};

std::shared_ptr<ZEN_GLShader> ZEN_Renderer2D::getShader() { return m_shader; };

void ZEN_Renderer2D::initOpenGL() {
  std::cout << "Initializing OpenGL" << std::endl;
  glEnable(GL_BLEND | GL_DEPTH_TEST | GL_DEBUG_OUTPUT);
  glDebugMessageCallback(MessageCallback, 0);

  // Configure VAO/VBO
  GLuint VBO;
  float vertices[] = {
      // pos      // tex
      0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,

      0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f};

  glGenVertexArrays(1, &m_quadVAO);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(m_quadVAO);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
};

void ZEN_Renderer2D::renderGameObject(
    std::shared_ptr<ZEN_GameObject2D> gameObject) {
  m_shader->use();
  glm::mat4 model = glm::mat4(1.0f);

  ZEN::Transform2D const &transform = gameObject->getTransform();
  ZEN::Sprite const &sprite = gameObject->getSprite();

  model = glm::translate(model, glm::vec3(transform.position, 0.0f));

  model = glm::translate(
      model, glm::vec3(0.5f * transform.size.x, 0.5f * transform.size.y, 0.0f));
  model = glm::rotate(model, glm::radians(transform.rotation),
                      glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, glm::vec3(-0.5f * transform.size.x,
                                          -0.5f * transform.size.y, 0.0f));

  model = glm::scale(model, glm::vec3(transform.size, 1.0f));

  m_shader->setMatrix4("model", model, true);
  m_shader->setVector3f("spriteColor", sprite.colour, true);

  glActiveTexture(GL_TEXTURE0);
  //
  // std::cout << "Texture ID: " << sprite.texture->getId() << std::endl;
  gameObject->getSprite().texture->bind();

  glBindVertexArray(m_quadVAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);
};

void ZEN_Renderer2D::render(SDL_Window *mainWindow) {
  SDL_GL_SwapWindow(mainWindow);
};
