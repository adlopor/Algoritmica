/*
	File: 	Moneda.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 5

*/


#ifndef MONEDA_HPP
#define MONEDA_HPP

#include <iostream>
#include <string>

using namespace std;

class Moneda{
	
	private:

	string _formato;	//Guarda su formato físico, es decir, si es "Moneda" o "Billete".
	int _valor;		//Guarda el valor de la moneda.

	public:
	
	//Observadores:
	
	//Devuelve _formato.
	inline string getFormato() const{return this->_formato;};
	
	//Devuelve _valor.
	inline int getValor() const{return _valor;};
		
		
	//Modificadores:
	
	//Modifica _formato.
	inline void setFormato(string formato){this->_formato=formato;};
	
	//Modifica _valor.
	inline void setValor(int valor){this->_valor=valor;};
	
	
	//Sobrecarga de operadores:
	
	//Operador de comparación
	bool operator==(const Moneda &m) const{
					if(this->_valor==m._valor) return true; return false;}	
	
	//Operador de salida.
	friend  ostream &operator<<(ostream &salida,const Moneda &m);
	
	//Operador de entrada.
	friend  istream &operator>>(istream &entrada,Moneda &m);
        

	
};


#endif

//Fin de Moneda.hpp
