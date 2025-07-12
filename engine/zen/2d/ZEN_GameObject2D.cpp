#include <zen/2d/ZEN_GameObject2D.h>
#include <zen/resource/ZEN_ResourceManager.h>

ZEN_GameObject2D::ZEN_GameObject2D(std::string objName, ZEN::Sprite objSprite) {
  name = objName;
  sprite = objSprite;
};

ZEN_GameObject2D::~ZEN_GameObject2D() {

};

void ZEN_GameObject2D::translate(float xOffset, float yOffset) {
  position.x += xOffset;
  position.y += yOffset;
};

void ZEN_GameObject2D::scale(float xScalar, float yScalar) {
  size.x *= xScalar;
  size.y *= yScalar;
};

void ZEN_GameObject2D::rotate(float rotationOffset) {
  rotation += rotationOffset;
};
