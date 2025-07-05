#include <base/2d/ZEN_Texture2D.h>

ZEN_Texture2D::ZEN_Texture2D() { glGenTextures(1, &m_id); };

void ZEN_Texture2D::create(unsigned int width, unsigned int height,
                           unsigned char *data) {
  m_properties.width = width;
  m_properties.height = height;

  glBindTexture(GL_TEXTURE_2D, m_id);
  glTexImage2D(GL_TEXTURE_2D, 0, m_properties.internalFormat,
               m_properties.width, m_properties.height, 0,
               m_properties.imageFormat, GL_UNSIGNED_BYTE, data);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_properties.sWrap);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_properties.tWrap);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_properties.minFilter);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_properties.maxFilter);
  glBindTexture(GL_TEXTURE_2D, 0);
};

void ZEN_Texture2D::bind() const { glBindTexture(GL_TEXTURE_2D, m_id); };

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
