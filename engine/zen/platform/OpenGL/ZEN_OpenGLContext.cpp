#include <zen/platform/OpenGL/ZEN_OpenGLContext.h>

namespace Zen {
  OpenGLContext::OpenGLContext(SDL_Window *window) : m_window(window) {
  };

  OpenGLContext::~OpenGLContext() {
  };

  void OpenGLContext::init() {
    m_glContext = SDL_GL_CreateContext(m_window);
  };

  void OpenGLContext::shutdown() {
    SDL_GL_DestroyContext(m_glContext);
  };
}; // namespace Zen