/*
	File: 	SistemaMonetario.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 4

*/

#ifndef SISTEMA_MONETARIO_HPP
#define SISTEMA_MONETARIO_HPP

#include <vector>
#include <iostream>
#include <algorithm> //Para la funcion 'sort' de la std.

#include "Moneda.hpp"


using namespace std;

class SistemaMonetario{

private:

	vector <Moneda> _v;	//Vector de Monedas ordenado en orden creciente de valor. 
	
	int _max;			//Variable de tipo entero que nos servirá para indicar la posición de la moneda con más valor de la que se puede dar cambio.				

public:
	
	//Constructor
	SistemaMonetario(){	this->_max = -1; };
	
	
	//Observadores:
	
	//Observador del tamaño de _v
	inline int tamanoVector() const{ return this->_v.size(); };
	
	//Observador de _v
	inline vector <Moneda> getVector() const{ return this->_v; };
	
	//Observador de _maximo
	inline Moneda getMaximo() const{ return _v[_max]; };
	
	
	//Modificadores:
	
	//Calcula el maximo valor de cambio que puede dar, dentro de las monedas pertenecientes al vector.
	bool setMaximo(int n);
	
	//Ordena el vector en orden creciente.
	inline void ordenarVector(){ sort(_v.begin(),_v.end(),sortMonedas);};
	
	//Comprueba si la moneda esta en el vector.
	bool existeMoneda(const Moneda m);
	
	//Inserta una moneda nueva en el vector y lo ordena.
	void insertarMoneda(Moneda m);
	
	//Borra una moneda perteneciente al vector.
	bool borrarMoneda(const Moneda m);


	//Sobrecarga de operadores:
	
	//Operador de salida.
	friend  ostream &operator<<(ostream &salida,const SistemaMonetario &s);
	
	//Operador de entrada.
	friend  istream &operator>>(istream &entrada,SistemaMonetario &s);


	static bool sortMonedas(Moneda i,Moneda j){return i.getValor()<j.getValor();}




};

#endif

//Fin de SistemaMonetario.hpp
