/*
	File: 	NReinas.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 6

*/

#include "NReinas.hpp"

using namespace std;


//----- OBSERVADORES DE LA CLASE NREINAS -----


/*
Función:		posicion

Entrada:		fila: variable de tipo entero que indica la fila del tablero (o elemento del vector), que se va a comprobar que sea correcto.
	
Salida:		bool

Descripción:	Comprueba que la Reina colocada en la 'fila' no sea comida por ninguna de las anteriores Reinas.
*/
bool NReinas::posicion(int fila){
	
	for(int j=0;j<fila;j++){//Comprueba que la reina de la fila 'fila', no este ni en vertical, ni en diagonal con el resto de Reinas ya introducidas.
		
		if(_v[j]==_v[fila] || abs(_v[j]-_v[fila])==abs(j-fila)) return false; 
	}
	
	return true;
};


/*
Función:		esCorrecto

Entrada:	

Salida:		bool

Descripción:	Comprueba que la colocación de las Reinas en el Tablero no de problemas(que haya Reinas que se coman entre sí).
*/
bool NReinas::esCorrecto(){

	for(int i=1;i<tamanoVector();i++){
		for(int j=0;j<tamanoVector();j++){	
		
			if(_v[i] == _v[j] || _v[i]==_v[j]-(i-j) || _v[i]==_v[j]+(i-j))
				return false;
				 
		}
	}
	return true;
};


//----- MODIFICADORES DE LA CLASE NREINAS -----


/*
Función:		vaciarTablero

Entrada:	

Salida:		void

Descripción:	Quita todas las Reinas del tablero, (dejando el tablero vacío).
*/
void NReinas::vaciarTablero(){

	for(int i=0;i<this->tamanoVector();i++)
		_v[i]=0;

};


//----- SOBRECARGA DE OPERADORES DE LA CLASE NREINAS -----


/*	
Función:		operator<<

Entrada:	

Salida:		ostream

Descripción:	Sobrecarga del operador de salida para objetos pertenecientes a la clase NReinas.
*/
ostream &operator<<(ostream &salida,const NReinas n){
	
	for(int i=0;i<n.tamanoVector();i++){
		salida<<n._v[i]<<" ";
	}
	
	return salida;
};


//Fin de NReinas.cpp
