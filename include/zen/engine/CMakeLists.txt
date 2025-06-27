project(ZEN_CORE)

set(CORE_SYSTEMS
    ${CMAKE_CURRENT_SOURCE_DIR}/systems/zen_system.h
    ${CMAKE_CURRENT_SOURCE_DIR}/systems/render.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/systems/render.h
    ${CMAKE_CURRENT_SOURCE_DIR}/systems/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/systems/window.h)

set(CORE_ENGINE ${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/engine.h)

add_library(CORE STATIC ${CORE_SYSTEMS} ${CORE_ENGINE})
target_include_directories(
  CORE PUBLIC STATIC ${CMAKE_CURRENT_SOURCE_DIR}/types/
              ${CMAKE_CURRENT_SOURCE_DIR}/systems/ ${CMAKE_CURRENT_SOURCE_DIR}/)
