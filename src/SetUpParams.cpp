/*
 * SetUpParams.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: Szymanski
 */

#include "SetUpParams.h"
#include <iostream>



SetUpParams::SetUpParams():
_independent_runs(30), _nb_evolution_steps(2*10^6), _population_size(40), _solution_size(20)
{

}

const unsigned int SetUpParams::independent_runs() const
{
	return _independent_runs;
}

const unsigned int SetUpParams::nb_evolution_steps() const
{
	return _nb_evolution_steps;
}

const unsigned int SetUpParams::population_size() const
{
	return _population_size;
}

const unsigned int SetUpParams::solution_size() const
{
	return _solution_size;
}

void SetUpParams::independent_runs(const unsigned int val)
{
	_independent_runs = val;
}

void SetUpParams::nb_evolution_steps(const unsigned int val)
{
	_nb_evolution_steps = val;
}

void SetUpParams::population_size(const unsigned int val)
{
	_population_size = val;
}

void SetUpParams::solution_size(const unsigned int val)
{
	_solution_size = val;
}

SetUpParams::~SetUpParams(){

}
