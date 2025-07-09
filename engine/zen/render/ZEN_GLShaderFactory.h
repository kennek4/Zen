#pragma once

#include <memory>
#include <zen/render/ZEN_GLShader.h>

class ZEN_GLShaderFactory {
public:
  std::shared_ptr<ZEN_GLShader> createShader(std::string const &vertexPath,
                                             std::string const &fragmentPath);

  ZEN_GLShaderFactory() {};
  ~ZEN_GLShaderFactory() {};
};
