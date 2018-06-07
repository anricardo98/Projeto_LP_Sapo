#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "..\include\sapo.hpp"
using namespace std;

/**
*@file sapo.cpp
*@brief Arquivo .cpp para a declaração de como os métodos da classe Sapo atuam no funcionamento do programa.
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 1.0
*/

/*@brief Declaração do construtor do construtor padrão da classe Sapo*/
Sapo::Sapo(){

}

/*@brief Declaração do contrutor que atribui os valores de cada atributo da classe Sapo*/	
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

/*@brief Declaração dos gets dos atributos da classe Sapo*/
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

/*@brief Declaração dos sets de atributos da classe Sapo*/
void Sapo::setPulos(int pulos){
	this->pulos = pulos;
}

void Sapo::setDist(int dist){
	this->dist_percorrida = dist;
}

void Sapo::setProvas(int provas){
	this->provas = provas;
}

void Sapo::setEmpate(int empate){
	this->empate = empate;
}

void Sapo::setWins(int wins){
	this->wins = wins;
}

void Sapo::setP_Total(int P_Total){
	this->P_Total = P_Total;
}
