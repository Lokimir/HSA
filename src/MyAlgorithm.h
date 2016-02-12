/*
 * MyAlgorithm.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef MYALGORITHM_H_
#define MYALGORITHM_H_

#include <iostream>
#include <vector>

#include "Problem.h"
#include "Solution.h"

class SetUpParams;

class MyAlgorithm
  {
	private:
		std::vector<Solution*> _solutions;     // individuals in population
		std::vector<struct particle> _fitness_values;
		const SetUpParams& _setup;
		unsigned int _upper_cost,_lower_cost; // lower and upper fitness of individuals in population
		Problem _problem;

	public:
		MyAlgorithm(const Problem& pbm,const SetUpParams& setup);
		~MyAlgorithm();

		const SetUpParams& setup() const;
	  	void initialize();

		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        void evaluate();

	 	const std::vector<Solution*>& solutions() const;
		unsigned int upper_cost() const;
		unsigned int lower_cost() const;
		Solution& solution(const unsigned int index) const;
        std::vector<struct particle>&  fitness_values();
		double fitness(const unsigned int index) const;


		double best_cost() const;
		double worst_cost() const;
		Solution& best_solution() const;
		Solution& worst_solution() const;

		void evolution(int iter); /*makes an evolution step*/
  };

#endif /* MYALGORITHM_H_ */
