#pragma once

#include <zen/zen_pch.h>

#include <zen/renderer/ZEN_RenderCommand.h>

namespace Zen {
class Renderer {
  public:
    static void beginScene();
    static void endScene();

    static void submit(const std::shared_ptr<VertexArray> &vertexArray);

    static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
};

}; // namespace Zen