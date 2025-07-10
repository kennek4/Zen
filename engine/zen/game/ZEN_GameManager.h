#pragma once

#include "zen/textures/ZEN_Texture2D.h"
#include <memory>
#include <unordered_map>
#include <zen/2d/ZEN_GameObject2D.h>

class ZEN_GameManager {
public:
  ZEN_GameManager();
  ~ZEN_GameManager();

  void addGameObject2D(std::string const &name,
                       std::shared_ptr<ZEN_Texture2D> texture,
                       glm::vec2 const &position = glm::vec2(200.0f),
                       glm::vec2 const &size = glm::vec2(100.0f));
  void removeGameObject2D(std::string const &name);
  bool contains(std::string const &name);

  std::shared_ptr<ZEN_GameObject2D> getGameObject(std::string const &name);

private:
  std::unordered_map<std::string, std::shared_ptr<ZEN_GameObject2D>>
      m_gameObjects{};
};
