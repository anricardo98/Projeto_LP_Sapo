#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "corrida.hpp"
#include "pista.hpp"
#include "sapo.hpp"
using namespace std;

/**
*@file main.cpp
*@brief Arquivo main do programa que gerencia a corrida de sapos.
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 2.0
*/

/*@brief Ĺink para o github onde este arquivo está disponibilizado: https://github.com/anricardo98/Projeto_LP_Sapo*/

int main(){

	int resposta; 
	string aux_nome;
	int aux_ident;
	int aux_pulo;
	int aux_empate;
	int aux_wins;
	int aux_p_total;
	int aux_provas;
	int aux_dist;
	string aux_local;
	string aux_formato;
	int aux_numero;
	int aux; 
	
	Corrida info;

	ifstream myfile;
	myfile.open("sapo.txt");

	if(myfile.is_open()){
		while (!myfile.eof()){
			
			myfile >> aux_nome;
			myfile >> aux_ident;
			myfile >> aux_pulo;
			myfile >> aux_provas;
			myfile >> aux_wins;
			myfile >> aux_empate;
			myfile >> aux_p_total;

			Sapo *frog_ = new Sapo(aux_nome, aux_ident, aux_pulo , aux_provas, aux_wins, aux_empate, aux_p_total);
			info.adc_sapo(frog_);
		}

	} else {
		cout << "Impossivel abrir arquivo dos sapos" << endl;
	
	}

	myfile.close();

	ifstream myfile2;
	myfile2.open("pista.txt");

	if(myfile2.is_open()){
		while (!myfile2.eof()){
			
			myfile2 >> aux_numero;
			myfile2 >> aux_local;
			myfile2 >> aux_formato;
			myfile2 >> aux_dist;

			Pista *runway_ = new Pista(aux_dist, aux_local, aux_formato, aux_numero);
			info.adc_pista(runway_);
		}

	} else {
		cout << "Impossivel abrir arquivo das pistas" << endl;
	
	}

	myfile2.close();
		
	cerr << "O que voce deseja fazer?" << endl;
	cerr << "Digite '1' para ver as estatisticas dos sapos" << endl;
	cerr << "Digite '2' para ver as estatisticas das pistas" << endl;
	cerr << "Digite '3' para iniciar uma corrida" << endl;
	cerr << "Digite '4' para criar um sapo" << endl;
	cerr << "Digite '5' para criar uma pista" << endl;
	cin >> resposta;

	if (resposta == 1){

		info.stats_sapo();

	} else if (resposta == 2){

		info.stats_pista();

	} else if (resposta == 3){

		srand(time(NULL));
		info.run();

	} else if (resposta == 4){

		string nome;
		int ident;
		int pulos;
		int provas;
		int wins;
		int empate;
		int p_total;

		cin.ignore();
		cout << "Qual o nome do sapo?" << endl;
		getline (cin, nome);

		cout << "Qual o identificador do sapo?" << endl;
		cin >> ident;

		cout << "Quantos pulos ele deu na ultima corrida?" << endl;
		cin >> pulos;

		cout << "Quantas provas ele ja disputou?" << endl;
		cin >> provas;

		cout << "Quantas provas ele ganhou?" << endl;
		cin >> wins;

		cout << "Quantas provas ele empatou?" << endl;
		cin >> empate;

		cout << "Quantos pulos ele deu em toda sua carreira" << endl;
		cin >> p_total;

		Sapo *salvo = new Sapo(nome, ident, pulos, provas, wins, empate, p_total);
		aux = info.adc_sapo(salvo);
		delete salvo;

		if (aux == 1){
			ofstream myfile;
			myfile.open("sapo.txt", ios::out | ios::app);

			if (myfile.is_open()){	
				myfile << "\n" << nome;
				myfile << "\n" << ident;
				myfile << "\n" << pulos;
				myfile << "\n" << provas;
				myfile << "\n" << wins;
				myfile << "\n" << empate;
				myfile << "\n" << p_total;

			} else cout << "Não foi possivel abrir o arquivo";

			myfile.close();
		}

	} else if (resposta == 5){

		string formato;
		string local;
		int dist;
		int numero;


		cout << "Qual o tamanho da pista?" << endl;
		cout << "Para uma corrida mais rapida, digite um numero de 0 a 100" << endl;
		cin >> dist;

		cin.ignore();
		cout << "Qual o formato da pista?" << endl;
		cout << "Por exemplo: circulo, retangulo..." << endl;
		getline (cin, formato);

		cout << "Onde essa pista se localiza?" << endl;
		getline(cin, local);

		cout << "Qual o identificador da pista?" << endl;
		cin >> numero;

		Pista *salvo = new Pista(dist, formato, local, numero);
		aux = info.adc_pista(salvo);
		delete salvo;

		if (aux == 1){
			ofstream myfile;
			myfile.open("pista.txt", ios::out | ios::app);

			if (myfile.is_open()){
				myfile << "\n" << numero;
				myfile << "\n" << local;
				myfile << "\n"  << formato;
				myfile << "\n" << dist;
			} else {
				cout << "Não foi possivel abrir o arquivo";
			}

			} else {
				cout << "Resposta invalida" << endl;			
			}

			myfile.close();

		}
	return 0;
}
