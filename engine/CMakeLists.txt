# Metadata
set(ZEN_ENGINE_VERSION 0.1.0)

project(ZenEngineLib)

include(base/CMakeLists.txt)
include(render/CMakeLists.txt)

set(ZEN_HEADER zen.h ${ZEN_BASE_HEADER} ${ZEN_RENDER_HEADER})
set(ZEN_SRC ${ZEN_BASE_SRC} ${ZEN_RENDER_SRC})

list(APPEND ZEN_SRC ${ZEN_HEADER})
add_library(ZenEngine STATIC ${ZEN_SRC})

target_include_directories(
  ZenEngine
  PUBLIC ${ZEN_ROOT_PATH}
  PUBLIC ${ZEN_ROOT_PATH}/engine
  INTERFACE ${ZEN_ROOT_PATH}/engine/base
  INTERFACE ${ZEN_ROOT_PATH}/engine/render)
