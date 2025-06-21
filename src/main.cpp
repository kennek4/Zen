#include "engine/engine.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_stdinc.h>
int main(int argc, char *argv[]) {
  Zen::Engine *engine = new Zen::Engine();

  engine->getWindowSubsystem()->loop();

  delete engine;
};
