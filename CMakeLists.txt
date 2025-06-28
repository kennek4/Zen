# Project Setup
cmake_minimum_required(VERSION 3.12..4.0.1)
project(
  ZEN_CMAKE
  VERSION 0.1.0
  DESCRIPTION "A 2D game engine made by kennek4"
  LANGUAGES CXX)

set(ZEN_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# ##############################################################################
# DIRECTORIES #
# ##############################################################################
add_subdirectory(engine)
add_subdirectory(editor)
