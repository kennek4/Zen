#ifndef ZEN_EVENT_EVENT_MANAGER
#define ZEN_EVENT_EVENT_MANAGER

#include <map>
#include <queue>
#include <subsystem.h>
#include <sys/types.h>
#include <vector>

namespace Zen {
class EventManager {
public:
  EventManager() {

  };

  ~EventManager() {

  };

  void addObserver(Subsystem *observer, u_int event);
  void alertObservers(u_int event);

  std::vector<Subsystem *> getSubscribers(u_int event);

private:
  // TODO: Switch u_int to the event type
  std::queue<u_int> eventQueue;
  std::map<u_int, std::vector<Subsystem *>> subscribers;
};
} // namespace Zen

#endif // !ZEN_EVENT_EVENT_MANAGER
