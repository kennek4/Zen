#include <GLES3/gl3.h>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>
#include <zen/render/ZEN_GLShader.h>

ZEN_GLShader::ZEN_GLShader(std::string const &vertexPath,
                           std::string const &fragmentPath) {

  std::string vertCodeStr{};
  std::string fragCodeStr{};
  std::ifstream vertShaderFile{};
  std::ifstream fragShaderFile{};

  vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {

    vertShaderFile.open(vertexPath.c_str());
    fragShaderFile.open(fragmentPath.c_str());

    std::stringstream vertStringStream, fragStringStream;
    vertStringStream << vertShaderFile.rdbuf();
    fragStringStream << fragShaderFile.rdbuf();

    vertShaderFile.close();
    fragShaderFile.close();

    vertCodeStr = vertStringStream.str();
    fragCodeStr = fragStringStream.str();

  } catch (std::ifstream::failure err) {
    // TODO: Add error handling here
  };

  const char *vertCode = vertCodeStr.c_str();
  const char *fragCode = fragCodeStr.c_str();

  // Compiling shaders
  GLuint vertex, fragment;
  GLint status;
  GLsizei log_length = 0;
  GLchar message[1024];

  create(ZEN::VERTEX, &vertex, vertCode, status);
  if (status != GL_TRUE) {
    glGetShaderInfoLog(vertex, 1024, &log_length, message);
    // TODO: Add custom error handling here
  };

  create(ZEN::FRAGMENT, &fragment, vertCode, status);
  if (status != GL_TRUE) {
    glGetShaderInfoLog(fragment, 1024, &log_length, message);
    // TODO: Add custom error handling here
  };

  m_glId = glCreateProgram();

  glAttachShader(m_glId, vertex);
  glAttachShader(m_glId, fragment);
  glLinkProgram(m_glId);

  // Check to see if shaders were linked to program
  glGetProgramiv(m_glId, GL_LINK_STATUS, &status);
  if (status != GL_TRUE) {
    glGetShaderInfoLog(fragment, 1024, &log_length, message);
    // TODO: Add custom error handling here
  };

  // Safe to delete
  glDeleteShader(vertex);
  glDeleteShader(fragment);
};

ZEN_GLShader &ZEN_GLShader::use() {
  glUseProgram(m_glId);
  return *this;
};

void ZEN_GLShader::setBool(const std::string &name, bool value,
                           bool useShader) {
  if (useShader) {
    this->use();
  };

  glUniform1i(glGetUniformLocation(m_glId, name.c_str()), (int)value);
};

void ZEN_GLShader::setInt(const std::string &name, int value, bool useShader) {
  if (useShader) {
    ZEN_GLShader::use();
  };

  glUniform1i(glGetUniformLocation(m_glId, name.c_str()), value);
};

void ZEN_GLShader::setFloat(const std::string &name, float value,
                            bool useShader) {

  if (useShader) {
    ZEN_GLShader::use();
  };

  glUniform1f(glGetUniformLocation(m_glId, name.c_str()), value);
};

void ZEN_GLShader::setMatrix4(const std::string &name, glm::mat4 value,
                              bool useShader) {

  if (useShader) {
    ZEN_GLShader::use();
  };

  glUniformMatrix4fv(glGetUniformLocation(m_glId, name.c_str()), 1, false,
                     glm::value_ptr(value));
};

void ZEN_GLShader::setVector3f(const std::string &name, glm::vec3 value,
                               bool useShader) {

  if (useShader) {
    ZEN_GLShader::use();
  };

  glUniform3f(glGetUniformLocation(m_glId, name.c_str()), value.x, value.y,
              value.z);
};

unsigned int const &ZEN_GLShader::getId() { return m_glId; };

void ZEN_GLShader::create(ZEN::ShaderType type, GLuint *shader,
                          const char *shaderCode, GLint &compileStatus) {

  switch (type) {
  case ZEN::VERTEX:
    *shader = glCreateShader(GL_VERTEX_SHADER);
    break;

  case ZEN::FRAGMENT:
    *shader = glCreateShader(GL_FRAGMENT_SHADER);
    break;
  };

  glShaderSource(*shader, 1, &shaderCode, nullptr);
  glCompileShader(*shader);
  glGetShaderiv(*shader, GL_COMPILE_STATUS, &compileStatus);
};
