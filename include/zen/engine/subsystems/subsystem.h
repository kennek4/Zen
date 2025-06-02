#ifndef ZEN_SUBSYSTEM
#define ZEN_SUBSYSTEM

#include <sys/types.h>

namespace Zen {
class Subsystem {
public:
  Subsystem(u_int systemId) { this->m_systemId = systemId; };

  virtual ~Subsystem() {

  };

  // TODO: Change the parameter to an event type
  virtual void emitEvent(u_int event) = 0;
  virtual void handleEvent(u_int event) = 0;

  inline const u_int getSystemId() { return m_systemId; };

private:
  u_int m_systemId{0};
};
}; // namespace Zen

#endif // !ZEN_SUBSYSTEM
