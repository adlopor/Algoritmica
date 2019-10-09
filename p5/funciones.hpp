/*
	File: 	funciones.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 5
*/

#ifndef _FUNCIONES_HPP_
#define _FUNCIONES_HPP_

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <assert.h>

#include "Moneda.hpp"
#include "SistemaMonetario.hpp"
#include "macros.hpp"


using namespace std;

	
		
	//Función del menú.
	int menu();
	
	//Función de la opción a) de la práctica.
	void cambio();
	
	//Función que genera la tabla de cambios para el valor introducido.
	void cambioDinamico(const SistemaMonetario &s,int n, vector<vector<int>> &v);
	
	//Función que obtiene la solución (si es posible), buscando en la tabla generada en la función anterior.
	bool solCambio(const vector<vector<int>> &tablaMonedas,const SistemaMonetario &s,vector<int> &sol);
	
	//Función que devuelve el valor menor de los introducidos como parámetros de entrada.
	int min(int n,int m);
	
// Fin de _FUNCIONES_HPP_
#endif

//Fin de funciones.hpp
