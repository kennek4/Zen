#include "ZEN_Engine.h"
namespace Zen {
void Engine::loop() {
  bool done = false;
  if (m_window->getWindow() != NULL) {
    while (!done) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
          done = true;
        }
      }
      // Do game logic, present a frame, etc.
    }
  };
};
}; // namespace Zen
