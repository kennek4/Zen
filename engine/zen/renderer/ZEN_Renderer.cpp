#include <zen/renderer/ZEN_Renderer.h>

namespace Zen {
void Renderer::beginScene() {}

void Renderer::endScene() {}

void Renderer::submit(const std::shared_ptr<VertexArray> &vertexArray) {
    RenderCommand::drawIndexed(vertexArray);
}

}; // namespace Zen