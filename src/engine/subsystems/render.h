#ifndef ZEN_RENDER_SUBSYSTEM
#define ZEN_RENDER_SUBSYSTEM

#include "subsystem.h"
#include <format>
#include <iostream>

namespace Zen {
class RenderSubsystem : public Subsystem {
public:
  RenderSubsystem(u_int systemId) : Subsystem(systemId) {
    std::cout << std::format("[SID: {}] Hello!\n", getSystemId());
  };

  ~RenderSubsystem() {
    std::cout << std::format("[SID: {}] Bye Bye!\n", getSystemId());
  };

  void emitEvent(u_int event) {

  };

  void handleEvent(u_int event) {

  };

private:
};
}; // namespace Zen

#endif // !ZEN_RENDER_SUBSYSTEM
