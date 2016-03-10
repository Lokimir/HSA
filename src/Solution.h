/*
 * Solution.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <vector>
#include "Problem.h"

class Solution
{
public:
	Solution(Problem&);
	~Solution() {};

	const Problem& getProblem() const;
	double getFitness() const;
	std::vector<double> getSolution() const;
	double& getHarmony(const int);

	void initialize();
	void calculateFitness();
	unsigned int size() const;
	void insert(const int, const double);
	std::vector<double> createDoubleVector();

private:
	std::vector<double> harmonies;
	double fitness;
	Problem& problem;
};


#endif /* SOLUTION_H_ */
