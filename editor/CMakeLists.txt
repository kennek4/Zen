project(ZenEditor)
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

# ##############################################################################
# ###### Main Program Exec #####################################################
# ##############################################################################
add_executable(ZEN src/main.cpp)
set_target_properties(ZEN PROPERTIES OUTPUT_NAME "Zen")

target_link_directories(ZEN PRIVATE src)
target_link_libraries(ZEN PRIVATE ZenEngine)
target_link_libraries(ZEN PRIVATE ZenEngine glm::glm SDL3_image::SDL3_image
                                  SDL3::SDL3 OpenGL::OpenGL)
