#include <GLES3/gl3.h>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>
#include <zen/opengl/ZEN_Shader.h>

namespace Zen {
Shader::Shader(std::string const &vertexPath, std::string const &fragmentPath) {

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

    create(Zen::ShaderType::VERTEX, &vertex, vertCode, status);
    if (status != GL_TRUE) {
        glGetShaderInfoLog(vertex, 1024, &log_length, message);
    };

    create(Zen::ShaderType::VERTEX, &fragment, fragCode, status);
    if (status != GL_TRUE) {
        glGetShaderInfoLog(fragment, 1024, &log_length, message);
    };

    this->m_id = glCreateProgram();

    glAttachShader(this->m_id, vertex);
    glAttachShader(this->m_id, fragment);
    glLinkProgram(this->m_id);

    // Check to see if shaders were linked to program
    glGetProgramiv(m_id, GL_LINK_STATUS, &status);
    if (status != GL_TRUE) {
        glGetShaderInfoLog(fragment, 1024, &log_length, message);
    };

    // Safe to delete
    glDeleteShader(vertex);
    glDeleteShader(fragment);
};

Shader &Shader::use() {
    glUseProgram(this->m_id);
    return *this;
};

void Shader::setBool(const std::string &name, bool value, bool useShader) {
    if (useShader) {
        use();
    };

    glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value);
};

void Shader::setInt(const std::string &name, int value, bool useShader) {
    if (useShader) {
        use();
    };

    glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
};

void Shader::setFloat(const std::string &name, float value, bool useShader) {

    if (useShader) {
        use();
    };

    glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
};

void Shader::setMatrix4(const std::string &name, glm::mat4 value,
                        bool useShader) {

    if (useShader) {
        use();
    };

    glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, false,
                       glm::value_ptr(value));
};

void Shader::setVector3f(const std::string &name, glm::vec3 value,
                         bool useShader) {

    if (useShader) {
        use();
    };

    glUniform3f(glGetUniformLocation(m_id, name.c_str()), value.x, value.y,
                value.z);
};

unsigned int const &Shader::getId() { return m_id; };

void Shader::create(Zen::ShaderType type, GLuint *shader,
                    const char *shaderCode, GLint &compileStatus) {

    switch (type) {
    case Zen::ShaderType::VERTEX:
        *shader = glCreateShader(GL_VERTEX_SHADER);
        break;

    case Zen::ShaderType::FRAGMENT:
        *shader = glCreateShader(GL_FRAGMENT_SHADER);
        break;
    };

    glShaderSource(*shader, 1, &shaderCode, nullptr);
    glCompileShader(*shader);
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &compileStatus);
};
}; // namespace Zen
