#pragma once

#include <zen/zen_pch.h>

namespace Zen {
  class Shader {
    public:
      Shader(const char *vertexPath, const char *fragmentPath);
      ~Shader();

      void bind() const;
      void unBind() const;
    
    private:
      uint32_t m_rendererID;
  };
} // namespace Zen