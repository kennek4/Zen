#pragma once

#include <zen/zen_pch.h>

namespace Zen {
class EventListener {
  public:
    virtual bool onEvent(const SDL_Event &event) = 0;
    virtual ~EventListener() = default;
};

class Events {
  public:
    void dispatch(const SDL_Event &event);
    void poll();
    void registerListener(int priority, EventListener *listener);
    void unregisterListener(EventListener *listener);

  private:
    std::map<int, std::vector<EventListener *>, std::less<int>> m_listeners;
};
}; // namespace Zen
