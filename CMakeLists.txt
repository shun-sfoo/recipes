cmake_minimum_required(VERSION 3.14...3.25)

project(recipes LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(extern/muduo)
include_directories("extern/muduo")

add_subdirectory(echo)
add_subdirectory(finger)
add_subdirectory(reactor)
