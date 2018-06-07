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
	vector<Sapo*> saparia; /*@brief Vetor que armazenará todos os sapos*/
	vector<Pista*> pistas; /*@brief Vetor que armazenará todas as pistas*/
public:
	Corrida(); /*@brief Declaração do construtor do construtor padrão*/
	int adc_sapo(Sapo *frog); /*@brief Declaração da função responsável pela adição de um sapo ao vetor com todos*/
	int adc_pista(Pista *runway); /*@brief Declaração da função responsável pela adição de uma pista ao vetor com todas*/
	void stats_sapo(); /*@brief Declaração da função responsável pela mostragem das estatísticas de cada um dos sapos*/
	void stats_pista(); /*@brief Declaração da função responsável pela mostragem das estatísticas de cada uma das pistas*/
	void run(); /*@brief Declaração da função responsável pela realização da corrida*/
};


#endif
