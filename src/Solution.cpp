/*
 * Solution.cpp
 *
 *  Created on: 12 févr. 2016
 *      Author: Szymanski
 */

#include "Solution.h"

#include <cstdlib>
#include <iterator>

#include "Function.h"

Solution::Solution(Problem& pb):
harmonies(createDoubleVector()), fitness(0), problem(pb)
{
}

const Problem& Solution::getProblem() const
{
	return problem;
}

double Solution::getFitness() const
{
	return fitness;
}

std::vector<double> Solution::getSolution() const
{
	return harmonies;
}

double& Solution::getHarmony(const int index)
{
	return harmonies.at(index);
}

void Solution::initialize()
{
	for(int i = 0; i<problem.getSize(); i++)
	{
		harmonies.insert(harmonies.begin()+i,problem.LowerLimit + ((double)rand())/RAND_MAX * (problem.UpperLimit-problem.LowerLimit));
	}
	calculateFitness();
}

void Solution::calculateFitness()
{
	fitness = -Function::launchFunction(harmonies, problem.getIndexFunction());
}

unsigned int Solution::size() const
{
	return harmonies.size();
}

void Solution::insert(const int index, const double value)
{
	harmonies.insert(harmonies.begin()+index, value);
}

std::vector<double> Solution::createDoubleVector()
{
	std::vector<double> sol;
	return sol;
}
