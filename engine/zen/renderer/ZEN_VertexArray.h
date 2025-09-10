#include <zen/zen_pch.h>

namespace Zen {
  class VertexArray {
    public:
      virtual ~VertexArray() {}

      virtual void bind() const = 0;
      virtual void unbind() const = 0;

      static VertexArray *Create();
  };
}; // namespace Zen