/*
	File: 	NReinas.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 6

*/

#ifndef NREINAS_HPP
#define NREINAS_HPP

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

class NReinas{

	private:
		vector<int> _v;//Vector de enteros en el que almacenamos la columna en la que estaría situada la Reina para cada fila.
	
	public:
	
	
		//Constructor
		
		
		NReinas(int n=8){//Crea el tablero de ajedrez, de tamaño nxn,(de 8x8 por defecto) en el que no hay ninguna Reina colocada aún.
			
			_v.resize(n,0);
		};
		
		
		//Observadores:
		
		
		//Observador de la columna en la que se encuentra situada la Reina en una fila concreta.
		inline int getReina(int pos)const{return _v[pos];};
		
		//Observador del tamaño, del vector de enteros.
		inline int tamanoVector() const{ return _v.size();};
		
		//Comprueba que la Reina colocada en la 'fila' no sea comida por ninguna de las anteriores Reinas.
		bool posicion(int fila);
				
		//Comprueba que la colocación de las Reinas en el Tablero no de problemas(que haya Reinas que se coman entre sí).
		bool esCorrecto();
		
		
		//Modificadores
		
		//Modifica la reina en la posición indicada.
		inline void setReina(int pos,int n){_v[pos]=n;};
		
		//Quita del tablero la Reina que se encuentra en la posición indicada.
		inline void borrarReina(int pos){_v[pos]=0;};
		
		//Quita todas las Reinas del tablero.
		void vaciarTablero();
		
		
		//Sobrecarga de operadores
		
		//Sobrecarga del operador de salida
		friend ostream &operator<<(ostream &salida,const NReinas n);

		//Sobrecarga del operador de asignación.
		inline void operator=(const NReinas &aux){this->_v=aux._v;};
		
};


#endif

//Fin de NReinas.hpp
