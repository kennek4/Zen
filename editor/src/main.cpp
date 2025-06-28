#include "zen.h"

int main(int argc, char *argv[]) {
  Zen::WindowSettings windowSettings{};
  windowSettings.title = "Zen Editor";
  windowSettings.width = 1280;
  windowSettings.height = 720;
  windowSettings.flags = SDL_WINDOW_BORDERLESS;

  Zen::Engine *engine = new Zen::Engine(&windowSettings);
  engine->loop();

  delete engine;
};
