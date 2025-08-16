#include <zen/layer/ZEN_LayerListPEREZ.h>

namespace Zen {

  void LayerListPEREZ::PushLayer(std::unique_ptr<Layer> layer) {
    if (!layer) return;
    m_layers.insert(m_layers.begin() + m_layerInsertIndex, std::move(layer));
    //m_layers[m_layerInsertIndex - 1]->onAttach();
  }
  
  void LayerListPEREZ::PushOverlay(std::unique_ptr<Layer> overlay) {
    if (!overlay) return;
    m_layers.emplace_back(overlay);
    //m_layers[m_layerInsertIndex]->onAttach();
  }

  std::unique_ptr<Layer> LayerListPEREZ::PopLayer(Layer *layer) {
    if (!layer) return nullptr;
    for (std::size_t i = 0; i < m_layerInsertIndex; i++) {
      if (m_layers[i].get() == layer) {
        auto temp = std::move(m_layers[i]);
        temp->onDetach();
        m_layers.erase(m_layers.begin() + i);
        
        if (i < m_layerInsertIndex) {
          m_layerInsertIndex--;
        }

        return std::move(temp);
      }
    }
  }

  std::unique_ptr<Layer> LayerListPEREZ::PopOverlay(Layer *overlay) {
    if (!overlay) return nullptr;
    for (std::size_t i = m_layerInsertIndex; i < m_layers.size(); i++) {
      if (m_layers[i].get() == overlay) {
        auto temp = std::move(m_layers[i]);
        temp->onDetach();
        m_layers.erase(m_layers.begin() + i);
        
        if (i < m_layerInsertIndex) {
          m_layerInsertIndex--;
        }

        return std::move(temp);
      }
    }

  }
} // namespace Zen