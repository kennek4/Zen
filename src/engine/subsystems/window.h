#ifndef ZEN_WINDOW_SUBSYSTEM
#define ZEN_WINDOW_SUBSYSTEM

#include <event_manager.h>
#include <format>
#include <iostream>
#include <memory>
#include <subsystem.h>
#include <sys/types.h>

namespace Zen {
class WindowSubsystem : public Subsystem {
public:
  WindowSubsystem(u_int systemId, std::shared_ptr<EventManager> eventManager)
      : Subsystem(systemId) {
    std::cout << std::format("[SID: {}] Hello!\n", getSystemId());
  };

  ~WindowSubsystem() {
    std::cout << std::format("[SID: {}] Bye Bye!\n", getSystemId());
  };

  void emitEvent(u_int event) {

  };

  void handleEvent(u_int event) {

  };

private:
  std::shared_ptr<EventManager> eventManager;
};
}; // namespace Zen

#endif // !ZEN_WINDOW_SUBSYSTEM
