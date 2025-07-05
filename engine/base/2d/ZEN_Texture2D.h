#pragma once

#include <GL/gl.h>

namespace ZEN {
typedef struct TextureProperties {
  unsigned int width{0};
  unsigned int height{0};
  unsigned int internalFormat{GL_RGB};
  unsigned int imageFormat{GL_RGB};
  unsigned int minFilter{GL_LINEAR};
  unsigned int maxFilter{GL_LINEAR};
  unsigned int sWrap{GL_REPEAT};
  unsigned int tWrap{GL_REPEAT};
} TextureProperties;
}; // namespace ZEN

class ZEN_Texture2D {
public:
  ZEN_Texture2D();
  void create(unsigned int width, unsigned int height, unsigned char *data);
  void bind() const;

  // Getters and setters
  void setWidth(unsigned int width);
  void setHeight(unsigned int height);
  void setInternalFormat(unsigned int internalFormat);
  void setImageFormat(unsigned int imageFormat);
  void setMinFilter(unsigned int minFilter);
  void setMaxFilter(unsigned int maxFilter);
  void setSWrap(unsigned int sWrap);
  void setTWrap(unsigned int tWrap);

  ZEN::TextureProperties const &getProperties();
  unsigned int const &getId();

private:
  unsigned int m_id;
  ZEN::TextureProperties m_properties{ZEN::TextureProperties()};
};
