/*
 * MyAlgorithm.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Dimitri
 */

#include "MyAlgorithm.h"

#include <cstdlib>
#include <ctime>
#include <iterator>

#include "Function.h"
#include "SetUpParams.h"


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
	for(int j = 0; j<setup().population_size(); j++)
	{
		Solution* sol = new Solution(_problem);
		sol->initialize();
		_solutions.insert(_solutions.begin()+j,sol);
	}
}

void MyAlgorithm::evaluate() /* Pour chaque individu : calcule sa fitness et la met dans le vector */
{
	Function fun;
	int sizePop = setup().population_size();
	unsigned int min = 0;
	unsigned int max = 0;
	double maxFitness,minFitness;
	struct particle part;

	maxFitness = fun.launchFunction(_solutions[0]->getSolution(), _problem.getIndexFunction());
	minFitness = maxFitness;

	for(int i = 0; i<sizePop; i++)
	{
		part.fitness = fun.launchFunction(_solutions[i]->getSolution(), _problem.getIndexFunction());
		part.index=i;
		_fitness_values.insert(_fitness_values.begin()+i,part);
		if(maxFitness < part.fitness)
		{
			maxFitness = part.fitness;
			max=i;
		}
		if(minFitness > part.fitness)
		{
			minFitness = part.fitness;
			min=i;
		}
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

void MyAlgorithm::evolution()
{
	const double rate = 0.3;
	const double harmonyMem= 0;
	const double limitMin = _problem.LowerLimit;
	const double limitMax = _problem.UpperLimit;
	double tmp = 0;

	for(int j = 0 ; j < _setup.population_size(); j++)
	{
		Solution* sol = new Solution(_problem);
		for(int i = 0 ; i < _setup.solution_size(); i++)
		{
			if((double)rand()/RAND_MAX<=harmonyMem)
			{
				sol->position(i,_solutions[(int)(39*((double)rand()/RAND_MAX))]->position(i));
				if((double)rand()/RAND_MAX<=rate)
				{
					tmp = sol->position(i);
					sol->position(i, tmp+(limitMax-limitMin)*0.005*
							(-1+2*(double)rand()/RAND_MAX));
				}
			}
			else
				sol->position(i,limitMin+(limitMax-limitMin)*(double)rand()/RAND_MAX);
		}
		if(worst_cost() < sol->fitness())
			_solutions[lower_cost()] = sol;
	}
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
