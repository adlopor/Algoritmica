/*
	File: 	SistemaMonetario.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 5

*/

#include "SistemaMonetario.hpp"

using namespace std;


/*
Función:	setMáximo

Entrada:	n: variable de tipo entero, que representa la cantidad de la que se ha de proporcionar cambio.

Salida:		bool

Descripción:	Señala con la variable _max, la moneda más alta con la que se puede dar cambio al valor n, introducido como parámetro de entrada. En caso de no poder dar cambio devuelve false.
*/
bool SistemaMonetario::setMaximo(int n){

	this->_max=-1;

	for(int i = this->_v.size()-1; i>-1; i--){

		if(this->_v[i].getValor() <= n){
			this->_max = i;
			return true;
		}
	}
	return false;
};


/*
Función:	existeMoneda

Entrada:	m: objeto de la clase Moneda.

Salida:		bool

Descripción:	Comprueba si existe una moneda m, perteneciente a la clase SistemaMonetario.
*/
bool SistemaMonetario::existeMoneda(const Moneda m){

	for(int i = 0; i<this->_v.size(); i++){
	
		if(this->_v[i] == m)
			return true;	
	}

	return false;
}


/*
Función:	insertarMoneda

Entrada:	m: objeto de la clase Moneda.

Salida:		void

Descripción:	Inserta una moneda m en la clase SistemaMonetario, previo comprobación de que dicha moneda no se encuentra ya en la clase.
*/
void SistemaMonetario::insertarMoneda(Moneda m){

	if(!existeMoneda(m)){
		
		_v.push_back(m);
		ordenarVector();
	}
	else{
		cout<<"CLASE SistemaMonetario->Funcion insertarMoneda: Esta moneda ya esta insertada por lo que no es necesario insertarla."<<endl;
	}
};


/*
Función:	borrarMoneda

Entrada:	m: objeto de la clase Moneda.

Salida:		bool

Descripción:	Borra una moneda m, de la clase SistemaMonetario, en el caso de que esta existiese en la clase.
*/
bool SistemaMonetario::borrarMoneda(const Moneda m){

	if(existeMoneda(m)){
	
		for(int i=0;i<_v.size();i++){

			if(m==_v[i]){
				_v.erase(_v.begin() + i);
				return true;
			}
		
		}
	}
	else{return false;}

};


/*
Función:	operator<<

Entrada:	salida: flujo de salida(ostream)
		s: objeto de la clase SistemaMonetario.

Salida:		ostream

Descripción:	Muestra por el flujo de salida el valor del objeto s, de la clase SistemaMonetario pasado como parámetro de entrada.
*/
ostream &operator<<(ostream &salida,const SistemaMonetario &s){

		for(int i=0;i<s._v.size();i++)     
			salida<<i<<" : "<<s._v[i]<<endl;
		
		return salida;
};


/*
Función:	operator>>

Entrada:	entrada: flujo de entrada(istream).
		s: objeto de la clase SistemaMonetario.

Salida:		istream

Descripción:	Lee del flujo de entrada los valores introducidos para rellenar s, y los almacena en dicho objeto.
*/
istream &operator>>(istream &entrada,SistemaMonetario &s){

	Moneda m;
		
	while(entrada>>m)
		s.insertarMoneda(m);
		
	return entrada;
	
};


//Fin de SistemaMonetario.cpp
