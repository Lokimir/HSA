/*
 * Function.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#include "Function.h"

#include <cmath>
#include <vector>

Function::~Function() {
}

double Function::rosenbrock(std::vector<double>& X, unsigned int dimension) {
	double sum=0;
	for (int i=0; i<dimension-1; ++i)
		sum += 100*pow( X[i+1] - X[i]*X[i], 2.0) + pow(X[i]-1, 2.0);

	return sum;
}
double Function::ackley(std::vector<double>& solution){
	double a,b,c;
	a=20;
	b=0.2;
	c=2*M_PI;
	double quadrat=2.0;
	unsigned int d= solution.size();
	double sum1=0;
	double sum2=0;
	for(int i=1;i<=d;i++)
	{
		double d=solution[i];
		sum1=sum1+pow(d,quadrat);
	}
	for(int i=1;i<=d;i++)
	{
		double d=solution[i];
		sum2=sum2+cos(c*d);
	}
	double expr1=0;
	expr1=-b*sqrt((1/d)*sum1);
	double expr2=0;
	expr2=(1/d)*sum2;
	double resultat=0;

	resultat= -a*exp(expr1)-exp(expr2)+a+exp(1);
	return resultat;
}
