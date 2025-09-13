#pragma once

#include <zen/zen_pch.h>

#include <zen/renderer/ZEN_VertexArray.h>

namespace Zen {
  /**
   * @brief Abstraction over the graphics backend
   */
  class RendererAPI {
    public:
      /**
       * @brief An enum declaring the supported rendering API
       */
      enum class API {
        None = 0, OpenGL = 1
      };
    public:
      /**
       * @brief Set the RGBA colour used by clear()
       * @param colour 
       */
      virtual void setClearColour(const glm::vec4 &colour) = 0;

      /**
       * @brief Clears the currently bound framebuffer
       */
      virtual void clear() = 0;

      /**
       * @brief Submits an indexed draw 
       * @param vertexArray 
       */
      virtual void drawIndexed(const std::shared_ptr<VertexArray> &vertexArray) = 0;

      /**
       * @brief Returns the current backend enum
       * @return API 
       */
      inline static API getAPI() {return s_API;}
    
    private:
      static API s_API;
};
}; // namespace Zen