#pragma once

#include <zen/zen_pch.h>
#include <zen/renderer/ZEN_RendererAPI.h>
#include <zen/renderer/ZEN_Renderer.h>


namespace Zen {
  class VertexBuffer {
    public:
      virtual ~VertexBuffer() {}

      virtual void bind() const = 0;
      virtual void unbind() const = 0;

      static VertexBuffer *Create(float *vertices, uint32_t size);
  };

  class IndexBuffer {
    public:
      virtual ~IndexBuffer() {}

      virtual void bind() const = 0;
      virtual void unbind() const = 0;
      virtual uint32_t getCount() const = 0;

      static IndexBuffer *Create(uint32_t *indices, uint32_t count);
  };

}; // namespace Zen