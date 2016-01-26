/*
 * Function.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "SetUpParams.h";

class Function {
public:
	Function();
	virtual ~Function();

	double rosenbrock(std::vector<double>);
};



#endif /* FUNCTION_H_ */
