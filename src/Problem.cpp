/*
 * Problem.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Dimitri
 */

#include "Problem.h"

Problem::Problem(double lower, double upper):
_dimension(20), LowerLimit(lower), UpperLimit(upper)
{
}

int Problem::dimension() const
{
	return _dimension;
}

