#include <zen/renderer/ZEN_VertexArray.h>
#include <zen/platform/OpenGL/ZEN_OpenGLVertexArray.h>

namespace Zen {

  VertexArray *VertexArray::Create() {
    switch (Renderer::getAPI()) {
      case RendererAPI::None: 
        ZEN_LOG_ERROR("Renderer API is not supported"); 
        return nullptr;
      
      case RendererAPI::OpenGL: 
        ZEN_LOG_INFO("Vertex buffer: Using OpenGL renderer API");
        return new OpenGLVertexArray();
    }

    ZEN_LOG_ERROR("Unknown renderer API");
  };

}; // namespace Zen