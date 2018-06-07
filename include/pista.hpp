#ifndef Pista_HPP
#define Pista_HPP

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/**
*@file pista.hpp
*@brief Arquivo .hpp para o documento pista.cpp, onde ocorre a declaração dos métodos e atributos da classe Pista 
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 1.0
*/

class Pista{
protected:
	string local; /*@brief Declaração da variável que armazenará o local da pista*/
	string formato; /*@brief Declaração da variável que armazenará o formato da pista*/
	int numero; /*@brief Declaração da variável que armazenará o identificador da pista*/
	int dist; /*@brief Declaração da variável que armazenará o tamanho da pista*/

public:
	/*@brief Declaração dos construtores*/
	Pista();
	Pista(int i, string local, string formato, int numero);

	/*@brief Declaração das funções get dos atributos*/
    string getLocal();
    string getFormato();
    int getNumero();
    int getDist();
};

#endif
