/*
 * Solution.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Szymanski
 */

#include "Solution.h"

Solution::Solution(const Problem& pbm) :
_solution(NULL), _current_fitness(NULL), _pbm(pbm)
{

}

Solution::Solution(const Solution& sol) :
_solution(sol._solution), _current_fitness(sol._current_fitness), _pbm(pbm())
{

}

const Problem& Solution::pbm() const
{
	return _pbm;
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
