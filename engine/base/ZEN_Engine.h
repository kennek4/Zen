#pragma once

#include <base/ZEN_Types.h>
#include <base/managers/ZEN_GameManager.h>
#include <base/managers/ZEN_ResourceManager.h>
#include <base/managers/ZEN_WindowManager.h>
#include <iostream>

class ZEN_Engine {
public:
  ZEN_Engine(ZEN_Window_MetaData *winMetaData, ZEN_Renderer_API rendererApi) {
    this->m_gameManager = new ZEN_GameManager();
    this->m_resourceManager = new ZEN_ResourceManager();
    this->m_windowManager = new ZEN_WindowManager(winMetaData, rendererApi);
    std::cout << "Zen Engine Initialized!" << std::endl;
  };

  ~ZEN_Engine() {
    delete this->m_windowManager;
    delete this->m_resourceManager;
    delete this->m_gameManager;
  };

  void startGame();
  void stopGame();

private:
  ZEN_GameManager *m_gameManager;
  ZEN_ResourceManager *m_resourceManager;
  ZEN_WindowManager *m_windowManager;
};
