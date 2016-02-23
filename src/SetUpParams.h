/*
 * SetUpParams.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef SETUPPARAMS_H_
#define SETUPPARAMS_H_
#include <iostream>

class SetUpParams
  {
  	//ici vous devez mettre quelques parametres tels que :

	private:
		unsigned int   _independent_runs;         //number of independent runs
		unsigned int   _nb_evolution_steps;       // number of iterations per run
		unsigned int   _population_size;		// number of solutions in the population
		unsigned int   _solution_size;	        // size of each particle

	public:
		SetUpParams();
		~SetUpParams(){};

		const unsigned int   independent_runs() const;
		const unsigned int   nb_evolution_steps() const;
		const unsigned int   population_size() const;
		const unsigned int   solution_size() const;
		void independent_runs(const unsigned int);
		void nb_evolution_steps(const unsigned int);
		void population_size(const unsigned int);
		void solution_size(const unsigned int);
  };
#endif /* SETUPPARAMS_H_ */
