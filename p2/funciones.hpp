/*
	File: 	funciones.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 2
*/

#ifndef _FUNCIONES_HPP_
#define _FUNCIONES_HPP_

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <tgmath.h>
#include "ClaseTiempo.cpp"
#include "funcionesMinimosCuadrados.hpp"
#include "sistemaEcuaciones.hpp"
#include "macros.hpp"


using namespace std;


	/*	-----Funciones Principales-----	*/
	
		
	//Función del menú.
	int menu();
	
	//Función del menú de las distintas formas implementadas para calcular los números combinatorios.
	void menuNumerosCombinatorios();
	
	//Función principal que realiza los calculos de los números combinatorios de forma recursiva.
	void combinatoriosRecursivos();
	
	//Función principal que realiza los calculos de los números combinatorios de forma recursiva, usando una tabla de valores.
	void combinatoriosRecursivosConTabla();
	
	//Función principal que realiza los calculos de los números combinatorios de forma iterativa.
	void combinatoriosIterativos();
	
	//Función principal que realiza los cálculos del número de movimientos necesarios para resolver el problema de "Las Torres de Hanoi".
	void mainHanoi();
	
	
	/*	-----Funciones Auxiliares Números Combinatorios-----	*/


	//Funcion que calcula el numero combinatorio recursivamente
	long double combinatorioRecurAux(long double m, long double n);
	
	//Funcion que calcula el numero combinatorio recursivamente buscando previamente en una tabla de valores
	long double combinatorioRecurTablaAux(long double m, long double n, vector<vector<long double>> &tabla);
	
	//Funcion que calcula el numero combinatorio iterativamente 
	long double combinatorioIterAux(long double m, long double n);


	/*	-----Funciones Auxiliares Hanoi-----	*/
	
	
	void hanoi(vector<vector<int>> &torres, int n, int i, int j, int &movimientos);
	
	void imprimirHanoi(const vector<vector<int>> &torres);
	
		
	/*	------------------------------------	*/
	
	
// Fin de _FUNCIONES_HPP_
#endif

