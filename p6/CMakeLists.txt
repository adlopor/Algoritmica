CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P6)

set (CMAKE_CXX_FLAGS "-lrt -g -std=c++11")
add_executable(a.out main.cpp funciones.cpp NReinas.cpp)
