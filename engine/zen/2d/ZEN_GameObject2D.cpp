#include <zen/2d/ZEN_GameObject2D.h>

ZEN_GameObject2D::~ZEN_GameObject2D() {

};

void ZEN_GameObject2D::translate(float xOffset, float yOffset) {
  m_transform.position.x += xOffset;
  m_transform.position.y += yOffset;
};

void ZEN_GameObject2D::scale(float xScalar, float yScalar) {
  m_transform.size.x *= xScalar;
  m_transform.size.y *= yScalar;
};

void ZEN_GameObject2D::rotate(float rotationOffset) {
  m_transform.rotation += rotationOffset;
};

void ZEN_GameObject2D::setPosition(float x, float y) {
  m_transform.position.x = x;
  m_transform.position.y = y;
};

void ZEN_GameObject2D::setPosition(glm::vec2 position) {
  m_transform.position = position;
};

void ZEN_GameObject2D::setSize(float width, float height) {
  m_transform.size.x = width;
  m_transform.size.y = height;
};

void ZEN_GameObject2D::setSize(glm::vec2 size) { m_transform.size = size; };

void ZEN_GameObject2D::setRotation(float rotation) {
  m_transform.rotation = rotation;
};

void ZEN_GameObject2D::setTransform(ZEN::Transform2D transform) {
  m_transform = transform;
};

glm::vec2 const &ZEN_GameObject2D::getPosition() {
  return m_transform.position;
};

glm::vec2 const &ZEN_GameObject2D::getSize() { return m_transform.size; };

float const &ZEN_GameObject2D::getRotation() { return m_transform.rotation; };

ZEN::Transform2D const &ZEN_GameObject2D::getTransform() {
  return m_transform;
};
