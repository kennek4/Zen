#include <base/ZEN_Engine.h>

void ZEN_Engine::loop() {
  bool done = false;
  int colour = 0;

  std::cout << "Starting engine loop!" << std::endl;
  if (m_windowManager->getWindow() != NULL) {
    while (!done) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
          done = true;
        }
      }
      // Do game logic, present a frame, etc.
      glClearColor(colour, colour, colour, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      SDL_GL_SwapWindow(m_windowManager->getWindow());
    }
  };

  std::cout << "Ending engine loop!" << std::endl;
};
