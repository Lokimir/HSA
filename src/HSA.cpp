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
#include <math.h>

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
	/*int i = 0;
	for(int i = 0; i < 40; i++)
	{
		std::cout << "|" << algo.solution(i).fitness();
	}
		std::cout << std::endl;*/
	while(nbStep < stp.nb_evolution_steps()){
		algo.evolution();
		nbStep+=40;
		std::cout <<std::endl<<nbStep;
	}
	/*std::cout << std::endl;
	for(int i = 0; i < 40; i++)
	{
		std::cout << "|" << algo.solution(i).fitness();
	}
	std::cout <<std::endl ;*/
	std::cout << algo.best_cost()<<std::endl;
	double result=0;double ecart = 0;
	for(int i = 0; i < 20; i++)
	{
		result+=algo.best_solution().getSolution()[i];
		std :: cout << "|" << algo.best_solution().getSolution()[i];
		ecart+=pow(pow(result,2.0)-pow(algo.best_solution().getSolution()[i],2.0),2.0);
	}
	std::cout <<std::endl <<result/20;
	std::cout <<std::endl <<pow(ecart,0.5);
	std::cout <<std::endl <<algo.worst_cost()<<std::endl;
	result = 0;ecart=0;
	for(int i = 0; i < 20; i++)
	{
		result+=algo.worst_solution().getSolution()[i];
		std :: cout << "|" << algo.worst_solution().getSolution()[i];
		ecart+=pow(pow(result,2.0)-pow(algo.worst_solution().getSolution()[i],2.0),2.0);
	}
	std::cout <<std::endl <<result/20;
	std::cout <<std::endl <<pow(ecart,0.5);
	return 0;
}
