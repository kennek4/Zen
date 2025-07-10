#include "zen/2d/ZEN_GameObject2D.h"
#include "zen/2d/ZEN_Sprite.h"
#include "zen/2d/ZEN_Transform2D.h"
#include <memory>
#include <zen/game/ZEN_GameManager.h>

ZEN_GameManager::ZEN_GameManager() {

};

ZEN_GameManager::~ZEN_GameManager() {

};

void ZEN_GameManager::addGameObject2D(std::string const &name,
                                      std::shared_ptr<ZEN_Texture2D> texture,
                                      glm::vec2 const &position,
                                      glm::vec2 const &size) {
  if (!contains(name)) {
    std::shared_ptr<ZEN_GameObject2D> gameObject =
        std::make_shared<ZEN_GameObject2D>(
            name, ZEN::Transform2D{position, size}, ZEN::Sprite{texture});

    m_gameObjects[name] = gameObject;
  };
};

void ZEN_GameManager::removeGameObject2D(std::string const &name) {
  if (contains(name)) {
    m_gameObjects.erase(name);
  };
};

bool ZEN_GameManager::contains(std::string const &name) {
  return m_gameObjects.contains(name);
};

std::shared_ptr<ZEN_GameObject2D>
ZEN_GameManager::getGameObject(std::string const &name) {
  return m_gameObjects[name];
};
