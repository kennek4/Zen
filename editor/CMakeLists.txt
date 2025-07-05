project(
  ZenEditor
  VERSION 0.1.0
  DESCRIPTION "A 2D game engine editor")

# ##############################################################################
# ###### Main Program Exec #####################################################
# ##############################################################################
add_executable(ZEN src/main.cpp)
target_link_directories(ZEN PRIVATE src)
target_link_libraries(ZEN PRIVATE ZenEngine)
set_target_properties(ZEN PROPERTIES OUTPUT_NAME "ZenEditor-v0.1.0")
