#include "event_manager.h"
#include "subsystem.h"
#include <sys/types.h>
#include <vector>

void Zen::EventManager::addObserver(Zen::Subsystem *observer, u_int event) {
  this->subscribers[event].push_back(observer);
};

void Zen::EventManager::alertObservers(u_int event) {
  const std::vector<Zen::Subsystem *> observers{this->subscribers[event]};
  for (u_int i = 0; i < observers.size(); i++) {
    observers[i]->handleEvent(event);
  };
};

std::vector<Zen::Subsystem *> Zen::EventManager::getSubscribers(u_int event) {
  return this->subscribers[event];
};
