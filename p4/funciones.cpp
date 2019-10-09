/*
	File: 	funciones.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 4

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
	cout << "[1] Algoritmo del cambio dinámico:";
	
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
	Función:	cambio
	
	Entrada:	
	
	Salida:		void
	
	Descripción:	Ejecuta el algoritmo del cambio usando las clases SistemaMonetario y Moneda, creadas para la resolución de este algoritmo.
*/
void cambio(){

	SistemaMonetario s;
	string nfich="SistemaMonetario.txt";
	
	/*cout<<"Introduce el fichero con el sistema monetario:"<<endl;
	cin>>nfich;
	*/
   	ifstream fichero;
	
	fichero.open(nfich.c_str());//Se abre el fichero

	//Prueba si el fichero se abrió bien. Si no es así, muestra un mensaje de error y se sale del programa.
	if(!fichero.is_open()){
		cout<<"Error al abrir el fichero. Saliendo del programa..."<<endl;
		cin.ignore();
		return;
	}
	
	fichero>>s;//se guardan los datos del fichero en la clase.
	
	fichero.close();//Se cierra el fichero

	int n;
	cout<<"Introduzca el valor a cambiar:"<<endl;
	cin>>n;
	
	while(n<1){
		cout<<"Error el número ha de ser mayor que cero. Introduzca de nuevo el número:"<<endl;	
		cin>>n;
	}
  
	vector <int> nMonedas;
	vector <Moneda> solucion;
	
	Moneda mAux;
	
	int sol=n;//En esta variable guardamos el valor que queremos cambiar.
	
	int ultimaMoneda = s.getVector()[s.tamanoVector()-1].getValor()+1; //+1 para que no entre siempre en: if(mAux.getValor()<ultimaMoneda){//Almacenamos en la solucion la moneda usada.
	
	while(sol!=0){//No hemos terminado de dar cambio
	
		if(!s.setMaximo(sol)){//No hay en el sistema monetario una moneda menor igual al valor restante por cambiar.
		
			cout<<"El sistema monetario cargado, no tiene una solución para el valor a cambiar."<<endl;
			return;
		}
		
		else{
			mAux=s.getMaximo();//En la moneda auxiliar creada, se guarda el maximo valor a cambiar posible.
			
			sol=sol-mAux.getValor();//Se lo restamos al valor a cambiar y guardamos en sol el valor que queda por cambiar.
			
			if(mAux.getValor()<ultimaMoneda){//Almacenamos en la solucion la moneda usada.
			
				ultimaMoneda=mAux.getValor();
				solucion.push_back(mAux);
				nMonedas.push_back(1);
			}
			else{//Si hemos usado esa moneda en una iteración anterior.
				nMonedas[nMonedas.size()-1]++;
			}
		}
	}  
	
	cout<<"Cambio realizado:"<<endl;

	for(int i=0;i<nMonedas.size();i++)
		cout<<nMonedas[i]<<" "<<solucion[i].getFormato() <<" de "<<solucion[i].getValor()<<endl;

	cin.ignore();
	
};






//Fin de funciones.cpp
