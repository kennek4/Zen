#include <GLES3/gl3.h>
#include <renderer/apis/ZEN_OpenGL.h>

bool ZEN_OpenGL::init() {
  bool success = true;
  m_glProgramId = glCreateProgram();
  return success;
};

ZEN_Graphics_MetaData *ZEN_OpenGL::getMetaData() { return &m_metaData; };
