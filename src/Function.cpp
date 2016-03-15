/*
 * Function.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#include "Function.h"
#include <cmath>

double Function::rosenbrock(std::vector<double> X)
{
	double sum=0;
	unsigned int dimension = X.size();

	for (unsigned int i = 0; i < dimension-1; ++i)
		sum += 100*pow(X[i+1]-X[i]*X[i], 2.0)+pow(X[i]-1, 2.0);
	sum+= 100*pow(X[0]-X[dimension-1]*X[dimension-1], 2.0)+pow(X[dimension-1]-1, 2.0);
	return sum;
}

double Function::ackley(std::vector<double> solution)
{
	double c = 2*M_PI;
	double exponent = 2;
	double sum1 = 0;
	double sum2 = 0;
	double d = 0;
	double resultat = 0;
	unsigned int dim = solution.size();

	for(unsigned int i = 0; i < dim; i++)
	{
		d = solution[i];
		sum1 += pow(d, exponent);
		sum2 += cos(c*d);
	}

	resultat = -20*exp(-0.2*sqrt(1.0/dim*sum1))-exp(1.0/dim*sum2)+20+exp(1.0);
	return resultat;
}

double Function::schwefel(std::vector<double> solution)
{
	unsigned int dim = solution.size();
	double sum1 = 0;
	double sol = 0;
	double resultat=0;

	for(unsigned int i = 0; i < dim; i++)
	{
		sol = solution[i];
		sum1 += sol*sin(sqrt(abs(sol)));
	}

	resultat = 418.9829*dim-sum1;
	return resultat;
}

double Function::rastrigin(std::vector<double> solution)
{
	unsigned int dim = solution.size();
	double a = 10;
	double sum1 = 0;
	double resultat = 0;

	for(unsigned int i = 0; i < dim; i++)
	{
		double d = solution[i];
		sum1 += pow(d,2.0)-a*cos(2*M_PI*d);
	}

	resultat = a*dim+sum1;
	return resultat;
}

double Function::schaffer (std::vector<double> solution)
{
	unsigned int dim = solution.size();
	double sum = 0;
	double innerThing = 0;
	double resultat = 0;

	for(unsigned int i = 0; i < dim-1; i++)
	{
		innerThing = pow(solution[i], 2) + pow(solution[i+1], 2);
		sum += pow(innerThing, 0.25)*(1+pow(sin(50*pow(innerThing, 0.1)), 2));
	}

	resultat = sum;
	return resultat;

}

double Function::weierstrass(std::vector<double> solution)
{
	unsigned int dim = solution.size();
	double a = 0.5;
	double b = 3.0;
	int kmax = 20;
	double f = 0;

	for (unsigned int i = 0; i < dim; i++)
		for (int k = 0; k <= kmax; k++)
			f += pow(a, k) * cos(2 * M_PI * pow(b, k) * (solution[i] + 0.5));

	return f;
}

double Function::launchFunction(std::vector<double> X, unsigned int n)
{
	switch(n){
		case 1 : return Function::rosenbrock(X); break;
		case 2 : return Function::ackley(X); break;
		case 3 : return Function::schwefel(X); break;
		case 4 : return Function::rastrigin(X); break;
		case 5 : return Function::schaffer(X); break;
		case 6 : return Function::weierstrass(X); break;
		default: break;
	}
	return 0;
}
