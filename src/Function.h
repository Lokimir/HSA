/*
 * Function.h
 *
 *  Created on: 26 janv. 2016
 *      Author: GALLIERE,JACOB,REYNIE,SZYMANSKI
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <vector>

class Function
{
public:
	Function() {};
	virtual ~Function() {};

	static double launchFunction(std::vector<double>, unsigned int);
	static double rosenbrock(std::vector<double>);
	static double ackley(std::vector<double>);
	static double schwefel(std::vector<double>);
	static double rastrigin(std::vector<double>);
	static double schaffer(std::vector<double>);
	static double weierstrass(std::vector<double>);
};

#endif /* FUNCTION_H_ */
