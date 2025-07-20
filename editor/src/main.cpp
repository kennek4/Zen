#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "resource/ZEN_ResourceManager.h"
#include "textures/ZEN_Texture2D.h"
#include "zen.h"
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {

  using ZENLOG = ZEN_LoggerManager; //ZENLOG is an alias for ZEN_LogggerManager
  ZENLOG::init();

  ZEN_Window_MetaData winMetaData{};
  winMetaData.title = "Zen Editor";
  winMetaData.width = 1280;
  winMetaData.height = 720;
  winMetaData.flags = SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL;

  ZEN_Engine *engine = new ZEN_Engine(&winMetaData, ZEN_RENDERER_OPENGL);
  ZENLOG::trace("Before Loading...");

  std::shared_ptr<ZEN_Texture2D> snoopy1 =
      ZEN_ResourceManager::getInstance().loadAlphaTexture(
          "../../data/snoopy1000x1000.jpg", "Snoopy", true);

  std::shared_ptr<ZEN_Texture2D> snoopy2 =
      ZEN_ResourceManager::getInstance().loadAlphaTexture(
          "../../data/snoopy1000x1000.jpg", "Snoopy", true);

  ZENLOG::trace("After Loading...");

  ZENLOG::info("Snoopy 1 glID: ",snoopy1->getId());
  ZENLOG::info("Snoopy 2 glID: ",snoopy2->getId());

  ZENLOG::trace("After cout");

  delete engine;
};
