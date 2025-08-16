#pragma once

#include <zen_pch.h>
#include <zen/core/ZEN_Core.h>
#include <zen/layer/ZEN_Layer.h>

#include <vector>

namespace Zen {
  class LayerList {
    public:
      LayerList() = default;
      ~LayerList();

      void PushLayer(Layer *layer);
      void PushOverlay(Layer *overlay);
      void PopLayer(Layer *layer);
      void PopOverlay(Layer *overlay);

      using ListOfLayers = std::vector<Layer*>;

      ListOfLayers::iterator begin() {return m_layers.begin();}
      ListOfLayers::iterator end() {return m_layers.end();}
      ListOfLayers::reverse_iterator rbegin() {return m_layers.rbegin();}
      ListOfLayers::reverse_iterator rend() {return m_layers.rend();}

    private:
      std::vector<Layer*> m_layers; //vector of layers
      unsigned int m_layerInsertIndex = 0;

  };
}; // namespace Zen