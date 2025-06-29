# Metadata
set(ZEN_ENGINE_VERSION 0.1.0)

project(ZenEngineLib)

include(2d/CMakeLists.txt)
include(base/CMakeLists.txt)
include(renderer/CMakeLists.txt)

set(ZEN_HEADER zen.h ${ZEN_BASE_HEADER} ${ZEN_RENDERER_HEADER})
set(ZEN_SRC ${ZEN_BASE_SRC} ${ZEN_RENDERER_SRC})

list(APPEND ZEN_SRC ${ZEN_HEADER})
add_library(ZenEngine STATIC ${ZEN_SRC})

target_include_directories(
  ZenEngine
  PUBLIC ${ZEN_ROOT_PATH}
  PUBLIC ${ZEN_ROOT_PATH}/engine
  INTERFACE ${ZEN_ROOT_PATH}/engine/2d
  INTERFACE ${ZEN_ROOT_PATH}/engine/base
  INTERFACE ${ZEN_ROOT_PATH}/engine/renderer)
