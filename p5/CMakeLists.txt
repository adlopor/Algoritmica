CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P5)

set (CMAKE_CXX_FLAGS "-lrt -g -std=c++11")
add_executable(a.out main.cpp funciones.cpp Moneda.cpp SistemaMonetario.cpp)
