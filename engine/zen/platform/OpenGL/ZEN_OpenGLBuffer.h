#pragma once

#include <zen/renderer/ZEN_Buffer.h>

namespace Zen {
  class OpenGLVertexBuffer : public VertexBuffer {
    public:
      OpenGLVertexBuffer(float *vertices, uint32_t size);
      virtual ~OpenGLVertexBuffer();

      virtual void bind() const override;
      virtual void unbind() const override;

    private:
      uint32_t m_rendererID;
  };

  class OpenGLIndexBuffer : public IndexBuffer {
    public:
      OpenGLIndexBuffer(uint32_t *indices, uint32_t count);
      virtual ~OpenGLIndexBuffer();

      virtual void bind() const override;
      virtual void unbind() const override;
      virtual uint32_t getCount() const override; 

    private:
      uint32_t m_rendererID;
      uint32_t m_count;
  };

}; // namespace Zen