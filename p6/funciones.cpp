/*
	File: 	funciones.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 6

*/

#include "funciones.hpp"

using namespace std;


/*
	Función:		menu
	
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
	cout << "[1] Cálculo de las n Reinas por Backtracking:";
	
	LUGAR(posicion++,10);
	cout << "[2] Cálculo de las n Reinas por el Algoritmo de Las Vegas:";
	
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


/*
	Función:		menuBTNReinas
	
	Entrada:	
	
	Salida:		void
	
	Descripción:	Muestra el menú del algoritmo que calcula por backtraking las N Reinas.
*/
void menuBTNReinas(){

	int n;//Número de Reinas
	cout<<"Introduce el número de Reinas. (Consejo:Introduce un número de Reinas superior a 3): ";	
	cin>>n;

	while (n<=3){
		cout<<"Error, el número de reinas introducido no es válido. Ha de introducir de nuevo el número de Reinas, (que sean más de 3 Reinas por favor): "<<endl;	
		cin>>n;
	}
	vector<NReinas> sol;//Vector en el que almacenamos las soluciones que obtendremos al realizar el algoritmo de calcular las N Reinas por backtracking.
	
	btNreinas(sol,n);//Llamamos a la función que calcula las N Reinas por el método de Backtracking.
	
	for(int i=0;i<sol.size();i++)//Imprimimos las soluciones obtenidas
		cout<<sol[i]<<endl;

	
	cin.ignore();
	cin.ignore();
};


/*
	Función:		btNReinas
	
	Entrada:		sol: Vector de objetos de la clase NReinas, en el que se almacenan todas las posibles soluciones al problema de las NReinas resuelto por Backtracking.
				n: 	Variable entera que representa el número de Reinas.
	
	Salida:		void
	
	Descripción:	Algoritmo que calcula por backtracking las N Reinas.
*/
void btNreinas(vector<NReinas> &sol,int n){

	sol.clear();//Limpiamos el vector de soluciones por si tenemos almacenado otra solución de una llamada anterior.
	
	NReinas aux(n);
	int i=0;//Variable para recorrer el vector de las soluciones (las filas del tablero).
		
	while(i >= 0){

		aux.setReina(i,aux.getReina(i)+1);//Se pone a la reina en la primera casilla

		while(aux.getReina(i) <= n && !aux.posicion(i)){//Si la reina esta dentro del tablero y es comida por las anteriores reinas, pone la reina en la siguiente casilla.
			
			aux.setReina(i,aux.getReina(i) + 1);
		}
		
		if(aux.getReina(i) <= n){//Una vez encontrada una casilla óptima para la i-esima reina
			
			if(i == n-1){//Si es la ultima a colocar se guarda la solución.
				sol.push_back(aux);
				
			}
			
			else{
				i++;
				aux.setReina(i,0);
			}

		}
		else{i--;}//Si no se encontrase solución óptima para la i-esima reina se hace backtracking.
	
	}
};


/*
	Función:		menuLasVegasNReinas
	
	Entrada:	
	
	Salida:		void
	
	Descripción:	Muestra el menú del algoritmo de LasVegas que calcula las N Reinas.
*/
void menuLasVegasNReinas(){
	
	int n;//Número de Reinas
	int numPruebas = 1;//Es el número de pruebas realizadas.
	
	srand(time(NULL));//Se requiere para la función que hace el algoritmo de LasVegas.
	
	cout<<"Introduce el número de Reinas. (Consejo:Introduce un número de Reinas superior a 3): ";	
	cin>>n;

	while (n<=3){
	
		cout<<"Error, el número de reinas introducido no es válido. Ha de introducir de nuevo el número de Reinas, (que sean más de 3 Reinas por favor): "<<endl;	
		cin>>n;
	}
	
	NReinas prueba;
	
	bool exito = LasVegasNReinas(prueba,n);
	while(!exito){
		exito = LasVegasNReinas(prueba,n);
		numPruebas++;
	}
	
	cout<<"Esta solucion ha sido sacada tras "<<numPruebas<<" pruebas:\n";
	cout<<prueba<<endl; 
	
	cin.ignore();
	cin.ignore();
};


/*
	Función:		LasVegasNReinas
	
	Entrada:		sol: Objeto de la clase NReinas en el que se almacena la solución para el problema de las NReinas.
				n:	Variable entera que representa el número de Reinas.
	
	Salida:		void
	
	Descripción:	Algoritmo de LasVegas que calcula las N Reinas. 
*/
bool LasVegasNReinas(NReinas &sol,int n){

	NReinas aux(n);
	vector <int> ok;
	int contador;
	
	for(int i=0;i<n;i++){
		contador=0;
		
		for(int j=0;j<n;j++){//Prueba a colocar en todas las casillas a la reina. 
	
			aux.setReina(i,j+1);
	
			if(aux.posicion(i)){//En caso de que dicha posicion sea correcta se guarda en el vector.
				contador++;
				ok.push_back(j+1);
			}
		}
		
		if(contador==0)//Si no encuentra ninguna posicion adecuada para la Reina en la fila i devuelve false
			return false;
		
		aux.setReina(i,ok[rand()%ok.size()]);//Pone a la reina i-esima en una de las posiciones válidas de forma aleatoria.
		ok.clear();//Se borran las posiciones validas.
	}
	
	if(contador==0)//Comprobamos fuera de los bucles, (por si acaso, ya que se comprueba en cada iteración del segundo bucle anidado) si se ha encontrado una posición válida para la Reina.
		return false;  
	
	sol=aux;//Guardamos la solución obtenida y salimos de la función.
	
	return true;
};


//Fin de funciones.cpp
