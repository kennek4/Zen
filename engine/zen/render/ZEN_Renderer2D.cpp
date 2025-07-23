#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <glad/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>
#include <zen/render/ZEN_Renderer2D.h>

ZEN_Renderer2D::ZEN_Renderer2D() {
  m_projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
};

ZEN_Renderer2D::~ZEN_Renderer2D() {};

void ZEN_Renderer2D::setShader(std::shared_ptr<ZEN_GLShader> shader) {
  m_shader = shader;
};

std::shared_ptr<ZEN_GLShader> ZEN_Renderer2D::getShader() { return m_shader; };

void ZEN_Renderer2D::renderGameObject(
    std::shared_ptr<ZEN_GameObject2D> gameObject) {
  m_shader->use();
  glm::mat4 model = glm::mat4(1.0f);

  model = glm::translate(model, glm::vec3(gameObject->position, 0.0f));

  // Applies rotation to the model via its center point
  model = glm::translate(model, glm::vec3(0.5f * gameObject->size.x,
                                          0.5f * gameObject->size.y, 0.0f));
  model = glm::rotate(model, glm::radians(gameObject->rotation),
                      glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, glm::vec3(-0.5f * gameObject->size.x,
                                          -0.5f * gameObject->size.y, 0.0f));

  model = glm::scale(model, glm::vec3(gameObject->size, 1.0f));

  m_shader->setMatrix4("model", model, true);
  m_shader->setVector3f("spriteColor", gameObject->sprite->colour, true);

  glActiveTexture(GL_TEXTURE0);
  gameObject->sprite->texture->bind();

  glBindVertexArray(m_quadVAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);
};

void ZEN_Renderer2D::render(SDL_Window *mainWindow) {
  SDL_GL_SwapWindow(mainWindow);
};
