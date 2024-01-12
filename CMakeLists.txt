cmake_minimum_required(VERSION 3.24)
project(Cat_in_Space)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cat_in_Space main.cpp)

target_link_libraries(Cat_in_Space -lOpenGL32 -lfreeGLUT -lwinmm)
target_link_libraries(Cat_in_Space -lOpenGL32 -lGLUT32 -lGLU32 -lwinmm)
