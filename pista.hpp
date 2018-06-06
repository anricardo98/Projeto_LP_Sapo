#ifndef Pista_HPP
#define Pista_HPP

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Pista{
protected:
	string local;
	string formato;
	int numero;
	int dist;

public:
	Pista(int i, string local, string formato, int numero);
    string getLocal();
    string getFormato();
    int getNumero();
    int getDist();
};

#endif
