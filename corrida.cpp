#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sapo.hpp"
#include "pista.hpp"
using namespace std;

Corrida::Corrida(){

}

void Corrida::adc_sapo(Sapo *frog){
	vector<Sapo*>::iterator analise;
	int aux = 0;

	for (analise = saparia.begin(); analise != saparia.end(); analise++){
		if (((*analise)->getNome().compare(frog->getNome())) == 0 && (*analise)->getIdent() == frog->getIdent()){
			aux = 1;
		}
	}

	if (aux == 0){
		saparia.push_back(frog);
	}

	else {
		cout << "O sapo ja foi inicializado antes" << endl;
	}

}

void Corrida::adc_pista(Pista *runway){
	vector<Pista*>::iterator analise2;
	int aux = 0;

	for (analise2 = pistas.begin(); analise2 != pistas.end(); analise2++){
		if ((*analise2)->getNumero() == runway->getNumero()){
			aux = 1;
		}
	}

	if (aux == 0){
		pistas.push_back(runway);
	}

	else {
		cout << "A pista ja foi inicializada antes" << endl;
	}
}

void Corrida::stats_sapo(){
	vector<Sapo*>::iterator filtro;
	int i = 0;

	cout << "As estatisticas dos sapos são as seguintes" << endl;

	for (filtro = saparia.begin(); filtro != saparia.end(); saparia++){
		cout << "Sapo: "<< saparia[i]->getNome() << endl;
		cout << "Identificador: "<< saparia[i]->getIdent() << endl;
		cout << "Pulos na ultima prova: "<< saparia[i]->getPulos() << endl;
		cout << "Numero de provas: " << saparia[i]->getProvas() << endl;
		cout << "Vitorias: " << saparia[i]->getWins() << endl;
		cout << "Empates: " << saparia[i]->getEmpate() << endl;
		cout << "Pulos totais na carreira: " << saparia[i]->getP_Total() << endl << endl;
		i++;
	}

}

void Corrida::stats_pista(){
	vector<Pista*>::iterator filtro2;
	int i = 0;

	for (filtro = pistas.begin(); filtro != pistas.end(); pistas++){
		cout << "Pista " << pistas[i]->getNumero() << endl;
		cout << "Formato: " << pistas[i]->getFormato() << endl;
		cout << "Local: " << pistas[i]->getLocal() << endl;
		cout << "Tamanho: " << pistas[i]->getDist() << endl;
		i++;
	}	

}

void Corrida::run(){
	int resposta;
	int quant = 0;
	int aux = -1;
	vector<Pista*>::iterator filtro3;
	vector<Sapo*>::iterator filtro4;
	static int dist_corrida;
	int i = 0;

	cout << "Digite o numero da pista em que você deseja realizar a corrida" << endl;
	cin >> resposta;

	for (filtro3 = pistas.begin(); filtro != pistas.end(); filtro3++){
		if (pistas[i]->getNumero() == resposta){
			dist_corrida = pistas[i]->getDist();
			aux = 0;
		}
		i++;
	}

	if (aux == -1){
		cout << "O numero digitado não corresponde a nenhuma pista listada" << endl;
	}

	else {
		int soma;
		int pulo;
		i = 0;
		int aleatorio;
		cout << "Sapos inscritos na corrida" << endl;

		for (filtro4 = saparia.begin(); filtro4 != saparia.end(); filtro4++){
			cout << "Sapo: " << saparia[i]->getNome() << endl;
			cout << "Identificador: " << saparia[i]->getIdent() << endl << endl;
			i++;
		}

		cout << "Digite '1' para iniciar a corrida" << endl;
		cin >> resposta;

		if (resposta == 1){
			string vetor[saparia.size()];
			int vitoria;
			while (quant < saparia.size()){
				for (i = 0; i < saparia.size(); i++){
					if (saparia[i]->getDist() < dist_corrida){
						aleatorio = 1 + rand()%10;
						soma = saparia[i]->getDist();
						soma = soma + aleatorio;
						saparia[i]->setDist(soma);

						pulo = saparia[i]->getPulos();
						pulo++;
						saparia[i]->setPulos(pulo);

						saparia[i]->setP_Total(pulo + saparia[i]->getP_Total());

						cout << "Sapo " << saparia[i]->getNome() << endl; 
						cout << "Pulo: "<< pulo << endl;
						cout << "Distancia do pulo: " << aleatorio << endl;
						cout << "Distancia percorrida: " << soma << endl <<endl;

						if (saparia[i]->getDist() > dist_corrida){
							vetor[quant] = saparia[i]->getNome();
							if (quant == 0){
								vitoria = saparia[i]->getWins();
								vitoria++;
								saparia[i]->setWins(vitoria);
							}
							
							quant++;
						}
					}
				}
			}

			cout << "Ranking" << endl;

			for (i = 0; i < saparia.size(); i++){
				cout << i+1 << "º - " << vetor[i];
			}

			ofstream myfile;
			myfile.open("sapo.txt");

			i = 0;

			if (myfile.is_open()){
				for (filtro4 = saparia.begin(); filtro4 != saparia.end(); filtro4++){
					if (i > 0){
						myfile << "\n";
					}

					myfile << "\nSapo: " << (*filtro4)->getNome();
					myfile << "\nIdenficador: " <<  (*filtro4)->getIdent();
					myfile << "\nPulos: " <<  (*filtro4)->getPulos();
					myfile << "\nProvas: " <<  (*filtro4)->getProvas();
					myfile << "\nVitorias: " <<  (*filtro4)->getWins();
					myfile << "\nEmpates: " <<  (*filtro4)->getEmpate();
					myfile << "\nPulos_Totais: " <<  (*filtro4)->getP_Total();
					i++;
				}

				myfile.close();

			} else {
				cout << "Impossivel abrir o arquivo"
			}

		}

		else {
			cout << "O valor digitado nao corresponde ao que foi pedido." << endl;
		}
	}

}
