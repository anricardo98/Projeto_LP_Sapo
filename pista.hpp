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

public:
	Pista(int a);
        string getLocal();
        string getFormato();

}

#endif
