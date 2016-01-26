/*
 * Function.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#include "Function.h"

#include <cmath>
#include <vector>


Function::Function() {
}

Function::~Function() {
}

double Function::rosenbrock(std::vector<double>& X, unsigned int dimension) {
	double sum=0;
	for (int i=0; i<dimension-1; ++i)
		sum += 100*pow( X[i+1] - X[i]*X[i], 2.0) + pow(X[i]-1, 2.0);

	return sum;
}
