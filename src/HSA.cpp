//============================================================================
// Name        : HSA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

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
	while(nbStep < stp.getNbrIterations()){
		algo.iterate();
		nbStep++;
		std::cout <<std::endl<< nbStep;
	}

	/**
	 * Affichage des resultats
	 */
	std::cout << std::endl << "Best fitness: " << algo.getBestFitness()<<std::endl;
	double result=0;double ecart = 0;
	for(int i = 0; i < 20; i++)
	{
		result+=algo.getBestSolution().getSolution()[i];
		std :: cout << "|" << algo.getBestSolution().getSolution()[i];
	}
	for(int i = 0; i < 20; i++)
	{
		ecart+=pow(pow(result,2.0)-pow(algo.getBestSolution().getSolution()[i],2.0),2.0);
	}
	std::cout <<std::endl << "Average Best sol : "<<result/20;
	std::cout <<std::endl << "Ecart type : " <<pow(ecart,0.5);
	std::cout <<std::endl << algo.getWorstFitness()<<std::endl;

	result = 0;ecart=0;
	for(int i = 0; i < 20; i++)
	{
		result+=algo.getWorstSolution().getSolution()[i];
		std :: cout << "|" << algo.getWorstSolution().getSolution()[i];
	}
	result/=20;
	std::cout <<std::endl <<result;
	for(int i = 0; i < 20; i++)
	{
		ecart+=pow(pow(result,2.0)-pow(algo.getWorstSolution().getSolution()[i],2.0),2.0);
	}
	std::cout <<std::endl <<pow(ecart,0.5);

	result = 0;ecart=0;
	for(int j = 0; j < 40 ; j++)
	{
		for(int i = 0; i < 20; i++)
		{
			result+=algo.getSolutions()[j]->getSolution()[i];
		}
	}
	std::cout <<std::endl <<result/800;
	for(int j = 0; j < 40 ; j++)
	{
		for(int i = 0; i < 20; i++)
		{
			ecart+=pow(pow(result,2.0)-pow(algo.getSolutions()[j]->getSolution()[i],2.0),2.0);
		}
	}
	std::cout <<std::endl <<pow(ecart,0.5);
	return 0;
}
