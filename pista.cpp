#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cstdlib>
#include "pista.hpp"
using namespace std;

/**
*@file pista.cpp
*@brief Arquivo .cpp para a declaração de como os métodos da classe Pista atuam no funcionamento do programa.
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 2.0
*/

/*@brief Declaração do construtor do construtor padrão da classe Pista*/
Pista::Pista(){

}

/*@brief Declaração do contrutor que atribui os valores de cada atributo da classe Pista*/	
Pista::Pista(int i, string local, string formato, int numero){
	dist = i;
	this->local = local;
	this->formato = formato;
	this->numero = numero;
}

/*@brief Declaração dos gets dos atributos da classe Pista*/
string Pista::getLocal(){
	return this->local;
}

string Pista::getFormato(){
	return this->formato;
}

int Pista::getNumero(){
	return this->numero;
}

int Pista::getDist(){
	return dist;
}
