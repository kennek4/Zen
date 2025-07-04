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
  void createTexture(GLuint width, GLuint height, unsigned char *data);
  void bind() const;

private:
  GLuint m_id;
  ZEN::TextureProperties m_properties{ZEN::TextureProperties()};
};
