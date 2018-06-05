#ifndef SAPO_HPP
#ifndef SAPO_HPP

#include <iostream>
#include <string>
using namespace std;

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
	void setEmpate(int P_Total);
	void setWins(int wins);
	void setP_Total(int P_Total);
};

#endif