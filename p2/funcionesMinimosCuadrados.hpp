/*
	File: 	funcionesMinimosCuadrados.hpp
	Author:	Adrián López Ortiz
	From:	Algorítmica. Práctica 2

*/

#ifndef MINIMOS_CUADRADOS_HPP
#define MINIMOS_CUADRADOS_HPP

#include <vector>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include "sistemaEcuaciones.hpp"

using namespace std;

vector<vector<double>> calcularMinimosCuadrados(const vector<double> &tamano,const vector<double> &tiempo,int n);

vector<vector<double>> calcularTerminosInds(const vector<double> &tamano, const vector<double> &tiempo, int n);

double sumatorioMultValores(const vector<double> &tamano, const vector<double> &tiempo, double n);

vector <vector<double>> calcularCoef(const vector<double> &tamano, int n);

double sumaVector(const vector<double> &vector, double exp);

double media(const vector<double> &v);

double varianza(const std::vector<double> &v);

double desviacionTipica(const vector<double> &v);

double covarianza(const vector<double> &v1, const vector<double> &v2);

double determinacion(const vector<double> &tEstimado,const vector<double> &tiempo);

double calcularValorAprox(double valorAprox, const vector<vector<double>> &soluciones, int n);

void TiempoAlgoritmos(long double & microsegundos);
#endif
