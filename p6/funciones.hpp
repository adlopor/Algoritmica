/*
	File: 	funciones.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 6
*/

#ifndef _FUNCIONES_HPP_
#define _FUNCIONES_HPP_


#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

#include "NReinas.hpp"
#include "macros.hpp"


using namespace std;
	
	
	//Función del menú.
	int menu();
	
	//Menú del algoritmo que calcula por backtraking las N Reinas.
	void menuBTNReinas();
	
	//Algoritmo que calcula por backtracking las N Reinas.
	void btNreinas(vector<NReinas> &sol,int n);	
	
	//Menú del algoritmo de LasVegas que calcula las N Reinas.
	void menuLasVegasNReinas();
	
	//Algoritmo de LasVegas que calcula las N Reinas. 
	bool LasVegasNReinas(NReinas &solucion,int n);

	
	
// Fin de _FUNCIONES_HPP_
#endif

//Fin de funciones.hpp
