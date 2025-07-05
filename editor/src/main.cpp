#include "zen.h"

int main(int argc, char *argv[]) {
  ZEN_Window_MetaData winMetaData{};
  winMetaData.title = "Zen Editor";
  winMetaData.width = 1280;
  winMetaData.height = 720;
  winMetaData.flags = SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL;

  ZEN_Engine *engine = new ZEN_Engine(&winMetaData, ZEN_RENDERER_OPENGL);
  ZEN_ResourceManager::loadTexture("../../data/snoopy1000x1000.jpg", false,
                                   "Snoopy");

  engine->startGame();

  delete engine;
};
