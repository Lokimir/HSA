/*
 * Problem.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Dimitri
 */

#include "Problem.h"

Problem::Problem(double lower, double upper):
_dimension(20), LowerLimit(lower), UpperLimit(upper),indexFunction(0)
{
}

Problem::Problem(const Problem& prob):
_dimension(prob._dimension), LowerLimit(prob.LowerLimit), UpperLimit(prob.UpperLimit),indexFunction(0)
{
}

Problem::~Problem(){

}

int Problem::dimension() const
{
	return _dimension;
}

int Problem::getIndexFunction() const
{
	return indexFunction;
}

void Problem::setIndexFunction(int indexf)
{
	indexFunction = indexf;
}
