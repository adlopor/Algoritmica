/*
	File: 	Moneda.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 5

*/


#include "Moneda.hpp"

using namespace std;


/*
Función:	operator<<

Entrada:	salida: flujo de salida(ostream)
		m: objeto de la clase Moneda.

Salida:		ostream

Descripción:	Muestra por el flujo de salida el valor del objeto m, de la clase Moneda pasado como parámetro de entrada.
*/
ostream &operator<<(ostream &salida,const Moneda &m){
	
	//Mostramos el valor de la moneda.
	salida<<m.getValor();
	return salida;
};


/*
Función:	operator>>

Entrada:	entrada: flujo de entrada(istream).
		m: objeto de la clase Moneda.

Salida:		istream

Descripción:	Lee del flujo de entrada los valores introducidos para rellenar m, y los almacena en dicho objeto, comprobando previamente que la lectura del flujo se ha realizado con éxito.
*/
istream &operator>>(istream &entrada,Moneda &m){

	string cadena;
	//Guardamos en cadena el flujo de entrada hasta encontrar un espacio.
	getline(entrada,cadena,' ');
	
	//Si la cadena no esta vacía, guardamos lo obtenido (el valor) en la clase.
	if(!cadena.empty())
		m._valor=stoi(cadena);
		
	//Leemos la linea del flujo de entrada hasta encontrar un salto de linea y lo guardamos en cadena(machaca lo anterior).
	getline(entrada,cadena,'\n');
	
	//Si la cadena no esta vacía, guardamos lo obtenido (el formato) en la clase.
	if(!cadena.empty())
		m.setFormato(cadena);
	
	return entrada;
};

//Fin de Moneda.cpp
