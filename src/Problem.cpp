/*
 * Problem.cpp
 *
 *  Created on: 12 f�vr. 2016
 *      Author: Dimitri
 */

#include "Problem.h"

Problem::Problem(double lower, double upper):
_dimension(20), LowerLimit(lower), UpperLimit(upper)
{
}

Problem::Problem(const Problem& prob):
_dimension(prob._dimension), LowerLimit(prob.LowerLimit), UpperLimit(prob.UpperLimit)
{
}

int Problem::dimension() const
{
	return _dimension;
}

int Problem::getIndexFunction() const
{
	return indexFunction;
}
