project(ZEN_CORE)

set(CORE_SUBSYSTEMS
    ${CMAKE_CURRENT_SOURCE_DIR}/subsystems/subsystem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/subsystems/render.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/subsystems/render.h
    ${CMAKE_CURRENT_SOURCE_DIR}/subsystems/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/subsystems/window.h)

set(CORE_ENGINE ${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/engine.h)

add_library(CORE STATIC ${CORE_SUBSYSTEMS} ${CORE_ENGINE})
target_include_directories(
  CORE
  PUBLIC STATIC ${CMAKE_CURRENT_SOURCE_DIR}/types/
         ${CMAKE_CURRENT_SOURCE_DIR}/subsystems/ ${CMAKE_CURRENT_SOURCE_DIR}/)
