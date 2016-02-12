/*
 * Function.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#include "Function.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>

Function::~Function() {
}

double Function::rosenbrock(std::vector<double> X) {
	double sum=0;
	unsigned int dimension = X.size();
	for (int i=0; i<dimension-1; ++i)
		sum += 100*pow( X[i+1] - X[i]*X[i], 2.0) + pow(X[i]-1, 2.0);

	return sum;
}
double Function::ackley(std::vector<double> solution){
	double c=2*M_PI,carre =2;
	unsigned int dim= solution.size();
	double sum1=0;
	double sum2=0;
	for(unsigned int i=1;i<=dim;i++)
	{
		double d=solution[i];
		sum1=sum1+pow(d,carre);
		sum2=sum2+cos(c*d);
	}
	double resultat=0.0;

	resultat=-20*exp(-0.2 * sqrt(1.0/dim * sum1))-exp(1.0/dim*sum2)+ 20+ exp(1.0);
	return resultat;
}
double Function::schwefel(std::vector<double> solution){

	unsigned int dim= solution.size();
	double sum1=0;
	for(int i=1;i<=dim;i++)
	{
		double d=solution[i];
		sum1=sum1+d*sin(sqrt(abs(d)));
	}
	double resultat=0;
	resultat=418.9829*dim-(sum1);
	return resultat;
}
double Function::rastrigin(std::vector<double> solution){

	unsigned int dim= solution.size();
	double a=10;
	double sum1=0;
	for(int i=1;i<=dim;i++)
	{
		double d=solution[i];
		sum1=sum1+(pow(d,2.0)-a*cos(2*M_PI*d));
	}
	double resultat=a*dim+sum1;
	return resultat;
}

double Function::launchFunction(std::vector<double> X, unsigned int n)
{
	switch(n)
		case 1 : rosenbrock(X); break;
		case 2 : ackley(X); break;
		case 3 : schwefel(X); break;
		case 4 : rastrigin(X); break;
		case 5 : break;
		case 6 : break;
		default; break;
}
