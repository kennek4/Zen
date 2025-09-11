#pragma once

#include <zen/zen_pch.h>
#include <zen/renderer/ZEN_GraphicsContext.h>


namespace Zen {
  class OpenGLContext : public GraphicsContext {
    public:
      OpenGLContext(SDL_Window *window);
      ~OpenGLContext() override;

      void init() override;  
      void swapBuffers() override;

      void shutdown() override;


    private:
      SDL_Window *m_window = nullptr;
      SDL_GLContext m_glContext = nullptr;
  };
}; // namespace Zen