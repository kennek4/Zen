#pragma once

#ifndef __gl_h_
#include <glad/gl.h>
#endif // !__gl_h_

#include <glm/glm.hpp>
#include <string>

namespace Zen {
enum class ShaderType { VERTEX, FRAGMENT };

class Shader {
public:
  Shader(std::string const &vertexPath, std::string const &fragmentPath);
  Shader &use();

  // Utility for Uniforms
  void setInt(const std::string &name, int value, bool useShader = true);
  void setFloat(const std::string &name, float value, bool useShader = true);
  void setBool(const std::string &name, bool value, bool useShader = true);
  void setMatrix4(const std::string &name, glm::mat4 value,
                  bool useShader = true);
  void setVector3f(const std::string &name, glm::vec3 value,
                   bool useShader = true);

  const unsigned int &getId();

private:
  void create(Zen::ShaderType shaderType, GLuint *shaderId,
              const char *shaderCode, GLint &compileStatus);
  unsigned int m_id;
};
}; // namespace Zen
