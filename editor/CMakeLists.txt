project(
  Zenith
  VERSION 0.1.0
  DESCRIPTION "A 2D game engine editor")

# ##############################################################################
# ###### Main Program Exec #####################################################
# ##############################################################################

add_executable(Zenith src/Zenith.cpp)
target_link_directories(Zenith PRIVATE src)
target_link_libraries(Zenith PRIVATE ZenEngine)
set_target_properties(Zenith PROPERTIES OUTPUT_NAME "Zenith")
