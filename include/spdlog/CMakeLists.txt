project(ZEN_SPDLOG)

add_library(SPDLOG INTERFACE)
target_include_directories(SPDLOG INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

