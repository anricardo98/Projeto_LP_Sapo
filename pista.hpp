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
*@version 2.0
*/

class Pista{
protected:
	string local;
	string formato;
	int numero;
	int dist;

public:
	Pista();
	Pista(int i, string local, string formato, int numero);
    string getLocal();
    string getFormato();
    int getNumero();
    int getDist();
};

#endif
