#pragma once

#ifndef __gl_h_
#include <glad/gl.h>
#endif // !__gl_h_

#include <glm/glm.hpp>
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
  ZEN_GLShader &use();

  // Utility for Uniforms
  void setInt(const std::string &name, int value, bool useShader = true);
  void setFloat(const std::string &name, float value, bool useShader = true);
  void setBool(const std::string &name, bool value, bool useShader = true);
  void setMatrix4(const std::string &name, glm::mat4 value,
                  bool useShader = true);
  void setVector3f(const std::string &name, glm::vec3 value,
                   bool useShader = true);

  unsigned int const &getId();

private:
  void create(ZEN::ShaderType type, GLuint *shader, const char *shaderCode,
              GLint &compileStatus);
  unsigned int m_glId;
};
