#pragma once

#include <zen/zen_pch.h>
#include <zen/core/ZEN_Core.h>

namespace Zen {
  class Layer : public EventListener {
    public:
      Layer(const std::string &name = "Layer");
      virtual ~Layer() = default;

      virtual void onAttach(){}
      virtual void onDetach(){}
      virtual void onUpdate(){}
      virtual bool onEvent(const SDL_Event &event) = 0;

      const std::string& GetName() const { return m_DebugName; }

    protected:
      std::string m_DebugName;
  };
}; // namespace Zen