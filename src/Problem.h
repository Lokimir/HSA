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
		Problem();
		~Problem();

		friend std::ostream& operator<< (std::ostream& os, const Problem& pbm);
		friend std::istream& operator>> (std::istream& is, Problem& pbm);

		Problem& operator=  (const Problem& pbm);
		bool operator== (const Problem& pbm) const;
		bool operator!= (const Problem& pbm) const;

		Direction direction () const; //Maximize or Minimize
		int dimension() const;
		double LowerLimit, UpperLimit;

	private:

		int _dimension;
  };
//=======================================================================

#endif
