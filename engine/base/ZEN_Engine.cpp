#include <SDL3/SDL_events.h>
#include <base/ZEN_Engine.h>

void ZEN_Engine::startGame() {
  SDL_Window *mainWindow = m_windowManager->getWindow();
  if (mainWindow == NULL) {
    std::cout << "Window could not be retrieved" << std::endl;
    return;
  };

  bool done = false;

  while (!done) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      };
    };

    // Process input

    // Update game

    // Render
    m_renderer2d->render(mainWindow);
  };
};
