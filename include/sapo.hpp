#ifndef SAPO_HPP
#define SAPO_HPP

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/**
*@file sapo.hpp
*@brief Arquivo .hpp para o documento sapo.cpp, onde ocorre a declaração dos métodos e atributos da classe Sapo 
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 1.0
*/

class Sapo{
protected:
	string nome; /*@brief Declaração da variável que armazenará o nome do sapo*/
	int ident; /*@brief Declaração da variável que armazenará o identificador do sapo*/
	int dist_percorrida; /*@brief Declaração da variável que armazenará a distancia percorrida pelo sapo na corrida*/
	int pulos; /*@brief Declaração da variável que armazenará os pulos que o sapo deu durante a corrida*/
	int provas; /*@brief Declaração da variável que armazenará o número de provas que o sapo correu*/
	int wins; /*@brief Declaração da variável que armazenará o número de vitórias do sapo*/
	int empate; /*@brief Declaração da variável que armazenará o número de empates do sapo*/
	int P_Total; /*@brief Declaração da variável que armazenará o somatório dos pulos que o sapo deu em sua carreira*/

public:
	/*@brief Declaração dos construtores*/
	Sapo();
	Sapo(string nome, int ident, int pulos, int provas, int wins, int empate, int pulos_total);

	/*@brief Declaração das funções get dos atributos*/
	string getNome();
	int getIdent();
	int getDist();
	int getPulos();
	int getProvas();
	int getWins();
	int getEmpate();
	int getP_Total();

	/*@brief Declaração de funções set de alguns atributos*/
	void setPulos(int pulos);
	void setDist(int dist);
	void setProvas(int provas);
	void setEmpate(int empate);
	void setWins(int wins);
	void setP_Total(int P_Total);
};

#endif
