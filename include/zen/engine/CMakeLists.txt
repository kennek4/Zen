project(ZEN_CORE)

add_library(CORE INTERFACE)
target_include_directories(
  CORE INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                 ${CMAKE_CURRENT_SOURCE_DIR}/subsystems/)
