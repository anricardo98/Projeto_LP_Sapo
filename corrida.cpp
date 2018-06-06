#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "sapo.hpp"
#include "pista.hpp"
#include "corrida.hpp"
using namespace std;

Corrida::Corrida(){

}


int Corrida::adc_sapo(Sapo *frog){
	vector<Sapo*>::iterator analise;
	int aux = 0;
	int aux2 = 0;

	for (analise = saparia.begin(); analise != saparia.end(); analise++){
		if (((*analise)->getNome().compare(frog->getNome())) == 0 && (*analise)->getIdent() == frog->getIdent()){
			aux = 1;
		}

		if ((*analise)->getIdent() == frog->getIdent()){
		 	aux = 2;
		} 
	}

	if (aux == 0){
		saparia.push_back(frog);
		aux2 = 1;
	} else if (aux == 1){
		cout << "O sapo ja foi inicializado antes" << endl;
	} else if (aux == 2){
		cout << "Escolha outro identificador" << endl;
	}

	return aux2;
}

int Corrida::adc_pista(Pista *runway){
	vector<Pista*>::iterator analise2;
	int aux = 0;
	int aux2 = 0;

	for (analise2 = pistas.begin(); analise2 != pistas.end(); analise2++){
		if ((*analise2)->getNumero() == runway->getNumero()){
			aux = 1;
		}
	}

	if (aux == 0){
		pistas.push_back(runway);
		aux2 = 1;
	}

	else {
		cout << "O identificador ja foi utilizado antes" << endl;
	}

	return aux2;
}

void Corrida::stats_sapo(){
	vector<Sapo*>::iterator filtro;
	int i = 0;

	cout << "As estatisticas dos sapos são as seguintes" << endl;

	for (filtro = saparia.begin(); filtro != saparia.end(); filtro++){
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

	for (filtro2 = pistas.begin(); filtro2 != pistas.end(); filtro2++){
		cout << endl << "Pista " << pistas[i]->getNumero() << endl;
		cout << "Formato: " << pistas[i]->getFormato() << endl;
		cout << "Local: " << pistas[i]->getLocal() << endl;
		cout << "Tamanho: " << pistas[i]->getDist() << endl;
		i++;
	}	

}

void Corrida::run(){
	int resposta;
	unsigned int quant = 0;
	int aux = -1;
	vector<Pista*>::iterator filtro3;
	vector<Sapo*>::iterator filtro4;
	static int dist_corrida;
	unsigned int i = 0;
	int soma;
	int pulo;
	int aleatorio;
	int posicao = 1;
	int aux3 = 0;

	cout << "Digite o identificador da pista em que você deseja realizar a corrida" << endl;
	cin >> resposta;

	for (filtro3 = pistas.begin(); filtro3 != pistas.end(); filtro3++){
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
		
		i = 0;

		cout << "Sapos inscritos na corrida" << endl;

		for (filtro4 = saparia.begin(); filtro4 != saparia.end(); filtro4++){
			cout << "Sapo: " << saparia[i]->getNome() << endl;
			cout << "Identificador: " << saparia[i]->getIdent() << endl << endl;
			i++;
		}

		cout << "Digite '1' para iniciar a corrida" << endl;
		cin >> resposta;

		if (resposta == 1){
			vector<Sapo*> vetor;

			for (i = 0; i < saparia.size(); i++){
				saparia[i]->setDist(0);
				saparia[i]->setPulos(0);
			}

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

						saparia[i]->setP_Total(1 + saparia[i]->getP_Total());

						cout << "Sapo " << saparia[i]->getNome() << endl; 
						cout << "Pulo: "<< pulo << endl;
						cout << "Distancia do pulo: " << aleatorio << endl;
						cout << "Distancia percorrida: " << soma << endl <<endl;

						if (saparia[i]->getDist() >= dist_corrida){
							vetor.push_back(saparia[i]);
							quant++;
						}
					}
				}
			}

			cout << "Ranking" << endl;
			
			cout << "Posicao " << "1 " << vetor[0]->getNome() << endl;  

			for (i = 1; i < saparia.size(); i++){
				if (vetor[0]->getPulos() == vetor[i]->getPulos()){
					vetor[i]->setEmpate(1 + vetor[i]->getEmpate());
					aux3 = 1;
				} else{
					posicao++;
				} 
				
				cout << endl << "Posicao " << posicao << " " << vetor[i]->getNome() << endl;
				
			}

			if (aux3 == 1){
				vetor[0]->setEmpate(1 + vetor[0]->getEmpate());
			} else {
				vetor[0]->setWins(1 + vetor[0]->getWins());
			}
				

			ofstream myfile;
			myfile.open("sapo.txt");

			i = 0;

			if (myfile.is_open()){
				for (i = 0; i < vetor.size(); i++){
					myfile << "\n" << vetor[i]->getNome();
					myfile << "\n" << vetor[i]->getIdent();
					myfile << "\n" << vetor[i]->getPulos();
					myfile << "\n" << vetor[i]->getProvas();
					myfile << "\n" << vetor[i]->getWins();
					myfile << "\n" << vetor[i]->getEmpate();
					myfile << "\n" << vetor[i]->getP_Total();
				}


			} else {
				cout << "Impossivel abrir o arquivo";
			}

			myfile.close();

		}

		else {
			cout << "O valor digitado nao corresponde ao que foi pedido." << endl;
		}
	}

}
