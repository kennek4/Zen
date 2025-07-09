#include <memory>
#include <zen/render/ZEN_GLShaderFactory.h>

std::shared_ptr<ZEN_GLShader>
ZEN_GLShaderFactory::createShader(std::string const &vertexPath,
                                  std::string const &fragmentPath) {
  std::shared_ptr<ZEN_GLShader> shader =
      std::make_shared<ZEN_GLShader>(vertexPath, fragmentPath);
  return shader;
};
