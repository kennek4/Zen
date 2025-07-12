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
  INTERFACE ${ZEN_ROOT_PATH}/engine/base/managers
  INTERFACE ${ZEN_ROOT_PATH}/engine/base/2d
  INTERFACE ${ZEN_ROOT_PATH}/engine/render
  INTERFACE ${ZEN_ROOT_PATH}/engine/render/backend)

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
endif()

# OpenGL
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)


include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281) # 10.2.1
FetchContent_MakeAvailable(fmt)

# Include folder libraries
target_link_libraries(ZenEngine STB_IMAGE)
target_link_libraries(ZenEngine SPDLOG)
target_link_libraries(ZenEngine DOCTEST)

# External libraries
target_link_libraries(ZenEngine glm::glm SDL3::SDL3 OpenGL::OpenGL fmt::fmt)
