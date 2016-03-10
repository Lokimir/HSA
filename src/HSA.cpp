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

#include "Function.h"
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
	std::cout << "Optimizing ...";
	std::cout.flush();
	while(nbStep < stp.getNbrIterations()){
		algo.iterate();
		nbStep++;
		//std::cout <<std::endl<< nbStep;
	}
	std::cout << std::endl << "Optimization is done.";
	/**
	 * Affichage des resultats
	 */
	double result=0;double ecart = 0;

	for(int i = 0; i < 20; i++)
		result+=algo.getFitness(i);
	result/=20;
	for(int i = 0; i < 20; i++)
		ecart+=pow(result-algo.getFitness(i),2.0);
	ecart = pow(ecart/20,0.5);

	std::cout << std::cout << std::endl << "Results : " << std::endl;
	std::cout << std::endl << "Best fitness: " << algo.getBestFitness();
	std::cout <<std::endl << "Average fitness : " <<result;
	std::cout <<std::endl << "Worst fitness : "<< algo.getWorstFitness();
	std::cout <<std::endl << "Standard deviation : " << ecart;
	return 0;
}
