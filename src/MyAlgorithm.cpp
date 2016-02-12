/*
 * MyAlgorithm.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Dimitri
 */

#include "MyAlgorithm.h"

#include <cstdlib>

#include "Function.h"
#include "Problem.h"

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

void MyAlgorithm::initialize() /* initialise 40 individus de 20 dimensions */
{
	int dimension = _problem.dimension();
	double lower = _problem.LowerLimit;
	double upper = _problem.UpperLimit;
	int sizePop = setup().population_size();
	Solution* sol = new Solution();
	for(int j = 0; j<sizePop; j++)
	{
		for(int i = 0; i<dimension; i++)
		{
			sol->getSolution().insert(sol->getSolution().begin()+i,lower + (double)rand()/RAND_MAX * (upper-lower));
		}
		_solutions.insert(_solutions.begin()+j,sol);
	}
}

void MyAlgorithm::evaluate() /* Pour chaque individu : calcule sa fitness et la met dans le vector */
{
	Function fun;
	int sizePop = setup().population_size();
	unsigned int min = 0;
	unsigned int max = 0;
	struct particle part;
	for(int i = 0; i<sizePop; i++)
	{
		part.fitness = fun.launchFunction(_solutions[i]->getSolution(), _problem.getIndexFunction());
		part.index=i;
		_fitness_values.insert(_fitness_values.begin()+i,part);
		if(max < part.fitness)
			max=i;
		if(min > part.fitness)
			min=i;
	}
	_upper_cost=max;
	_lower_cost=min;
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
	for(int i =0; i<_fitness_values.size();i++)
	{
		if(_fitness_values[i].index == _upper_cost)
			return _fitness_values[i].fitness;
	}
}

double MyAlgorithm::worst_cost() const
{
	for(int i =0; i<_fitness_values.size();i++)
	{
		if(_fitness_values[i].index == _lower_cost)
			return _fitness_values[i].fitness;
	}
}

Solution& MyAlgorithm::best_solution() const
{
	for(int i =0; i<_fitness_values.size();i++)
	{
		if(_fitness_values[i].index == _upper_cost)
			return *(_solutions[i]);
	}
}

Solution& MyAlgorithm::worst_solution() const
{
	for(int i =0; i<_fitness_values.size();i++)
	{
		if(_fitness_values[i].index == _lower_cost)
			return *(_solutions[i]);
	}
}

void MyAlgorithm::evolution(int iter)
{
	/*makes an evolution step, utiliser evaluate() */
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
