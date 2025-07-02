#pragma once

#include <GL/gl.h>
#include <iostream>
#include <renderer/apis/ZEN_GraphicsAPI.h>

class ZEN_OpenGL : public ZEN_GraphicsAPI {
public:
  ZEN_OpenGL() {
    init();
    setMetaData();
    std::cout << "OpenGL initialized!" << std::endl;
  };

  ~ZEN_OpenGL() {

  };

  bool init();
  ZEN_Graphics_MetaData *getMetaData();

private:
  void setMetaData();
  ZEN_Graphics_MetaData m_metaData{};
  GLuint m_glProgramId{};
  GLuint m_glVBO{};
  GLuint m_gIBO{};
};

inline void ZEN_OpenGL::setMetaData() {
  this->m_metaData.API_NAME = "OpenGL";
  // std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
  // std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
  // std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
  // std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
  //           << std::endl;
};
