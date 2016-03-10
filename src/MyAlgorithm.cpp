/*
 * MyAlgorithm.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Dimitri
 */

#include "MyAlgorithm.h"

#include <cstdlib>

#include "SetUpParams.h"

MyAlgorithm::MyAlgorithm(Problem& pbm,const SetUpParams& setup):
problem(pbm),
fitnesses(createParticuleVector()),
setup(setup),
upperFitnessIndex(0),
lowerIndexFitness(0),
solutions(createSolutionVector())
{
}

MyAlgorithm::~MyAlgorithm()
{
	for(unsigned int i = 0; i < setup.getPopulationSize() ; i++)
	{
		delete solutions[i];
	}
}

const SetUpParams& MyAlgorithm::getSetup() const
{
	return setup;
}

void MyAlgorithm::initialize() /* initialise 40 individus de 20 dimensions */
{
	Solution* sol;
	struct particle part;
	upperFitnessIndex = 0; lowerIndexFitness = 0;

	for(unsigned int j = 0; j<getSetup().getPopulationSize(); j++)
	{
		sol = new Solution(problem);
		sol->initialize();
		solutions.insert(solutions.begin()+j,sol);
		part.fitness = sol->getFitness();
		part.index=j;
		fitnesses.insert(fitnesses.begin()+j,part);
	}
	evaluate();
}

void MyAlgorithm::evaluate()
{
	double maxFitness = fitnesses[0].fitness;
	double minFitness = maxFitness;
	int max =0;
	int min =0;

	for(unsigned int i = 0; i < setup.getPopulationSize(); i++)
	{
		if(maxFitness < solutions[i]->getFitness())
		{
			maxFitness = solutions[i]->getFitness();
			max = i;
		}
		if(minFitness > solutions[i]->getFitness())
		{
			minFitness = solutions[i]->getFitness();
			min = i;
		}
	}
	upperFitnessIndex= max;
	lowerIndexFitness= min;
}

void MyAlgorithm::evaluate(struct particle& part)
{
	double maxFitness, minFitness;

	maxFitness = getBestFitness();
	minFitness = maxFitness;
	int min = 0;

	for(unsigned int i = 0 ; i < setup.getPopulationSize() ; i++)
	{
		if((unsigned int)fitnesses[i].index ==lowerIndexFitness)
			fitnesses[i]= part;
	}

	if(maxFitness < part.fitness)
		upperFitnessIndex = part.index;
	for(unsigned int i = 0; i < setup.getPopulationSize(); i++)
	{
		if(minFitness > fitnesses[i].fitness)
		{
			minFitness = fitnesses[i].fitness;
			min = fitnesses[i].index;
		}
	}
	lowerIndexFitness= min;
}

const std::vector<Solution*>& MyAlgorithm::getSolutions() const
{
	return solutions;
}

unsigned int MyAlgorithm::getUpperFitnessIndex() const
{
	return upperFitnessIndex;
}

unsigned int MyAlgorithm::getLowerFitnessIndex() const
{
	return lowerIndexFitness;
}

Solution& MyAlgorithm::getSolution(const unsigned int index) const
{
	return *(solutions[index]);
}

std::vector<struct particle>&  MyAlgorithm::getFitnesses()
{
	return fitnesses;
}

double MyAlgorithm::getFitness(const unsigned int index) const
{
	return fitnesses[index].fitness;
}

double MyAlgorithm::getBestFitness() const
{
	for(unsigned int i =0; i<fitnesses.size();i++)
	{
		if((unsigned int)fitnesses[i].index == upperFitnessIndex)
			return fitnesses[i].fitness;
	}
	throw ;
}

double MyAlgorithm::getWorstFitness() const
{
	for(unsigned int i =0; i<fitnesses.size();i++)
	{
		if((unsigned int)fitnesses[i].index == lowerIndexFitness)
			return fitnesses[i].fitness;
	}
	throw ;
}

Solution& MyAlgorithm::getBestSolution() const
{
	for(unsigned int i =0; i<fitnesses.size();i++)
	{
		if((unsigned int)fitnesses[i].index == upperFitnessIndex)
			return *(solutions[i]);
	}
	throw ;
}

Solution& MyAlgorithm::getWorstSolution() const
{
	for(unsigned int i =0; i<fitnesses.size();i++)
	{
		if((unsigned int)fitnesses[i].index == lowerIndexFitness)
			return *(solutions[i]);
	}
	throw ;
}


Solution& MyAlgorithm::calculateAverageSolution() const
{
	double result;
	Solution* sol = new Solution(problem);
	for(unsigned int j = 0; j < setup.getSolutionSize() ; j++)
	{
		result = 0;
		for(unsigned int i = 0; i < setup.getPopulationSize(); i++)
		{
			result+=getSolutions()[i]->getSolution()[j];
		}
		result/=setup.getPopulationSize();
		sol->insert(j,result);
	}
	return *sol;
}

void MyAlgorithm::iterate()
{
	const double rate = 0.3;
	const double harmonyMem= 0.9;
	const double limitMin = problem.LowerLimit;
	const double limitMax = problem.UpperLimit;
	double tmp = 0;
	struct particle part;
	Solution* sol = new Solution(problem);

	for(unsigned int i = 0 ; i < setup.getSolutionSize(); i++)
	{
		if((double)rand()/RAND_MAX<=harmonyMem)
		{
			sol->insert(i,solutions[(int)(39*((double)rand()/RAND_MAX))]->getHarmony(i));
			if((double)rand()/RAND_MAX<=rate)
			{
				tmp = sol->getHarmony(i)+(limitMax-limitMin)*0.005*
						(-1+2*(double)rand()/RAND_MAX);
				if(tmp<limitMax && tmp>limitMin) sol->insert(i, tmp);
			}
		}
		else
			sol->insert(i,limitMin+(limitMax-limitMin)*(double)rand()/RAND_MAX);
	}
	sol->calculateFitness();
	if(getWorstFitness() < sol->getFitness())
	{
		delete solutions[lowerIndexFitness];
		solutions[lowerIndexFitness] = sol;
		part.fitness = sol->getFitness();
		part.index = lowerIndexFitness;
		evaluate(part);
	}
	else
		delete sol;
}

std::vector<Solution*> MyAlgorithm::createSolutionVector()
{
	std::vector<Solution*> sol;
	return sol;
}

std::vector<struct particle> MyAlgorithm::createParticuleVector()
{
	std::vector<struct particle> sol;
	return sol;
}
