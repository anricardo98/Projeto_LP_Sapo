#ifndef SAPO_HPP
#define SAPO_HPP

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/**
*@file main.cpp
*@brief Arquivo .hpp para o documento sapo.cpp, onde ocorre a declaração dos métodos e atributos da classe Sapo 
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 2.0
*/

class Sapo{
protected:
	string nome; 
	int ident;
	int dist_percorrida;
	int pulos;
	int provas;
	int wins;
	int empate;
	int P_Total;

public:
	Sapo();
	Sapo(string nome, int ident, int pulos, int provas, int wins, int empate, int pulos_total);
	string getNome();
	int getIdent();
	int getDist();
	int getPulos();
	int getProvas();
	int getWins();
	int getEmpate();
	int getP_Total();
	void setPulos(int pulos);
	void setDist(int dist);
	void setProvas(int provas);
	void setEmpate(int empate);
	void setWins(int wins);
	void setP_Total(int P_Total);
};

#endif
