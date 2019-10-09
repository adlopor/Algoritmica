/*
	File: 	funcionesMinimosCuadrados.cpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 2

*/

#include "funcionesMinimosCuadrados.hpp"


vector<vector<double>> calcularMinimosCuadrados(const vector<double> &tamano,const vector<double> &tiempo,int n){

	vector<vector<double>> coef = calcularCoef(tamano ,n);
	vector<vector<double>> coefInds = calcularTerminosInds(tamano,tiempo,n);

	vector<vector<double>> soluciones(n,vector<double>(1,0));

	//Funcion implementada por el profesor en sistemaEcuaciones.cpp
	resolverSistemaEcuaciones(coef, coefInds, n, soluciones);

	return soluciones;
};



vector<vector<double>> calcularTerminosInds(const vector<double> &tamano, const vector<double> &tiempo, int n){

	vector<vector<double>> coefInds;
	coefInds.resize(n);

	for(int i=0; i<n; i++)
		coefInds[i].resize(1,0);

	for(int i=0; i<n; i++)
		coefInds[i][0] = sumatorioMultValores(tamano,tiempo,i);

   return coefInds;

};



double sumatorioMultValores(const vector<double> &tamano, const vector<double> &tiempo, double n){
	assert(tiempo.size() == tamano.size());
	
	double aux=0;
	
	for(unsigned int i=0; i<tiempo.size(); i++)
		aux += ( tiempo[i] * pow(tamano[i],n) );

	return aux;
};



vector <vector<double>> calcularCoef(const vector<double> &tamano, int n){

	vector<vector<double>> coef(n, vector<double>(n,0));

	for(double i=0; i<n; i++){

		for(double j=0; j<n; j++)
			coef[i][j] = coef[j][i] = sumaVector(tamano,i+j);
      		
	}


	return coef;

};



double sumaVector(const vector<double> &vector, double exp){
	
	double aux=0;
	
	for(unsigned int i=0; i<vector.size(); i++)
		aux += pow(vector[i],exp);
	
	return aux;
}


//---------------------------------------------------------------------

double media(const vector<double> &v){

	double media=0;

	for(unsigned int i=0; i<v.size(); i++){
		media+=v[i];
	}
	
	return media/v.size();
}



double varianza(const std::vector<double> &v){

	double medias=media(v);

	double aux=0;

	for(unsigned int i=0; i<v.size(); i++)
		aux += (pow(v[i]-medias,2));

	aux = aux/v.size();

	return aux;

};



double desviacionTipica(const vector<double> &v){

	double aux = varianza(v);
	aux=sqrt(aux);
	
	return aux;
};



double covarianza(const vector<double> &v1, const vector<double> &v2){
	
	double mV1=media(v1);
	double mV2=media(v2);
	
	double sumatorioVectores = sumatorioMultValores(v1,v2,1);

    double aux = sumatorioVectores/v1.size();
    
    aux = aux - (mV1*mV2);
    
    return aux;

};



double determinacion(const vector<double> &tEstimado,const vector<double> &tiempo){

	double v = varianza(tiempo);
	
	double vEstimada = varianza(tEstimado);
	
    return (vEstimada/v);

};



double calcularValorAprox(double valorAprox, const vector<vector<double>> &soluciones, int n){
	if(valorAprox>0){

		double valor=0;
		
		for(int i=0; i<n; i++){
			valor += soluciones[i][0]*pow(valorAprox,i);
		}
	// valor = 0 + 1*n +2*n²
        return valor;  
	}
	else{
	
	return -1;
	
	}

};



void TiempoAlgoritmos(long double & microsegundos){

	microsegundos = microsegundos/pow(10, 6);//Multiplicamos por 10^6 los microsegundos para obtener segundos
	unsigned long long int tiempoEntero = microsegundos;

	unsigned long long int minutos= tiempoEntero/60;
	
	unsigned long long int segundos= tiempoEntero%60;
	
	unsigned long long int horas= minutos/60;
	
	minutos = minutos%60;
	
	unsigned long long int dias = horas/24;
	
	horas = horas%24;
	
	unsigned long long int anos = dias/365;
	
	dias = dias%365;

	cout << anos << "años, " << dias << " dias, " << horas << " horas, " << minutos << " minutos y " << (float)segundos + (float)microsegundos - (float)tiempoEntero << " segundos." << 		endl;
}
