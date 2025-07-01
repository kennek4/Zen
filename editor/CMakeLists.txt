project(ZenEditor)

# ##############################################################################
# ###### Main Program Exec #####################################################
# ##############################################################################
add_executable(ZEN src/main.cpp)
set_target_properties(ZEN PROPERTIES OUTPUT_NAME "Zen" VERSION 0.1.0)

target_link_directories(ZEN PRIVATE src)
target_link_libraries(ZEN PRIVATE ZenEngine)
