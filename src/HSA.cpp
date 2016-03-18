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
	Problem p(-30,30,1);
	MyAlgorithm algo(p, stp);
	algo.initialize();

	/**
	 * Optimisation de la fonction cible
	 */
	//std::cout << "Optimizing ...";
	std::cout.flush();
	while(nbStep < stp.getNbrIterations()){
		algo.iterate();
		nbStep++;
		//std::cout <<std::endl<< nbStep;
	}
	//std::cout << std::endl << "Optimization is done.";
	/**
	 * Affichage des resultats
	 */
	double result=0;double ecart = 0;

	for(int i = 0; i < 40; i++)
		result+=algo.getFitness(i);
	result/=40;

	//std::cout << std::cout << std::endl << "Results : " << std::endl;
	std::cout << std::endl /*<< "Best fitness: " */<<-algo.getBestFitness();
	std::cout << /*std::endl << "Average fitness : " */"\t"<<-result;
	std::cout << /*std::endl << "Worst fitness : "*/"\t"<< -algo.getWorstFitness();
	return 0;
}
