project(ZEN_GLAD)

add_library(
  glad
  ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/gl.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/KHR/khrplatform.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gl.c)

target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
