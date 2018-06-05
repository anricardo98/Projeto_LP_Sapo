#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include "sapo.hpp"

Sapo::Sapo(){

}
	
Sapo::Sapo(string nome, int ident, int pulos, int provas, int wins, int empate, int pulos_total){
	this->nome = nome;
	this->ident = ident;
	this->pulos = pulos;
	this->provas = provas;
	this->wins = wins;
	this->empate = empate;
	this->P_Total = pulos_total;
	this->dist_percorrida = 0;
}

string Sapo::getNome(){
	return this->nome;
}

int Sapo::getIdent(){
	return this->ident;
}

int Sapo::getDist(){
	return this->dist_percorrida;
}

int Sapo::getPulos(){
	return this->pulos;
}

int Sapo::getProvas(){
	return this->provas;
}

int Sapo::getWins(){
	return this->wins;
}

int Sapo::getEmpate(){
	return this->empate;
}

int Sapo::getP_Total(){
	return this->P_Total;
}

void Sapo::setPulos(int pulos){
	this->pulos = pulos;
}

void Sapo::setDist(int dist){
	this->Dist_percorrida = dist;
}

void Sapo::setProvas(int provas){
	this->provas = provas;
}

void Sapo::setEmpate(int P_Total){
	this->empate = empate;
}

void Sapo::setWins(int wins){
	this->wins = wins;
}

void Sapo::setP_Total(int P_Total){
	this->P_Total = P_Total;
}