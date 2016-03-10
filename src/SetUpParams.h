/*
 * SetUpParams.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef SETUPPARAMS_H_
#define SETUPPARAMS_H_

class SetUpParams
{
public:
	SetUpParams();
	~SetUpParams(){};

	const unsigned int getNbrRuns() const;
	const unsigned int getNbrIterations() const;
	const unsigned int getPopulationSize() const;
	const unsigned int getSolutionSize() const;
	void setNbrRuns(const unsigned int);
	void setNbrIterations(const unsigned int);
	void getPopulationSize(const unsigned int);
	void setSolutionSize(const unsigned int);

private:
	unsigned int nbrRuns;
	unsigned int nbrIterations;
	unsigned int populationSize;
	unsigned int solutionSize;
};
#endif /* SETUPPARAMS_H_ */
