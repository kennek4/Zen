#pragma once

#include <glm/ext/matrix_clip_space.hpp>
#include <memory>
#include <zen/ZEN_Types.h>
#include <zen/game/ZEN_GameManager.h>
#include <zen/render/ZEN_Renderer2D.h>
#include <zen/resource/ZEN_ResourceManager.h>
#include <zen/window/ZEN_WindowManager.h>

class ZEN_Engine {
public:
  ZEN_Engine(ZEN_Window_MetaData *winMetaData);
  ~ZEN_Engine();

  void init();
  void startGame();
  void stopGame();

private:
  std::unique_ptr<ZEN_WindowManager> m_windowManager;
  std::unique_ptr<ZEN_GameManager> m_gameManger;
  std::unique_ptr<ZEN_Renderer2D> m_renderer;
};
