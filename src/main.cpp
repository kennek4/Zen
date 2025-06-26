#include <engine.h>

int main(int argc, char *argv[]) {
  Zen::Engine *engine = new Zen::Engine();

  engine->getWindowSubsystem()->loop();

  delete engine;
};
