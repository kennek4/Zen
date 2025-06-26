#include "window.h"
namespace Zen {

void Zen::WindowSubsystem::emitEvent(u_int systemId) {};

void Zen::WindowSubsystem::handleEvent(u_int systemId) {};

void Zen::WindowSubsystem::loop() {
  bool quit{false};
  SDL_Event e;
  SDL_zero(e);

  while (!quit) {
    while (SDL_PollEvent(&e) == true) {
      // If event is quit type
      if (e.type == SDL_EVENT_QUIT) {
        // End the main loop
        quit = true;
      }
    }

    SDL_FillSurfaceRect(
        this->m_mainSurface, nullptr,
        SDL_MapSurfaceRGB(this->m_mainSurface, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(this->m_mainWindow);
  };
};

}; // namespace Zen
