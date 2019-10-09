/*
	File: 	funciones.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 2

*/

#include "funciones.hpp"


///////////////////////////////////////////////////////////////////////////////////////////////

/* ----------------------------------FUNCIONES PRINCIPALES---------------------------------- */


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
	cout << "[1] Calcular numeros combinatorios";

	LUGAR(posicion++,10);
	cout << "[2] Calculo de movimientos de la torre de Hanoi";

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
	Función:	menuNumerosCombinatorios
	Entrada:	
	Salida:		int
	Descripción:	muestra el menú de la elección 1 del menú principal.
*/
void menuNumerosCombinatorios(){
	
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=8;

	// Se borra la pantalla
	cout << CLEAR_SCREEN;

	LUGAR(5,10);
	
	cout << BBLUE;
	cout << "Calculo numero combinatorio | Opciones del menú";
	cout << RESET;

	LUGAR(posicion++,10);
	cout <<  "[1] Calcular numeros combinatorios de forma recursiva";

	LUGAR(posicion++,10);
	cout << "[2] Calcular numeros combinatorios de forma recursiva con tabla";
	
	LUGAR(posicion++,10);
	cout << "[3] Calcular numeros combinatorios de forma iterativa";

	LUGAR(posicion++,10);
	cout << GREEN << "[0] Volver al menu principal";
	
	LUGAR(posicion++,20);
	cout << IYELLOW;
	cout << "Opción: ";
	cout << RESET;

	// Se lee el número de opción
	cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	cin.ignore();
	
	
	switch(opcion){
		
		case 0:
		cout << "Saliendo del programa"<< endl;
		break;
 
		case 1: 
		combinatoriosRecursivos(); 
		break;

		case 2:
		combinatoriosRecursivosConTabla();
		break;        
 
		case 3:
		combinatoriosIterativos();
		break;

		default:
		LUGAR(25,25);
		cout << INVERSE;
		cout << "Opción incorrecta ";
		cout << RESET;
		cout << RED;
		cout << " --> " << opcion << endl;
		cout << RESET;
         
	}

};



/*
	Función:	combinatoriosRecursivos
	Entrada:
	Salida:		void
	Descripción	Función principal que realiza los calculos de los números combinatorios de forma recursiva.
*/
void combinatoriosRecursivos(){ 

	Clock time;
	int n,rep;
  
	cout<<endl<<"Introduce el valor de n:";
	cin>>n;
	
	if(n < 1){
		cout<<"FUNCION combinatoriosRecursivos: El numero n ha de ser mayor que cero. Saliendo del programa..."<<endl;
		return;
	}
	
	cout<<"Introduce el numero de repeticiones:";
	cin>>rep;
	
	if( rep<1 ){
		cout<<"FUNCION combinatoriosRecursivos: El numero de repeticiones ha de ser mayor que cero. Saliendo del programa..."<<endl;
		return;
	}

	vector<double> tiempo_recursivo;
	tiempo_recursivo.resize(n,0);

	vector<double> muestra_recursivo;
	muestra_recursivo.resize(n,0);
	double tiempoPasado=0;
 
	for(int i=1; i <= n; i++){ 
		muestra_recursivo[i-1] = i;
		tiempoPasado = 0;
	
		for(int j=0; j < rep; j++){
			time.start();
	
			for(int k=0; k <= i; k++)    
				combinatorioRecurAux(i,k);

			if (time.isStarted()){
				time.stop();
				tiempoPasado+=time.elapsed();
         		}
       
       		}
		tiempo_recursivo[i-1] = tiempoPasado/rep;
    
	}
	
	vector<double> muestra_recursivo2(n,0);
	vector<double> tiempo_estimado(n,0);
	
	for(int i=0; i<n; i++){
		muestra_recursivo2[i] = pow(2,muestra_recursivo[i]);
	}
	
	vector<vector<double>> sol = calcularMinimosCuadrados(muestra_recursivo2, tiempo_recursivo,2);//Grado 2 = O(2^n), en este caso ya que hace un árbol debido a la recursividad.
	
	ofstream file;
	file.open("combinatoriosRecursivos.txt");

	for(int i=0; i<n; i++){ 
		tiempo_estimado[i] = sol[0][0] + ( sol[1][0] * pow(2,muestra_recursivo[i]) );
		file<<muestra_recursivo[i]<<" "<<tiempo_recursivo[i]<<" "<<tiempo_estimado[i]<<endl;
	}

	file.close();
	cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo_recursivo)<<endl;
	cin.ignore();
	system("../graficaCombinatoriosRecursivos.sh");

	double valor=1;

	while(valor!=0){
		cout<<"\nIntroduce valor para estimar(n=0,salir):";
		cin>>valor;
		long double anos = ( sol[0][0] + (sol[1][0] * pow(2,valor)) ) / (3,1536*pow(10,13));
		
		cout<<"La estimacion del tiempo para ese valor es "<<anos<<" en años"<<endl;
	}


};



/*
	Función:	combinatoriosRecursivosConTabla
	Entrada:
	Salida:		void
	Descripción	Función principal que realiza los calculos de los números combinatorios de forma recursiva, usando una tabla de valores.
*/
void combinatoriosRecursivosConTabla(){

	Clock time;
	int n,rep;
  
	cout<<endl<<"Introduce el valor de n:";
	cin>>n;
	
	if(n < 1){
		cout<<"FUNCION combinatoriosRecursivosConTabla: El numero n ha de ser mayor que cero. Saliendo del programa..."<<endl;
		return;
	}
	
	cout<<"Introduce el numero de repeticiones:";
	cin>>rep;
	
	if( rep<1 ){
		cout<<"FUNCION combinatoriosRecursivosConTabla: El numero de repeticiones ha de ser mayor que cero. Saliendo del programa..."<<endl;
		return;
	}

	vector<double> tiempo_recursivo_con_tabla;
	tiempo_recursivo_con_tabla.resize(n,0);

	vector<double> muestra;

	muestra.resize(n,0);
	double tiempoPasado=0;
 
	for(int i=1; i<=n; i++){ 
		
		 muestra[i-1] = i;
		tiempoPasado = 0;
	
		for(int j=0; j<rep; j++){
		
			vector<vector<long double>> tabla(i+1, vector<long double>(i+1,0));
		        time.start();
		
			for(int k=0;k<=i;k++)
				combinatorioRecurTablaAux(i,k,tabla);
			
				if ( time.isStarted() ){
				
					time.stop();
					tiempoPasado += time.elapsed();
				
				}
       
		}

		tiempo_recursivo_con_tabla[i-1] = tiempoPasado/rep;
		
    
	}
	
	vector<double> tiempo_estimado(n,0);
	
	vector<vector<double>> sol = calcularMinimosCuadrados(muestra, tiempo_recursivo_con_tabla,3);//Grado 3 = O(n^2)
	
	ofstream file;
	file.open("combinatoriosRecursivosConTabla.txt");
	
	for(int i=0;i<n;i++){ 
		tiempo_estimado[i] = calcularValorAprox(muestra[i],sol,3);
		file<<muestra[i]<<" "<<tiempo_recursivo_con_tabla[i]<<" "<<tiempo_estimado[i]<<endl;
	}
	file.close();
	
	cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo_recursivo_con_tabla)<<endl;
	system("../graficaCombinatoriosRecursivosConTabla.sh");

	double valor=1;

	while(valor!=0){

	cout<<"\nIntroduce valor para estimar(n=0,salir):";
	cin>>valor;
	cout<<"La estimacion del tiempo para ese valor es "<<calcularValorAprox(valor,sol,3)<<" en mcs"<<endl;

	}

};



/*
	Función:	combinatoriosIterativos
	Entrada:
	Salida:		void
	Descripción	Función principal que realiza los calculos de los números combinatorios de forma iterativa.
*/
void combinatoriosIterativos(){

	Clock time;
	int n,rep;
  
	cout<<endl<<"Introduce el valor de n:";
	cin>>n;
	
	if(n < 1){
		cout<<"FUNCION combinatoriosIterativos: El numero n ha de ser mayor que cero. Saliendo del programa..."<<endl;
		return;
	}
	
	cout<<"Introduce el numero de repeticiones:";
	cin>>rep;
	
	if( rep<1 ){
		cout<<"FUNCION combinatoriosIterativos: El numero de repeticiones ha de ser mayor que cero. Saliendo del programa..."<<endl;
		return;
	}

	vector<double> tiempo_iterativo;
	tiempo_iterativo.resize(n,0);

	vector<double> muestra;
	muestra.resize(n,0);

	double tiempoPasado=0;
 
	for(int i=1; i <= n; i++){ 

		muestra[i-1] = i;
		tiempoPasado=0;

		for(int j=0; j<rep; j++){
			
			for(int k=1; k<=i; k++){
				time.start();
	
				combinatorioIterAux(i,k);
				
				if (time.isStarted()){
					time.stop();
					tiempoPasado += time.elapsed();
				}
			}
		}
		
		tiempo_iterativo[i-1] = tiempoPasado/rep;
	
	}
	
	vector<double> tiempo_estimado(n);
	vector<vector<double>> sol = calcularMinimosCuadrados(muestra, tiempo_iterativo,3);//Grado 3 = O(n^2)

	ofstream file;
	file.open("combinatoriosIterativos.txt");
	
	for(int i=0; i<n; i++){
	
		tiempo_estimado[i] = calcularValorAprox(muestra[i], sol,3);       
	
		file<<muestra[i]<<" "<<tiempo_iterativo[i]<<" "<<tiempo_estimado[i]<<endl;
	}
     
	file.close();
 
	system("../graficaCombinatoriosIterativos.sh");
	cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo_iterativo)<<endl; 

	double valor=1;
	while(valor!=0){
	
		cout<<"\nIntroduce valor para estimar(n=0,salir):";
		cin>>valor;
		cout<<"La estimacion del tiempo para ese valor es "<<calcularValorAprox(valor,sol,3)<<" en mcs"<<endl;
	
	}

};



/*
	Función:	mainHanoi
	Entrada:
	Salida:		void
	Descripción	Función principal que realiza los cálculos del número de movimientos necesarios para resolver el problema de "Las Torres de Hanoi".
*/
void mainHanoi(){

	Clock time;
	int n,k=0;
  
	cout<<"Introduce el valor de n:";
	cin>>n;

	if(n < 1){
		cout<<"FUNCION mainHanoi: El numero n ha de ser mayor que cero. Saliendo del programa..."<<endl;
		return;
	}
	
	vector<double> tiempo;
	tiempo.resize(n,0);

	vector<double> muestra;
	muestra.resize(n,0);
	
	double tiempoPasado=0;
 
	
	for(int i=1; i<=n; i++){
	
		muestra[k] = i;

		int movimientos = 0;
		tiempoPasado = 0;

		vector<vector<int>> torres(3);
		
		for(int j=i; j>0; j--)
			torres[0].push_back(j);
			
		cout<<"Solución de Hanoi para "<<i<<" elementos:"<<endl;
		imprimirHanoi(torres);

		time.start();

		hanoi(torres,i,1,2,movimientos);

		if (time.isStarted()){
			time.stop();
			tiempoPasado += time.elapsed();
		}
		
		tiempo[k] = tiempoPasado;
		
		k++;
	}

	vector<double> muestra2(n,0);
	vector<double> tiempo_estimado(n,0);

	for(int i=0; i<n; i++)
		muestra2[i] = pow(2, muestra[i]);
		
	vector<vector<double>> sol = calcularMinimosCuadrados(muestra2, tiempo,2);//Grado 2 = O(2^n), en este caso ya que hace un árbol debido a la recursividad.
 
	ofstream file;
	file.open("torresHanoi.txt");
	
	for(int i=0; i<tiempo.size(); i++){ 
	
	tiempo_estimado[i] = sol[0][0] + ( sol[1][0]*pow(2, muestra[i]) );
	file<<muestra[i]<<" "<<tiempo[i]<<" "<<tiempo_estimado[i]<<endl;
	
	}

	file.close();

	cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado, tiempo)<<endl;
	cin.ignore();
	
	system("../graficaTorresHanoi.sh");

	double valor=1;

	while(valor!=0){
		cout<<"\nIntroduce valor para estimar(n=0,salir):";
		cin>>valor;
		long double anos=( sol[0][0] + ( sol[1][0]*pow(2, valor) ) ); //microsegundos double.
				
		
		cout<<"La estimacion del tiempo para ese valor es "<<anos<<" años"<<endl;
	}

};




/////////////////////////////////////////////////////////////////////////////////////////////////////

/* ----------------------------------FUNCIONES AUXILIARES HANOI---------------------------------- */


/*
	Función:		hanoi
	Entrada:		torres: vector de vectores donde almaceno las varillas y el status de cadad una (el numero de discos, ya que es int)
				n:numero de discos
				i:torre origen
				j:torre destino
				movimientos: numeros de movimientos que lleva actualmente el algoritmo (por eso es referencia)
	Salida:		void
	Descripción:	Función auxiliar que calcula el número de movimientos realizados al resolver el problema de "Las Torres de Hanoi".
*/
void hanoi(vector<vector<int>> &torres, int n, int i, int j, int &movimientos){
 
	if(n>0){
	
		hanoi(torres,n-1,i,6-i-j,movimientos);  
		
		torres[j-1].push_back( torres[i-1].back() );
		torres[i-1].resize( torres[i-1].size() - 1 );
		
		movimientos++;
		
		imprimirHanoi(torres);
		
		hanoi(torres,n-1,6-i-j,j,movimientos); 
	}

};


/*
	Función:		imprimirHanoi
	Entrada:		torres: vector 
	Salida:		void
	Descripción:	Función auxiliar que imprime la situación actual del problema de "Las Torres de Hanoi".
*/
void imprimirHanoi(const vector<vector<int>> &torres){

	string cadena;
	int n=0;
	
	for(int i=0; i<torres.size(); i++)
		n += torres[i].size();
		
	cadena += "            |                        |                        |            \n";
	
	for(int i=n; i>=0; i--){
	
		for(int j=0; j<torres.size(); j++){
		
			if(torres[j].size()>i){
				for (int k=0; k<12-torres[j][i]; k++)
					cadena+=" ";
					
				for (int k=0; k<torres[j][i]*2+1; k++)
					cadena += "-"; 
				
				for (int k=0; k<12-torres[j][i]; k++)
					cadena += " ";
			}
			
			else{
					    //12 espacios | 12 espacios
				cadena += "            |            ";
	
			}
		}
		cadena += "\n            |                        |                        |            \n";
	
	}
			 
	cadena += "___________________________________________________________________________\n\n";
	
	//Imprimimos el troncho	
	cout<<cadena;   
  
};




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ----------------------------------FUNCIONES AUXILIARES NÚMEROS COMBINATORIOS---------------------------------- */


/*
	Función:	combinatorioRecurAux
	Entrada:	m: Numero m del numero combinatorio. 
			n: Numero n del numero combinatorio.
	Salida:		long double.
	Descripción	Calcula "m sobre n" de forma recursiva.
*/
long double combinatorioRecurAux(long double m, long double n){

	if( n == 0 || n == m)
		return 1;
	
	return (combinatorioRecurAux(m-1, n-1) + combinatorioRecurAux(m-1, n));

};



/*
	Función:	combinatorioRecurTablaAux
	Entrada:	m: 	Numero m del numero combinatorio. 
			n: 	Numero n del numero combinatorio.
			tabla:	Tabla en la que almacenamos los numeros combinatorios calculados.
	Salida:		long double.
	Descripción	Calcula "m sobre n" de forma recursiva, buscando previamente si tenemos el valor en la tabla.
*/
long double combinatorioRecurTablaAux(long double m, long double n, vector<vector<long double>> &tabla){

	long double aux;
	
	if( n==0 || n==m )
		return 1;
		
	else{
	
		if( tabla[m][n] != 0 )//Está el valor en la tabla.
			return tabla[m][n];
		
		else{
		
		aux = combinatorioRecurTablaAux( m-1, n-1, tabla) + combinatorioRecurTablaAux( m-1, n, tabla);
		tabla[m][n] = aux; 
		
		return aux;
		
		}
	}
};



/*
	Función:	combinatorioIterAux
	Entrada:	m: Numero m del numero combinatorio. 
			n: Numero n del numero combinatorio.
	Salida:		long double.
	Descripción	Calcula "m sobre n" de forma iterativa.
*/
long double combinatorioIterAux(long double m, long double n){

	if( n==0 || n==m )
		return 1;
	
	long double num=m;
   
   	//Calculamos el factorial de m
	for( int i = m-1; i > n; i--)
		num*=i;

	long double den=1;
	
	//Calculamos el factorial de m-n (se empieza en i=2 para ahorrar una iteracion, ya que 1*1=1)
	for( int i = 2; i <= m-n; i++)
		den*=i;

	return num/den;

};




//Fin de funciones.cpp
