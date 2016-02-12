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
		Problem(double,double);
		Problem(const Problem&);
		~Problem(){};

	//	Direction direction () const; //Maximize or Minimize -> type enum
		int dimension() const;
		double LowerLimit, UpperLimit;

	private:
		int _dimension;
  };
//=======================================================================

#endif
