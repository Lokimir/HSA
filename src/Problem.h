/*
 * Problem.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>

struct particle // index of a particle in the swarm and its fitness
{
	int index;
	double fitness;
};

//=======================================================================
class Problem
{
public:
	double LowerLimit, UpperLimit;

	Problem(double,double,int);
	Problem(const Problem&);
	~Problem(){};

	//	Direction direction () const; //Maximize or Minimize -> type enum
	int dimension() const;
	int getIndexFunction() const;
	void setIndexFunction(int);

private:
	int _dimension;
	int indexFunction;
};
//=======================================================================

#endif
