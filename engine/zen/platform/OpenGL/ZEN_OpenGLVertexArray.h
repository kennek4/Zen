#pragma once

#include <zen/zen_pch.h>

#include <zen/renderer/ZEN_VertexArray.h>

namespace Zen {
  class OpenGLVertexArray : public VertexArray {
    public:
      OpenGLVertexArray();
      virtual ~OpenGLVertexArray() {}

      virtual void bind() const override;
      virtual void unbind() const override;

      virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) override;
      virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) override;

    private:
      uint32_t m_rendererID;

      std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
      std::shared_ptr<IndexBuffer> m_indexBuffer;
  };
}; // namespace Zen