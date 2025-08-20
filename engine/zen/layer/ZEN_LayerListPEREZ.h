#pragma once

#include <zen_pch.h>
#include <zen/core/ZEN_Core.h>
#include <zen/layer/ZEN_Layer.h>

namespace Zen {
  class LayerListPEREZ {
    public:
      LayerListPEREZ() = default;
      ~LayerListPEREZ() = default;

      void PushLayer(std::unique_ptr<Layer> layer);
      void PushOverlay(std::unique_ptr<Layer> overlay);
      std::unique_ptr<Layer> PopLayer(Layer *layer);
      std::unique_ptr<Layer> PopOverlay(Layer *overlay);

      using ListOfLayers = std::vector<std::unique_ptr<Layer>>;

      ListOfLayers::iterator begin() {return m_layers.begin();}
      ListOfLayers::iterator end() {return m_layers.end();}
      ListOfLayers::reverse_iterator rbegin() {return m_layers.rbegin();}
      ListOfLayers::reverse_iterator rend() {return m_layers.rend();}

    private:
      ListOfLayers m_layers; //vector of layers
      std::size_t m_layerInsertIndex = 0;

  };
}; // namespace Zen