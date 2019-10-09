/*
	File: 	funciones.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 3

*/

#include "funciones.hpp"

using namespace std;

/*
	Función:	menu
	Entrada:	
	Salida:		int
	Descripción:	muestra el menú principal.
*/
int menu(){


	int opcion, posicion;

	// Se muestran las opciones del menú
	posicion=8;

	// Se borra la pantalla
	cout << CLEAR_SCREEN;

	LUGAR(5,10);

	cout << BBLUE;
	cout << "Programa principial | Opciones del menú   ";
	cout << RESET;

	LUGAR(posicion++,10);
	cout << "[1] Suma de dos numeros enteros";

	LUGAR(posicion++,10);
	cout << "[2] Multiplicacion de dos numeros enteros";
	
	LUGAR(posicion++,10);
	cout << GREEN << "[0] Salir";

	LUGAR(posicion++,20);
	cout << IYELLOW;
	cout << "Opción: ";
	cout << RESET;

	// Se lee el número de opción
	cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	cin.ignore();

	return opcion;

};



//----------------------------------------
void sumaEnteros(){

	string num1,num2;
	
	//int tamano;
	
	//Leemos el valor del primer entero y comprobamos que lo sea
	
	cout<<"Introduce el valor del primer entero: "<<endl;
	cin>>num1;
	
	while(!esEntero(num1)){
		
		cout<<"ERROR. la cadena introducida para el primer entero, no es un entero."<<endl;
		
		cout<<"Introduce de nuevo el valor del primer entero: "<<endl;
		cin>>num1;
		
	}
	
	//Leemos el valor del segundo entero y comprobamos que lo sea
	cout<<"Introduce el valor del segundo entero: "<<endl;
	cin>>num2;
	
	while(!esEntero(num2)){
	
		cout<<"ERROR. la cadena introducida para el segundo entero, no es un entero."<<endl;
	
		cout<<"Introduce de nuevo el valor del segundo entero: "<<endl;
		cin>>num2;
	
	}

	Entero n1(num1);
	Entero n2(num2);
	
	Entero resultado("0");
	
	resultado = n1+n2;
	
	cout<<"La suma de los dos valores introducidos es: "<<resultado<<endl;
	
	cin.ignore();

	return;
};




//----------------------------------------
void multiplicacionEnteros(){

	string num1,num2;
	
	int tamano;
	
	//Leemos el valor del primer entero y comprobamos que lo sea
	
	cout<<"Introduce el valor del primer entero: "<<endl;
	cin>>num1;
	
	while(!esEntero(num1)){
		
		cout<<"ERROR. la cadena introducida para el primer entero, no es un entero."<<endl;
		
		cout<<"Introduce de nuevo el valor del primer entero: "<<endl;
		cin>>num1;
		
	}
	
	//Leemos el valor del segundo entero y comprobamos que lo sea
	cout<<"Introduce el valor del segundo entero: "<<endl;
	cin>>num2;
	
	while(!esEntero(num2)){
	
		cout<<"ERROR. la cadena introducida para el segundo entero, no es un entero."<<endl;
	
		cout<<"Introduce de nuevo el valor del segundo entero: "<<endl;
		cin>>num2;
	
	}
	
	cout<<"Introduce el máximo de cifras desde el que dos enteros pueden multiplicarse,(ha de ser como mucho 4, para evitar overflow en la salida del resultado por pantalla)"<<endl;
	cin>>tamano;
	
	Entero i(num1,tamano);
	Entero j(num2,tamano);
	
	Entero res = i*j;
	cout<<"\nEl resultado es: "<<res<<endl;
	cin.ignore();

   
   

}






//Fin de funciones.cpp
