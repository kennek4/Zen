#include <base/2d/ZEN_Texture2D.h>

ZEN_Texture2D::ZEN_Texture2D() { glGenTextures(1, &m_id); };

void ZEN_Texture2D::createTexture(GLuint width, GLuint height,
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
