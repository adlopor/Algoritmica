/*
	File: 	Entero.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 3

*/

#include "Entero.hpp"

using namespace std;


//----------------------------------------
bool esEntero(const string &s){
	
	//Si esta vacío el string o el primer caracter no es un digito o los signos +-
	if(s.empty() || (!isdigit(s[0])) )
		return false;
	
	char * endptr ;
	strtol(s.c_str(), &endptr, 10) ;

	return (*endptr == 0);//Esto es por si ha habido algún fallo en la conversión?

};

//----------------------------------------
void Entero::partirCadena (string &cad1, string &cad2){

	int aux,aux2;
	
	aux= this->_entero.length();
	
	if (aux%2 == 0)
		aux2= aux/2;
		
	else{
		aux2= (aux+1)/2;//En caso de ser impar se agregaría si fuera necesario para operar un cero a la izq.
	}
	
	//Dividimos en dos subcadenas el número.
	cad1= this->_entero.substr(0,aux2);
	cad2= this->_entero.substr(aux2);//desde aux2 hasta el final de la cadena this->_entero.

	return;
};



//----------------------------------------
void Entero::agregarCerosFinal (int nCeros){

	for (int i=0; i<nCeros; i++)
		this->_entero.push_back('0');
	
	return;
};




//----------------------------------------
void Entero::agregarCerosDelante(int nCeros){

	string aux;
	for(int i=0; i<nCeros; i++)
		aux.push_back('0');
	
	this->_entero = aux + this->_entero;
	
	return;
}





//----------------------------------------
void Entero::quitarCerosNoSignificativos(){

	int i=0, nCeros=0;
	int tamano;
	 
	tamano = (this->_entero.length()) -1;
	
	//Contamos el número de ceros a la derecha
	while( this->_entero[i] == '0' && i < tamano){
		i++;
		nCeros++;
	}
	
	//Guardamos la subcadena(sin ceros no significativos), machacando el valor anterior. 
        this->_entero= this->_entero.substr(nCeros);
	
	//En caso de que el número sea solamente muchos ceros, se pone la cadena = "0", para que esta no esté vacía.
	if( this->_entero == "")
		this->_entero = "0";
	
	return;
};



//----------------------------------------
ostream &operator<<(ostream &salida,const Entero &d){
	
	salida<<d.getEntero();
	
	return salida;
};



//----------------------------------------
istream &operator>>(istream &entrada, Entero &d){
	
	string aux;
	//almacenamos la entrada en la string auxiliar
	entrada>>aux;
	
	//Y luego almacenamos con el setter el número.
	d.setEntero(aux);
	
	return entrada;
};



//----------------------------------------
Entero Entero::operator+(Entero &e){

	string suma;
	string::reverse_iterator i,j;
	
	int n1,n2;
	string aux2;
	
	int acarreo=0;
	
	//Recorre el entero desde principio a fin, cifra a cifra.
	for(i = e._entero.rbegin(), j = this->_entero.rbegin(); (i!=e._entero.rend()) && (j!=this->_entero.rend() );i++,j++){
	
		int n1 = *i - '0';
		int n2 = *j - '0';
	
		int aux = n1+n2+acarreo;//Guardamos en aux  
	
		
		if (aux < 10){
	
			aux2 = '0' + aux;
			acarreo=0;
		}

		else{
	
			aux2 = '0' + aux % 10;
			acarreo = aux/10;
		}
	
		suma= aux2+suma;
	
	}

	while(i!=e._entero.rend()){
          
		int aux;
		
		if(acarreo!=0){
		
		aux = (*i - '0') + acarreo;
		
		if (aux < 10) 
			acarreo=0;
		
		else{
		
			acarreo = aux/10;
			aux=aux%10;
		
		}
		
		aux2='0'+aux;
		
		suma=aux2+suma ; 
            
		}
	
		else
			suma=*i+suma;
			
		i++;
	}

	while(j!=this->_entero.rend()){
		
		int aux;
		
		if(acarreo!=0){
			aux = (*j - '0') + acarreo;
		
			if (aux < 10)
				acarreo=0;

			else{
				acarreo = aux/10;
				aux=aux%10; 
			}

			aux2='0'+aux;
			
			suma=aux2+suma; 

		}
		else
		suma=*j+suma;
		
		j++;
	}
	
	if(acarreo>0)
		suma=to_string(acarreo)+suma;
	

	return Entero(suma);
};


//----------------------------------------
Entero Entero::operator*(Entero &e){

	int s;
	string e1,e2,e3,e4;
	
	int n = this->magnitudMaxima(e);
	if(n <= this->getMax()) {

		string result=to_string(stoi(e._entero) * stoi(this->_entero));
		
		return Entero(result);
	}

	if( this->_entero == "0" || e._entero == "0" )
		return Entero("0");
    
	if( n > this->_entero.length() )   
		this->agregarCerosDelante(n-this->_entero.length());
		
	if(n > e._entero.length() )    
		e.agregarCerosDelante(n-e._entero.length());

	s=n/2;
	
	//Partimos en 2 ambos numeros:
	this->partirCadena(e1,e2);    
	e.partirCadena(e3,e4);
	
	//Guardamos el maximo establecido en los nuevos Enteros creados
	Entero E1(e1,this->getMax());
	Entero E2(e2,this->getMax());
	Entero E3(e3,this->getMax()); 
	Entero E4(e4,this->getMax());
     
	//Quitamos los ceros a la izq. para que no estorben al multiplicar (NO HARIA FALTA)
	E1.quitarCerosNoSignificativos();
	E2.quitarCerosNoSignificativos();
	E3.quitarCerosNoSignificativos();
	E4.quitarCerosNoSignificativos();
	
	
	//1a*1b
	Entero a= E1*E3;
	a.setMax(this->getMax());
	a.multiplicarPotencia10(s*2);

	//1a*2b
	Entero b= E1*E4;
	b.setMax(this->getMax());
	
	//2a*1b
	Entero c= E2*E3;
	c.setMax(this->getMax());
	
	
	
	//2a*2b
	Entero d= E2*E4;
	d.setMax(this->getMax());


	Entero f=b+c;
	f.multiplicarPotencia10(s);
	f.setMax(this->getMax());
	
	Entero res = a+d+f;
	res.setMax(this->getMax());
	res.quitarCerosNoSignificativos();
	
	e.quitarCerosNoSignificativos();
	this->quitarCerosNoSignificativos();
	
	return res;
};


