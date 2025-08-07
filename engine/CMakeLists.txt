# Metadata
set(ZEN_ENGINE_VERSION 0.1.0)

project(ZenEngineLib)
include(zen/CMakeLists.txt)
include(zen/core/CMakeLists.txt)
include(zen/textures/CMakeLists.txt)
include(zen/platform/CMakeLists.txt)
include(zen/log/CMakeLists.txt)
include(zen/events/CMakeLists.txt)

# System Config
if(UNIX AND NOT APPLE)
  set(ZEN_HEADER
      zen/zen.h
      ${ZEN_BASE_HEADER}
      ${ZEN_CORE_HEADER}
      ${ZEN_TEXTURES_HEADER}
      ${ZEN_LOG_HEADER}
      ${ZEN_LINUX_HEADER}
      ${ZEN_EVENTS_HEADER})

  set(ZEN_SRC ${ZEN_CORE_SRC} ${ZEN_TEXTURES_SRC} ${ZEN_LOG_SRC}
              ${ZEN_LINUX_SRC} ${ZEN_EVENTS_SRC})

  list(APPEND ZEN_SRC ${ZEN_HEADER})
  add_library(ZenEngine STATIC ${ZEN_SRC})
  target_compile_definitions(ZenEngine PUBLIC __ZEN_PLATFORM_LINUX)
elseif(WIN32)
  set(ZEN_HEADER zen/zen.h ${ZEN_BASE_HEADER} ${ZEN_CORE_HEADER}
                 ${ZEN_TEXTURES_HEADER} ${ZEN_LOG_HEADER})

  set(ZEN_SRC ${ZEN_CORE_SRC} ${ZEN_TEXTURES_SRC} ${ZEN_LOG_SRC})

  list(APPEND ZEN_SRC ${ZEN_HEADER})
  add_library(ZenEngine STATIC ${ZEN_SRC})
  target_compile_definitions(ZenEngine PUBLIC __ZEN_PLATFORM_WINDOWS)
endif()

target_include_directories(
  ZenEngine
  PUBLIC ${ZEN_ROOT_PATH}
  PUBLIC ${ZEN_ROOT_PATH}/engine
  INTERFACE ${ZEN_ROOT_PATH}/engine/zen
  INTERFACE ${ZEN_ROOT_PATH}/engine/zen/core
  INTERFACE ${ZEN_ROOT_PATH}/engine/zen/log
  INTERFACE ${ZEN_ROOT_PATH}/engine/zen/opengl
  INTERFACE ${ZEN_ROOT_PATH}/engine/zen/platform
  INTERFACE ${ZEN_ROOT_PATH}/engine/zen/textures
  INTERFACE ${ZEN_ROOT_PATH}/engine/zen/events)

include(FetchContent)

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
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# OpenGL
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)

if(NOT TARGET fmt)
  FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG e69e5f977d458f2650bb346dadf2ad30c5320281
    FIND_PACKAGE_ARGS REQUIRED) # 10.2.1

endif()

# spdlog
if(NOT TARGET spdlog)
  # Stand-alone build
  find_package(spdlog REQUIRED)
endif()

# External libraries
target_link_libraries(
  ZenEngine
  glad
  glm
  stb_image
  SDL3::SDL3
  fmt::fmt
  spdlog::spdlog
  ${OPENGL_LIBRARIES})
