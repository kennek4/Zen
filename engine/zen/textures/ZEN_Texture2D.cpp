#include <GL/gl.h>
#include <zen/textures/ZEN_Texture2D.h>

ZEN_Texture2D::ZEN_Texture2D(unsigned int width, unsigned int height,
                             unsigned char *data) {

  m_properties.width = width;
  m_properties.height = height;

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &this->m_id);
  glBindTexture(GL_TEXTURE_2D, this->m_id);
  glTexImage2D(GL_TEXTURE_2D, 0, m_properties.internalFormat, width, height, 0,
               m_properties.imageFormat, GL_UNSIGNED_BYTE, data);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 1.0f);

  glBindTexture(GL_TEXTURE_2D, 0);
};

ZEN_Texture2D::ZEN_Texture2D(unsigned int width, unsigned int height,
                             unsigned int internalFormat,
                             unsigned int imageFormat, unsigned char *data) {
  m_properties.width = width;
  m_properties.height = height;
  m_properties.internalFormat = internalFormat;
  m_properties.imageFormat = imageFormat;

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &this->m_id);
  glBindTexture(GL_TEXTURE_2D, this->m_id);
  glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, imageFormat,
               GL_UNSIGNED_BYTE, data);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 1.0f);

  glBindTexture(GL_TEXTURE_2D, 0);
};

void ZEN_Texture2D::bind() const { glBindTexture(GL_TEXTURE_2D, this->m_id); };

void ZEN_Texture2D::setWidth(unsigned int width) {
  m_properties.width = width;
};

void ZEN_Texture2D::setHeight(unsigned int height) {
  m_properties.height = height;
};

void ZEN_Texture2D::setInternalFormat(unsigned int internalFormat) {
  m_properties.internalFormat = internalFormat;
};

void ZEN_Texture2D::setImageFormat(unsigned int imageFormat) {
  m_properties.imageFormat = imageFormat;
};

void ZEN_Texture2D::setMinFilter(unsigned int minFilter) {
  m_properties.minFilter = minFilter;
};

void ZEN_Texture2D::setMaxFilter(unsigned int maxFilter) {
  m_properties.maxFilter = maxFilter;
};

void ZEN_Texture2D::setSWrap(unsigned int sWrap) {
  m_properties.sWrap = sWrap;
};

void ZEN_Texture2D::setTWrap(unsigned int tWrap) {
  m_properties.tWrap = tWrap;
};

ZEN::TextureProperties const &ZEN_Texture2D::getProperties() {
  return m_properties;
};

unsigned int const &ZEN_Texture2D::getId() { return m_id; };
