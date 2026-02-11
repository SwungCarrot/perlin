cmake_minimum_required(VERSION 4.0)
project(perlin)

set(CMAKE_CXX_STANDARD 20)
find_package(raylib 5.0 REQUIRED)


add_executable(perlin main.cpp
        Grid.cpp
        Grid.h
        Maths.cpp
        Maths.h
        FVec.h
        FInt.h
        FFloat.h)

target_link_libraries(perlin PRIVATE raylib)