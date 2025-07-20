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
  ZENLOG::info("Before Loading...");

  std::shared_ptr<ZEN_Texture2D> snoopy1 =
      ZEN_ResourceManager::getInstance().loadAlphaTexture(
          "../../data/snoopy1000x1000.jpg", "Snoopy", true);

  std::shared_ptr<ZEN_Texture2D> snoopy2 =
      ZEN_ResourceManager::getInstance().loadAlphaTexture(
          "../../data/snoopy1000x1000.jpg", "Snoopy", true);

  std::cout << "After Loading..." << std::endl;

  std::cout << "Snoopy 1 glID: " << snoopy1->getId() << std::endl;
  std::cout << "Snoopy 2 glID: " << snoopy2->getId() << std::endl;

  std::cout << "After cout" << std::endl;

  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);
  
  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");
  
  //spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  spdlog::debug("This message should be displayed..");    
  
  // change log pattern
  //spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
  
  // Compile time log levels
  // Note that this does not change the current log level, it will only
  // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
  //SPDLOG_TRACE("Some trace message with param {}", 42);
  //SPDLOG_DEBUG("Some debug message");
  
  
  
  ZENLOG::info("hi");
  ZENLOG::warn("Snoopy 1 glID: {}", snoopy1->getId());
  ZENLOG::trace("CAN YOU SEE THIS");
  ZENLOG::debug("CAN YOU SEE THIS");

  delete engine;
};
