CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(P1)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
add_executable(a.out main.cpp ClaseTiempo.cpp funciones.cpp funcionesMinimosCuadrados.cpp sistemaEcuaciones.cpp)
