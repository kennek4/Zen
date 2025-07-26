#include "zen.h"

class Zenith : public Zen::Application {
  public:
  private:
};

Zen::Application *Zen::CreateApplication() { return new Zenith(); };
