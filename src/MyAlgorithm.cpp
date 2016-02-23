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
	Solution* sol;
	struct particle part;
	_upper_cost = 0; _lower_cost = 0;

	for(int j = 0; j<setup().population_size(); j++)
	{
		sol = new Solution(_problem);
		sol->initialize();
		_solutions.insert(_solutions.begin()+j,sol);
		part.fitness = sol->get_fitness();
		part.index=j;
		_fitness_values.insert(_fitness_values.begin()+j,part);
	}
	evaluate(part);
	delete sol;
}

void MyAlgorithm::evaluate(struct particle& part)
{
	double maxFitness,minFitness;

	maxFitness = _solutions[_upper_cost]->get_fitness();
	minFitness = _solutions[_lower_cost]->get_fitness();

	if(maxFitness < part.fitness)
		_upper_cost = part.index;
	for(int i = 0; i < _setup.population_size(); i++)
		if(minFitness > _solutions[i]->get_fitness())
			_lower_cost= i;
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
	const double harmonyMem= 0.9;
	const double limitMin = _problem.LowerLimit;
	const double limitMax = _problem.UpperLimit;
	double tmp = 0;
	struct particle part;
	Solution *sol;

	for(int j = 0 ; j < _setup.population_size(); j++)
	{
		sol = new Solution(_problem);
		for(int i = 0 ; i < _setup.solution_size(); i++)
		{
			if((double)rand()/RAND_MAX<=harmonyMem)
			{
				sol->position(i,_solutions[(int)(39*((double)rand()/RAND_MAX))]->position(i));
				if((double)rand()/RAND_MAX<=rate)
				{
					tmp = sol->position(i)+(limitMax-limitMin)*0.005*
							(-1+2*(double)rand()/RAND_MAX);
					if(tmp<limitMax && tmp>limitMin) sol->position(i, tmp);
				}
			}
			else
				sol->position(i,limitMin+(limitMax-limitMin)*(double)rand()/RAND_MAX);
		}
		if(worst_cost() < sol->fitness())
		{
			_solutions[_lower_cost] = sol;
			part.fitness = sol->get_fitness();
			part.index = _lower_cost;
			evaluate(part);
		}
	}
	delete sol;
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
