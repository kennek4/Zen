#pragma once

#include <GL/gl.h>

namespace ZEN {
typedef struct TextureProperties {
  GLuint width{0};
  GLuint height{0};
  GLuint internalFormat{GL_RGB};
  GLuint imageFormat{GL_RGB};
  GLuint minFilter{GL_LINEAR};
  GLuint maxFilter{GL_LINEAR};
  GLuint sWrap{GL_REPEAT};
  GLuint tWrap{GL_REPEAT};
} TextureProperties;
}; // namespace ZEN

class ZEN_Texture2D {
public:
  ZEN_Texture2D();
  void create(GLuint width, GLuint height, unsigned char *data);
  void bind() const;

  // Getters and setters
  void setWidth(GLuint width);
  void setHeight(GLuint height);
  void setInternalFormat(GLuint internalFormat);
  void setImageFormat(GLuint imageFormat);
  void setMinFilter(GLuint minFilter);
  void setMaxFilter(GLuint maxFilter);
  void setSWrap(GLuint sWrap);
  void setTWrap(GLuint tWrap);

  ZEN::TextureProperties const &getProperties();
  GLuint const &getId();

private:
  GLuint m_id;
  ZEN::TextureProperties m_properties{ZEN::TextureProperties()};
};
