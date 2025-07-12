#pragma once

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <memory>
#include <string>
#include <zen/2d/ZEN_Sprite.h>
#include <zen/2d/ZEN_Transform2D.h>

class ZEN_GameObject2D {
public:
  ZEN_GameObject2D(std::string objName, ZEN::Sprite objSprite);
  ~ZEN_GameObject2D();

  void translate(float xOffset = 0.0f, float yOffset = 0.0f);
  void scale(float xScalar = 1.0f, float yScalar = 1.0f);
  void rotate(float rotationOffset = 0.0f);

  std::string name = "";
  glm::vec2 position{0.0f, 0.0f};
  glm::vec2 size{10.0f, 10.0f};
  float rotation{0.0f};

  std::shared_ptr<ZEN::Sprite> sprite;
};
