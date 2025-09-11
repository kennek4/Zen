#include <zen/renderer/ZEN_GraphicsContext.h>
#include <zen/platform/OpenGL/ZEN_OpenGLContext.h>

namespace Zen {
  std::unique_ptr<GraphicsContext> GraphicsContext::Create(SDL_Window *window) {
    return std::make_unique<OpenGLContext>(window);
  }
}; // namespace Zen