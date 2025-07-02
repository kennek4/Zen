#pragma once

#include <iostream>
#include <renderer/apis/ZEN_OpenGL.h>

class ZEN_2D {
public:
  ZEN_2D(ZEN_Renderer_API graphicsApi) {
    switch (graphicsApi) {
    case ZEN_RENDERER_OPENGL:
      std::cout << "Initializing OpenGL..." << std::endl;
      this->graphicsApi = new ZEN_OpenGL();
      break;
    default: // Used for later API usage
      break;
    };

    std::cout << "Zen 2D Renderer Initialized!" << std::endl;
  };

  ~ZEN_2D() {
    delete this->graphicsApi;
    this->graphicsApi = nullptr;
  };

  void init();
  void loop();

private:
  ZEN_GraphicsAPI *graphicsApi{nullptr};
};
