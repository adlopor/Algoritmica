/*
	File: 	Entero.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 3

*/

#ifndef ENTERO_HPP
#define ENTERO_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include "funciones.hpp"
using namespace std;


bool esEntero(const string &s);

class Entero{
	
	private:
		
		string _entero;
		int _max;
	public:
	
	//Constructor
	Entero(const string &e, int maximo=4){
	
		setEntero(e);
		setMax(maximo);
		
	};
	
	//Comprueba si el string de la clase esta vacío o no.
	inline bool estaVacio(){
		if(this->_entero.empty()){return true;}	
		else{return false;}
	}
	
	//Devuelve la magnitud mayor de los dos Enteros que se comparan
	inline int magnitudMaxima(const Entero &e){ 
		if( e.getEntero().length() >= this->_entero.length() )
			return e.getEntero().length();
			
		else
			return this->_entero.length();
	};
	
	//Getters & Setters
	inline string getEntero() const{ return this->_entero;};
		
	inline void setEntero(const string &e){
	
		//Comprobamos que la string que vamos a guardar sea entero.
		assert(esEntero(e));
		this->_entero=e;
	};
		
	inline int getMax() const{ return this->_max;};
		
	inline void setMax(const int &max){this->_max=max;};
		
		
	//parte el numero en dos para operar más facilmente.
	void partirCadena (string &cad1, string &cad2);
	
	//Pone ceros a la izquierda.
	void agregarCerosFinal (int nCeros);

	//Pone ceros a la derecha.
	void agregarCerosDelante (int nCeros);
	
	//Quita los ceros a la izquierda.
	void quitarCerosNoSignificativos();
	
	//Agrega tantos ceros a la derecha como la potencia de 10 por la que se esta multiplicando. p.e.: 90ioopo0o10^3 = Agrega 3 ceros. 
	inline void multiplicarPotencia10(int n){agregarCerosFinal(n);}
	
	//Sobrecarga de operadores
	
	friend ostream &operator<<(ostream &salida,const Entero &e);
	
	friend istream &operator>>(istream &entrada, const Entero &e);
	
	inline void operator=(const Entero &e){this->_entero=e._entero;};
	
	Entero operator+(Entero &e);
	
	Entero operator*(Entero &e);
	
	


};

	

#endif
