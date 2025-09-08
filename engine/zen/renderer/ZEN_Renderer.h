#pragma once

#include <zen/zen_pch.h>

#include <zen/renderer/ZEN_RendererAPI.h>
namespace Zen {
  class Renderer {
    public:
      //void init();
      //void shutdown();
    
      inline static RendererAPI getAPI() {return s_rendererAPI;}

    private:
      static RendererAPI s_rendererAPI;
  };

}; // namespace Zen