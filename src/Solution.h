/*
 * Solution.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iostream>
#include <vector>

#include "Problem.h"

class Solution
  {
	//contient la declaration d'une solution
	public:
		Solution(const Problem&);
		~Solution() {};

		const Problem& pbm() const;

		void initialize();
		double fitness();
		double get_fitness();

		unsigned int size() const;

		std::vector<double>& solution();

		double& position(const int index); //retournera une position du tableau _solution
        void  position(const int index, const double value);
        std::vector<double> getSolution();

	private:
        std::vector<double> _solution;
        double _current_fitness;
        const Problem& _problem;
  };

std::vector<double> createDoubleVector();

#endif /* SOLUTION_H_ */
