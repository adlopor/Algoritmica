/*
	File: 	funciones.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 5

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
	cout << "[1] Algoritmo del cambio:";
	
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
	Función:		cambio
	
	Entrada:	
	
	Salida:		void
	
	Descripción:	Ejecuta el algoritmo del cambio de forma dinámica, usando las clases SistemaMonetario y Moneda, creadas para la resolución de este algoritmo.
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
	cout<<"Introduzca el valor a cambiar (en céntimos):"<<endl;
	cin>>n;
	
	while(n<1){
		cout<<"Error el número ha de ser mayor que cero. Introduzca de nuevo el número:"<<endl;	
		cin>>n;
	}
  
	vector<vector<int>> tablaMonedas;
	
	cambioDinamico(s,n,tablaMonedas);
	
	vector <int> sol;
  
	if(solCambio(tablaMonedas,s,sol)){

		cout<<"Cambio realizado:"<<endl;

		for(int i=0;i<sol.size();i++){
			if(sol[i]!=0)
				cout<<sol[i]<<" "<<s.getMoneda(i).getFormato() <<" de "<<s.getMoneda(i).getValor()<<" céntimos."<<endl;
		}
	}	
	else{//No hay solución
		
		cout<<"No hay solución"<<endl;
		cin.ignore();
	}

	cin.ignore();
};


/*
	Función:		cambioDinamico
	
	Entrada:		s:			Variable de la clase SistemaMonetario.
				n:			número que se ha de cambiar.
				tablaMonedas:	Vector de vectores de enteros, en la que se generará la tabla con los cambios.
	
	Salida:		void
	
	Descripción:	Se genera la tabla de cambios dinámicos.
*/
void cambioDinamico(const SistemaMonetario &s,int n, vector<vector<int>> &tablaMonedas){

	vector<vector<int>> tablaAux(s.tamanoVector(),vector<int>(n+1,0));
	

	for(int i=0;i<tablaAux.size();i++){
	
		for(int j=1;j<tablaAux[i].size();j++){
			
			if((i==0)&&(j<s.getMoneda(i).getValor())){
			
				tablaAux[i][j]=-1; //-1 equivale a infinito
			
			}
			
			else{
				if(i==0){
				
					if(tablaAux[i][j-s.getMoneda(0).getValor()]==-1)
						tablaAux[i][j]=-1;
					else{
						tablaAux[i][j]=1+tablaAux[i][j-s.getMoneda(0).getValor()];  
					}
				}
				
				else{
					
					if(j<s.getMoneda(i).getValor())
					tablaAux[i][j]=tablaAux[i-1][j];
					
					else{
						if(tablaAux[i][j-s.getMoneda(i).getValor()]==-1){
							tablaAux[i][j]=tablaAux[i-1][j];
						}
						else{
							tablaAux[i][j] = min(tablaAux[i-1][j],1+tablaAux[i][j-s.getMoneda(i).getValor()]);
                      		}
					}
				
				}
			}	
		}
	}
	
	tablaMonedas=tablaAux;
	
	/* ----IMPRESIÓN DE LA TABLA----
	
	for (int i=0; i<tablaMonedas.size();i++){
		
		cout<<endl;
		
		for (int j=0; j<tablaMonedas[i].size();j++){
			cout<<" "<<tablaMonedas[i][j]<<" ";
		}
	}
	------------------------------------------*/
};


/*
	Función:		solCambio
	
	Entrada:		tablaMonedas:	Tabla de cambios generada en la función cambioDinamico que usamos para obtener la solución.
				s:			Variable de la clase SistemaMonetario
				sol: 		Vector de enteros dónde guardamos la solución obtenida.
					
	Salida:		bool
	
	Descripción:	Busca en la tabla de cambios generada en el otro método la solución, en caso de que no haya una solución posible, devuelve false. En caso contrario, devuelve true y guarda la solución en el vector de enteros sol.
*/
bool solCambio(const vector<vector<int>> &tablaMonedas,const SistemaMonetario &s,vector<int> &sol){

	vector<int> solucion(tablaMonedas.size(),0);
	int i,j;
	
	i=tablaMonedas.size()-1;
	j=tablaMonedas[i].size()-1;
	
	if(tablaMonedas[i][j]==-1){
		return false;
	}
	
	while(j>0 && i>0){
	 
		if(tablaMonedas[i][j] == tablaMonedas[i-1][j])
			i--;
     	else{
     	
			if( tablaMonedas[i][j]==1+tablaMonedas[i][j-s.getMoneda(i).getValor()]){
				solucion[i]++;
				j=j-s.getMoneda(i).getValor();
			}
		
		}
	}
	
	if(i==0 && tablaMonedas[i][j]==1+tablaMonedas[i][j-s.getMoneda(i).getValor()]){
		solucion[0]+=tablaMonedas[i][j];
	}
	
	sol=solucion;
	return true;

};


/*
	Función:		min
	
	Entrada:		n:	Variable de tipo entero.
				m:	Variable de tipo entero
									
	Salida:		int
	
	Descripción:	Función que devuelve el menor valor de los dos pasados como parámetros de entrada.
*/
int min (int n, int m){
	
	//Si n o m son infinito:
	if(n == -1) return m;
	if(m == -1) return n;
	
	//Si no:
	if(n>m) return m;
	else{ return n;}
};

	
//Fin de funciones.cpp
