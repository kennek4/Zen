#pragma once

#include <base/ZEN_Types.h>
#include <base/managers/ZEN_GameManager.h>
#include <base/managers/ZEN_ResourceManager.h>
#include <base/managers/ZEN_WindowManager.h>
#include <iostream>
#include <renderer/ZEN_2D.h>

class ZEN_Engine {
public:
  ZEN_Engine(ZEN_Window_MetaData *winMetaData, ZEN_Renderer_API graphicsApi) {
    this->m_windowManager = new ZEN_WindowManager(winMetaData);
    this->m_render = new ZEN_2D(graphicsApi);
    std::cout << "Zen Engine Initialized!" << std::endl;
  };

  ~ZEN_Engine() {
    delete this->m_render;
    delete this->m_gameManager;
    delete this->m_resourceManager;
    delete this->m_windowManager;
  };

  void loop();

private:
  ZEN_GameManager *m_gameManager;
  ZEN_ResourceManager *m_resourceManager;
  ZEN_WindowManager *m_windowManager;
  ZEN_2D *m_render;
};
