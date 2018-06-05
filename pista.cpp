#include <iostream>
#include <string>
#include <vector>
#include <fstring>
using namespace std;
#include "pista.hpp"

Pista::Pista(static int i, string local, string formato, int numero){
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

int Pista::getNumero{
	retunr this->numero;
}

static int Pista::getDist(){
	return this->dist;
}