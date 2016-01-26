/*
 * Function.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#include "Function.h"


Function::Function() {
}

Function::~Function() {
}

double Function::rosenbrock(std::vector<double>& solution) {
	double sum=0;
	for (int i=0; i</*Dimensions*/3-1; ++i)
		sum += 100*pow( solution[i+1] - solution[i]*solution[i], 2) + pow(solution[i]-1, 2.0);

	return sum;
}
