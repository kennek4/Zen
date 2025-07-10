#include "zen.h"
#include <memory>

int main(int argc, char *argv[]) {
  ZEN_Window_MetaData winMetaData{};
  winMetaData.title = "Zen Editor";
  winMetaData.width = 1280;
  winMetaData.height = 720;
  winMetaData.flags = SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL;

  ZEN_Engine *engine = new ZEN_Engine(&winMetaData);
  engine->startGame();

  delete engine;
};
