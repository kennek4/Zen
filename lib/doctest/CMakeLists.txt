project(ZEN_DOCTEST)

add_library(DOCTEST INTERFACE)
target_include_directories(DOCTEST INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
