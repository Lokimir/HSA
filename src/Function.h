/*
 * Function.h
 *
 *  Created on: 26 janv. 2016
 *      Author: GALLIERE,JACOB,REYNIE,SZYMANSKI
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "SetUpParams.h";
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>

class Function {
public:
	Function();
	virtual ~Function();

	double launchFunction(std::vector<double>, unsigned int);

	double rosenbrock(std::vector<double>);
	double ackley(std::vector<double>);
	double schwefel(std::vector<double>);
	double rastrigin(std::vector<double>);
	double schaffer(std::vector<double>);
	double weierstrass(std::vector<double>);
};

#endif /* FUNCTION_H_ */
