#ifndef Pista_HPP
#define Pista_HPP

#include <iostream>
#include <string>
using namespace std;

class Pista{
protected:
	static int dist;
	string local;
	string formato;
	int numero;

public:
	Pista(static int i, string local, string formato, int numero);
    string getLocal();
    string getFormato();
    int getNumero();
    static int getDist();
}

#endif
