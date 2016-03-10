/*
 * SetUpParams.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: Szymanski
 */

#include "SetUpParams.h"

SetUpParams::SetUpParams():
nbrRuns(30), nbrIterations(2e6), populationSize(40), solutionSize(20)
{
}

const unsigned int SetUpParams::getNbrRuns() const
{
	return nbrRuns;
}

const unsigned int SetUpParams::getNbrIterations() const
{
	return nbrIterations;
}

const unsigned int SetUpParams::getPopulationSize() const
{
	return populationSize;
}

const unsigned int SetUpParams::getSolutionSize() const
{
	return solutionSize;
}

void SetUpParams::setNbrRuns(const unsigned int val)
{
	nbrRuns = val;
}

void SetUpParams::setNbrIterations(const unsigned int val)
{
	nbrIterations = val;
}

void SetUpParams::getPopulationSize(const unsigned int val)
{
	populationSize = val;
}

void SetUpParams::setSolutionSize(const unsigned int val)
{
	solutionSize = val;
}
