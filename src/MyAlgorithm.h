/*
 * MyAlgorithm.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef MYALGORITHM_H_
#define MYALGORITHM_H_

#include <vector>

#include "Problem.h"
#include "Solution.h"
#include "SetUpParams.h"

class MyAlgorithm
{
private:
	std::vector<Solution*> solutions;     // individuals in population
	std::vector<struct particle> fitnesses;
	const SetUpParams& setup;
	unsigned int upperFitnessIndex,lowerIndexFitness; // lower and upper fitness of individuals in population
	Problem& problem;

public:
	MyAlgorithm(Problem& pbm,const SetUpParams& setup);
	~MyAlgorithm();

	const SetUpParams& getSetup() const;
	void initialize();

	// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
	void evaluate();
	void evaluate(struct particle&);

	const std::vector<Solution*>& getSolutions() const;
	unsigned int getUpperFitnessIndex() const;
	unsigned int getLowerFitnessIndex() const;
	Solution& getSolution(const unsigned int) const;
	std::vector<struct particle>&  getFitnesses();
	double getFitness(const unsigned int) const;

	double getBestFitness() const;
	double getWorstFitness() const;
	Solution& getBestSolution() const;
	Solution& getWorstSolution() const;
	Solution& calculateAverageSolution() const;
	void iterate();
	std::vector<Solution*> createSolutionVector();
	std::vector<struct particle> createParticuleVector();
};

#endif /* MYALGORITHM_H_ */
