#pragma once

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <string>
#include <zen/2d/ZEN_Sprite.h>
#include <zen/2d/ZEN_Transform2D.h>

class ZEN_GameObject2D {
public:
  ZEN_GameObject2D(std::string name, ZEN::Transform2D transform,
                   ZEN::Sprite sprite)
      : m_name(name), m_transform(transform), m_sprite(sprite) {};
  ~ZEN_GameObject2D();

  void translate(float xOffset = 0.0f, float yOffset = 0.0f);
  void scale(float xScalar = 1.0f, float yScalar = 1.0f);
  void rotate(float rotationOffset = 0.0f);

  void setPosition(float newX, float newY);
  void setPosition(glm::vec2 position);
  void setSize(float width, float height);
  void setSize(glm::vec2 size);
  void setRotation(float newRotation);
  void setTransform(ZEN::Transform2D);

  glm::vec2 const &getPosition();
  glm::vec2 const &getSize();
  float const &getRotation();
  ZEN::Transform2D const &getTransform();
  ZEN::Sprite const &getSprite();

private:
  std::string m_name;
  ZEN::Transform2D m_transform{};
  ZEN::Sprite m_sprite{};
};
