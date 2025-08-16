#include <zen/layer/ZEN_LayerList.h>

namespace Zen {

  LayerList::~LayerList() {
    for (Layer *layer : m_layers) {
      layer->onDetach();
      delete layer;
    }
  }

  void LayerList::PushLayer(Layer *layer) {
    m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
    m_layerInsertIndex++;
  }
  
  void LayerList::PushOverlay(Layer *overlay) {
    m_layers.emplace_back(overlay);
  }
  void LayerList::PopLayer(Layer *layer) {
    auto it = std::find(m_layers.begin(), m_layers.end(), layer);
    if (it != m_layers.end()) {
      layer->onDetach();
			m_layers.erase(it);
			m_layerInsertIndex--;
    }
  }
  void LayerList::PopOverlay(Layer *overlay) {
    auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
    if (it != m_layers.end()) {
      overlay->onDetach();
			m_layers.erase(it);
    }
  }
} // namespace Zen