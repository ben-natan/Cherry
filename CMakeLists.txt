cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_COMPILER "/usr/bin/g++")

project(Cherry LANGUAGES CXX)

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE CY_FILES src/*)

include_directories(external)
include_directories(Cherry ${SDL2_INCLUDE_DIRS})

add_executable(Cherry ${CY_FILES})

target_link_libraries(Cherry ${SDL2_LIBRARIES})

add_custom_command(TARGET Cherry PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/models/ $<TARGET_FILE_DIR:Cherry>/models)

