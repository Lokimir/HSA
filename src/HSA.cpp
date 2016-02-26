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

int main()
{
	/**
	 *  Declaration des variables
	 */
	unsigned int nbStep = 0;
	srand(time(NULL));

	/**
	 * Initialisation des parametres, du probleme et de l'algorithme
	 */
	SetUpParams stp;
	Problem p(-500,500,3);
	MyAlgorithm algo(p, stp);
	algo.initialize();

	/**
	 * Optimisation de la fonction cible
	 */
	while(nbStep < stp.nb_evolution_steps()){
		algo.evolution();
		nbStep+=40;
		std::cout <<std::endl<< algo.best_solution().getSolution()[0];//nbStep;
	}

	/**
	 * Affichage des resultats
	 */
	std::cout << std::endl << "Best fitness: " << algo.best_cost()<<std::endl;
	double result=0;double ecart = 0;
	for(int i = 0; i < 20; i++)
	{
		result+=algo.best_solution().getSolution()[i];
		std :: cout << "|" << algo.best_solution().getSolution()[i];
	}
	for(int i = 0; i < 20; i++)
	{
		ecart+=pow(pow(result,2.0)-pow(algo.best_solution().getSolution()[i],2.0),2.0);
	}
	std::cout <<std::endl << "Average Best sol : "<<result/20;
	std::cout <<std::endl << "Ecart type : " <<pow(ecart,0.5);
	std::cout <<std::endl << algo.worst_cost()<<std::endl;

	result = 0;ecart=0;
	for(int i = 0; i < 20; i++)
	{
		result+=algo.worst_solution().getSolution()[i];
		std :: cout << "|" << algo.worst_solution().getSolution()[i];
	}
	result/=20;
	std::cout <<std::endl <<result;
	for(int i = 0; i < 20; i++)
	{
		ecart+=pow(pow(result,2.0)-pow(algo.worst_solution().getSolution()[i],2.0),2.0);
	}
	std::cout <<std::endl <<pow(ecart,0.5);

	result = 0;ecart=0;
	for(int j = 0; j < 40 ; j++)
	{
		for(int i = 0; i < 20; i++)
		{
			result+=algo.solutions()[j]->getSolution()[i];
		}
	}
	std::cout <<std::endl <<result/800;
	for(int j = 0; j < 40 ; j++)
	{
		for(int i = 0; i < 20; i++)
		{
			ecart+=pow(pow(result,2.0)-pow(algo.solutions()[j]->getSolution()[i],2.0),2.0);
		}
	}
	std::cout <<std::endl <<pow(ecart,0.5);
	return 0;
}
