#ifndef CORRIDA_HPP
#define CORRIDA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include "sapo.hpp"
#include "pista.hpp"
using namespace std;

/**
*@file corrida.hpp
*@brief Arquivo .hpp para o documento corrida.cpp, onde ocorre a declaração dos métodos e atributos da classe Pista 
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 2.0
*/

class Corrida{
protected:
	vector<Sapo*> saparia;
	vector<Pista*> pistas;
public:
	Corrida();
	int adc_sapo(Sapo *frog);
	int adc_pista(Pista *runway);
	void stats_sapo();
	void stats_pista();
	void run();
};


#endif
