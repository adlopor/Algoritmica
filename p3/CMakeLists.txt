CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P3)

SET(CMAKE_CXX_FLAGS "-lrt -g -std=c++11")
add_executable(a.out main.cpp Entero.cpp funciones.cpp)
