/*
 * Solution.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Szymanski
 */

#include "Solution.h"

Solution::Solution():
_solution(createDoubleVector()), _current_fitness(0)
{
}

double Solution::get_fitness()
{
	return _current_fitness;
}

unsigned int Solution::size() const
{
	return _solution.size();

}

std::vector<double>& Solution::solution()
{
	return _solution;
}

double& Solution::position(const int index)
{
	return _solution.at(index);
}

void Solution::position(const int index, const double value)
{
	_solution.insert(_solution.begin()+index, value);
}

std::vector<double> createDoubleVector()
{
	std::vector<double> sol;
	return sol;
}

std::vector<double> Solution::getSolution()
{
	return _solution;
}
