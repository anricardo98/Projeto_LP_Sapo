#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include "corrida.hpp"
#include "pista.hpp"
#include "sapo.hpp"

int main(){

	int loop = 1;
	int resposta; 

	Corrida info;


	while (loop == 1){
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
			info.run();

		} else if (resposta == 4){

			string nome;
			int ident;
			int pulos;
			int provas;
			int wins;
			int empate;
			int p_total;

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
			info.adc_sapo(salvo);
			delete salvo;

			ofstream myfile;
			myfile.open("sapo.txt", ios::out | ios::app);

			if (myfile.is_open()){
				myfile << "\n";
				myfile << "\nSapo: " << nome;
				myfile << "\nIdenficador: " << ident;
				myfile << "\nPulos: " << pulos;
				myfile << "\nProvas: " << provas;
				myfile << "\nVitorias: " << wins;
				myfile << "\nEmpates: " << empate;
				myfile << "\nPulos_Totais: " << p_total;

			} else cout << "Não foi possivel abrir o arquivo";

			myfile.close();

		} else if (resposta == 5){

			string formato;
			string local;
			static int dist;
			int numero;


			cout << "Qual o tamanho da pista?" << endl;
			cout << "Para uma corrida mais rapida, digite um numero de 0 a 100" << endl;
			cin >> dist;

			cin.ignore();
			cout << "Qual o formato da pista?" << endl;
			cout << "Por exemplo: circulo, retangulo..." << endl;
			getline (cin, formato);

			cin.ignore();
			cout << "Onde essa pista se localiza?" << endl;
			getline(cin, local);

			cout << "Qual o identificador da pista?" << endl;
			cin >> numero;

			Pista *salvo = new Pista(dist, formato, local, numero);
			info.adc_pista(salvo);
			delete salvo;

			ofstream myfile;
			myfile.open("pista.txt", ios::out | ios::app);

			if (myfile.is_open()){
				myfile << "\n";
				myfile << "\nPista: " << numero;
				myfile << "\nLocal: " << local;
				myfile << "\nFormato: " << formato;
				myfile << "\nTamanho: " << dist;
			} else cout << "Não foi possivel abrir o arquivo";

			myfile.close();

		} else {
			cerr << "Resposta invalida" << endl;			
		}


		cerr << "Deseja realizar mais algum processo" << endl;
		cerr << "Digite '1' se sim" << endl;
		cin >> loop;
	}


	return 0;
}
