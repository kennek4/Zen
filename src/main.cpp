#include "engine/subsystems/window.h"
#include "event_manager.h"
#include <memory>

int main(int argc, char *argv[]) {
  std::shared_ptr<Zen::EventManager> eventManager{new Zen::EventManager()};
  Zen::WindowSubsystem *windowZero = new Zen::WindowSubsystem(0, eventManager);
  Zen::WindowSubsystem *windowOne = new Zen::WindowSubsystem(1, eventManager);

  delete windowOne;
  delete windowZero;
}
