#pragma once

#include <base/ZEN_Types.h>
#include <base/managers/ZEN_GameManager.h>
#include <base/managers/ZEN_ResourceManager.h>
#include <base/managers/ZEN_WindowManager.h>
#include <iostream>
#include <render/ZEN_Renderer2D.h>

class ZEN_Engine {
public:
  ZEN_Engine(ZEN_Window_MetaData *winMetaData, ZEN_Renderer_API rendererApi) {
    m_gameManager = new ZEN_GameManager();
    m_windowManager = new ZEN_WindowManager(winMetaData, rendererApi);
    m_renderer2d = new ZEN_Renderer2D();
    std::cout << "Zen Engine Initialized!" << std::endl;
  };

  ~ZEN_Engine() {
    delete m_windowManager;
    delete m_gameManager;
    delete m_renderer2d;

    m_windowManager = nullptr;
    m_gameManager = nullptr;
    m_renderer2d = nullptr;
  };

  void startGame();
  void stopGame();

private:
  ZEN_GameManager *m_gameManager{nullptr};
  ZEN_WindowManager *m_windowManager{nullptr};
  ZEN_Renderer2D *m_renderer2d{nullptr};
};
