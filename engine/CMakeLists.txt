# Metadata
set(ZEN_ENGINE_VERSION 0.1.0)

project(ZenEngineLib)

include(base/CMakeLists.txt)
include(renderer/CMakeLists.txt)
include(renderer/2d/CMakeLists.txt)

set(ZEN_HEADER zen.h ${ZEN_BASE_HEADER} ${ZEN_RENDERER_HEADER} ${ZEN_2D_HEADER})
set(ZEN_SRC ${ZEN_BASE_SRC} ${ZEN_RENDERER_SRC} ${ZEN_2D_SRC})

list(APPEND ZEN_SRC ${ZEN_HEADER})
add_library(ZenEngine STATIC ${ZEN_SRC})

target_include_directories(
  ZenEngine
  PUBLIC ${ZEN_ROOT_PATH}
  PUBLIC ${ZEN_ROOT_PATH}/engine
  INTERFACE ${ZEN_ROOT_PATH}/engine/base
  INTERFACE ${ZEN_ROOT_PATH}/engine/renderer
  INTERFACE ${ZEN_ROOT_PATH}/engine/renderer/2d)

# SDL
cmake_policy(SET CMP0072 NEW)

# Create an option to switch between a system sdl library and a vendored SDL
# library
option(SDL_VENDORED "Use vendored libraries" OFF)
if(SDL_VENDORED)
  # This assumes you have added SDL as a submodule in vendored/SDL
  add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
  # 1. Look for a SDL3 package,
  # 2. look for the SDL3-shared component, and
  # 3. fail if the shared component cannot be found.
  find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
  find_package(SDL3_image REQUIRED) # Find the SDL3_image package
endif()

# OpenGL
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(ZenEngine glm::glm SDL3_image::SDL3_image SDL3::SDL3
                      OpenGL::OpenGL)
