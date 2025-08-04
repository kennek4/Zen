#include <zen/events/ZEN_Events.h>

namespace Zen {
void Events::dispatch(const SDL_Event &event) {
  for (auto &[priority, listeners] : m_listeners) {
    for (auto *listener : listeners) {
      if (listener->onEvent(event)) return;
    }
  }
};

void Events::poll() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    dispatch(event);
  }
}

void Events::registerListener(int priority, EventListener *listener) {
  m_listeners[priority].push_back(listener);
}

void Events::unregisterListener(EventListener *listener) {
  for (auto &[priority, vec] : m_listeners) { 
    for (auto i = vec.begin(); i != vec.end();) {
      if (*i == listener) {
        i = vec.erase(i);
      } else {
        i++;
      }
    }
  }
}

}; // namespace Zen

