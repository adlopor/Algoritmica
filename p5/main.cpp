/*
	File: 	main.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 4

*/

#include <stdio.h>
#include <string>

#include "SistemaMonetario.hpp"
#include "funciones.hpp"
#include "macros.hpp"


int main(){

	int opcion;
	srand(time(NULL));
	
	do{

		// Se elige la opción del menún
		opcion = menu();		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;
			break;

			case 1: 
				std::cout << "[1] Algoritmo de obtención del cambio:" << std::endl;
				cambio();
				break;

			default:
			    LUGAR(25,25);
					std::cout << INVERSE;
					std::cout << "Opción incorrecta ";
					std::cout << RESET;
			  	std::cout << RED;
					std::cout << " --> " << opcion << std::endl;
					std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		 LUGAR(30,25);
		 std::cout << "pulse ";
		 std::cout << UNDERLINE;
		 std::cout << IYELLOW;
		 std::cout << "ENTER";
		 std::cout << RESET;
		 std::cout << " para ";
		 std::cout << INVERSE;
		 std::cout << "continuar"; 
		 std::cout << RESET;
		 getchar();
		 std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}

