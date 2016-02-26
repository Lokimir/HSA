/*
 * Solution.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Szymanski
 */

#include "Solution.h"

#include <cstdlib>
#include <ctime>
#include <iterator>

#include "Function.h"

Solution::Solution(Problem& pb):
_solution(createDoubleVector()), _current_fitness(0), _problem(pb)
{
}

const Problem& Solution::pbm() const
{
	return _problem;
}

void Solution::initialize()
{
	for(int i = 0; i<_problem.dimension(); i++)
	{
		_solution.insert(_solution.begin()+i,_problem.LowerLimit + ((double)rand())/RAND_MAX * (_problem.UpperLimit-_problem.LowerLimit));
	}
	fitness();
}

double Solution::fitness()
{
	Function f;
	_current_fitness = -f.launchFunction(_solution, _problem.getIndexFunction());
	return _current_fitness;
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

std::vector<double> Solution::getSolution()
{
	return _solution;
}

std::vector<double> createDoubleVector()
{
	std::vector<double> sol;
	return sol;
}
