#pragma once

#include <glad/gl.h>
#include <string>

namespace ZEN {
typedef enum ShaderType {
  VERTEX = GL_VERTEX_SHADER,
  FRAGMENT = GL_FRAGMENT_SHADER,
} ShaderType;
};

class ZEN_GLShader {
public:
  ZEN_GLShader(std::string const &vertexPath, std::string const &fragmentPath);
  void use();

  // Utility for Uniforms
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
  void setBool(const std::string &name, bool value) const;

  unsigned int const &getId();

private:
  void create(ZEN::ShaderType type, GLuint *shader, const char *shaderCode,
              GLint &compileStatus);
  unsigned int m_glId;
};
