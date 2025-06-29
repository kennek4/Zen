#pragma once

#include <renderer/2d/ZEN_2D_ResourceManager.h>
#include <renderer/ZEN_Renderer.h>

class ZEN_2D : ZEN_Renderer {
public:
  ZEN_2D() { this->resourceManager = new ZEN_2D_ResourceManager(); };

  ~ZEN_2D() {
    delete this->resourceManager;
    this->resourceManager = nullptr;
  };

  void init();
  void stop();

private:
  ZEN_2D_ResourceManager *resourceManager{nullptr};
};
