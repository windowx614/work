cmake_minimum_required(VERSION 3.22)
project(algorithmusTests)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithmusTests main.cpp sort1.cpp sort1.h test.hpp STLtest.hpp)
