/*
 * MyAlgorithm.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Dimitri
 */

#include "MyAlgorithm.h"

#include <cstdlib>


class Function;


MyAlgorithm::MyAlgorithm(const Problem& pbm,const SetUpParams& setup):
_problem(pbm),
_fitness_values(createParticuleVector()),
_setup(setup),
_upper_cost(0),
_lower_cost(0),
_solutions(createSolutionVector())
{
}

MyAlgorithm::~MyAlgorithm()
{
}

const SetUpParams& MyAlgorithm::setup() const
{
	return _setup;
}

void MyAlgorithm::initialize()
{
	int dimension = _problem.dimension();
	double lower = _problem.LowerLimit;
	double upper = _problem.UpperLimit;
	Solution* sol = new Solution();
	for(int i = 0; i<dimension; i++)
	{
		sol->getSolution().push_back(lower + (double)rand()/RAND_MAX * (upper-lower));
	}
	_solutions.push_back(sol);
}

void MyAlgorithm::evaluate()
{
}

const std::vector<Solution*>& MyAlgorithm::solutions() const
{
	return _solutions;
}

unsigned int MyAlgorithm::upper_cost() const
{
	return _upper_cost;
}

unsigned int MyAlgorithm::lower_cost() const
{
	return _lower_cost;
}

Solution& MyAlgorithm::solution(const unsigned int index) const
{
	return *(_solutions[index]);
}

std::vector<struct particle>&  MyAlgorithm::fitness_values()
{
	return _fitness_values;
}

double MyAlgorithm::fitness(const unsigned int index) const
{
	return _fitness_values[index].fitness;
}

double MyAlgorithm::best_cost() const
{
	return _fitness_values[_upper_cost];
}

double MyAlgorithm::worst_cost() const
{
	return _fitness_values[_lower_cost];
}

Solution& MyAlgorithm::best_solution() const
{
	return _solutions[_upper_cost];
}

Solution& MyAlgorithm::worst_solution() const
{
	return _solutions[_lower_cost];
}

void evolution(int iter)
{
	 /*makes an evolution step*/
}

std::vector<Solution*> createSolutionVector()
{
	std::vector<Solution*> sol;
	return sol;
}

std::vector<struct particle> createParticuleVector()
{
	std::vector<struct particle> sol;
	return sol;
}
