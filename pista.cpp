#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
#include "pista.hpp"


Pista::Pista(int i, string local, string formato, int numero){
	dist = i;
	this->local = local;
	this->formato = formato;
	this->numero = numero;
}
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
