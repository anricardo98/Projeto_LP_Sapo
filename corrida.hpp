#ifndef CORRIDA_HPP
#define CORRIDA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sapo.hpp"
#include "pista.hpp"
using namespace std;

class Corrida{
protected:
	vector<Sapo*> saparia;
	vector<Pista*> pistas;
public:
	Corrida();
	void adc_sapo(Sapo *frog);
	void adc_pista(Pista *runway);
	void stats_sapo();
	void stats_pista();
	void run();
};


#endif
