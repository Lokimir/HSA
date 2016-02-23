//============================================================================
// Name        : HSA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <time.h>
#include <cstdlib>
#include <iostream>

#include "MyAlgorithm.h"
#include "Problem.h"
#include "SetUpParams.h"
#include "Solution.h"

int main() {
	int nbStep = 0;
	SetUpParams stp;
	/*std::cout << stp.independent_runs() << " | " << stp.nb_evolution_steps() << " | "
			<< stp.population_size() << " | " << stp.solution_size();*/
	Problem p(-5.12, 5.12,4);
	Solution s(p);
	MyAlgorithm algo(p, stp);
	srand(time(NULL));
	algo.initialize();
	/*for(int j = 0 ; j < 40 ; j++)
	{
		for(int i = 0; i<20;i++)
		{
			std::cout <<  std::endl << j << " " << i << " " << algo.solution(j).getSolution()[i];

		}
	}*/
	int i = 0;
	for(int i = 0; i < 40; i++)
			{
				std::cout << "|" << algo.solution(i).fitness();
			}
		std::cout << std::endl;
	while(nbStep < 2500/*stp.nb_evolution_steps()*/){
		algo.evaluate();
		algo.evolution();
		nbStep++;
		//std::cout << nbStep << std::endl;
	}
		std::cout << std::endl;
	for(int i = 0; i < 40; i++)
			{
				std::cout << "|" << algo.solution(i).fitness();
			}
	return 0;
}
