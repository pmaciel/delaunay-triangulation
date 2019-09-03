cmake_minimum_required(VERSION 3.0)

project(delaunay-triangulation LANGUAGES CXX)

add_library(delaunay-triangulation dt/delaunay.cpp dt/edge.cpp dt/numeric.cpp dt/triangle.cpp dt/vector2.cpp)
target_include_directories(delaunay-triangulation PUBLIC include)

add_executable(tests tests/tests.cpp)
target_link_libraries (tests delaunay-triangulation)

