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

	int resposta; /*@brief Variável que indicará o que o usuário deseja fazer*/
	/*@brief Declaração das variáveis que receberão os dados de cada sapo do arquivo "sapo.txt"*/
	string aux_nome; 
	int aux_ident;
	int aux_pulo;
	int aux_empate;
	int aux_wins;
	int aux_p_total;
	int aux_provas;
	/*@brief Declaração das variáveis que receberão os dados de cada pista do arquivo "pista.txt"*/
	int aux_dist;
	string aux_local;
	string aux_formato;
	int aux_numero;
	int aux; /*@brief Declaração de uma variável que indicará se adiciona um sapo ou pista ao seu arquivo*/
	
	Corrida info; /*@brief Chamada de uma variável "info" do tipo Corrida*/

	/*@brief Processo de leitura do arquivo "sapo.txt" com todos os sapos mostrados anteriormente*/
	ifstream myfile; /*@brief Declaração de myfile do tipo ifstream*/
	myfile.open("sapo.txt");  /*@brief Indicação do arquivo que será lido*/

	if(myfile.is_open()){  /*@brief Verificação de se o arquivo está aberto*/
		while (!myfile.eof()){  /*@brief Caso esteja aberto, realizará a leitura até o final do arquivo "sapo.txt"*/

			/*@brief Indicação do processo de leitura, pegando os dados de acordo com a ordem pre-determinada*/
			/*@brief Ordem: nome, identificador, pulos da corrida passada, provas participadas, vitórias, empates e pulos totais*/		
			myfile >> aux_nome;
			myfile >> aux_ident;
			myfile >> aux_pulo;
			myfile >> aux_provas;
			myfile >> aux_wins;
			myfile >> aux_empate;
			myfile >> aux_p_total;

			 /*@brief Declaração de um sapo com as informações obtidas do arquivos*/
			Sapo *frog_ = new Sapo(aux_nome, aux_ident, aux_pulo , aux_provas, aux_wins, aux_empate, aux_p_total);

			aux = info.adc_sapo(frog_); /*@brief Adição do sapo declarado ao vetor com todos os sapos*/
		}

	} else { /*@brief Caso o arquivo não esteja aberto, imprimirá essa mensagem*/
		cout << "Impossivel abrir arquivo dos sapos" << endl;
	
	}

	myfile.close(); /*@brief Fechando o arquivo "sapo.txt"*/

	/*@brief Processo de leitura do arquivo "pista.txt" com todas as pistas mostradas anteriormente*/
	ifstream myfile2; /*@brief Declaração de myfile2 do tipo ifstream*/
	myfile2.open("pista.txt"); /*@brief Indicação do arquivo que será lido*/

	if(myfile2.is_open()){ /*@brief Verificação de se o arquivo está aberto*/
		while (!myfile2.eof()){ /*@brief Caso esteja aberto, realizará a leitura até o final do arquivo "pista.txt"*/

			/*@brief Indicação do processo de leitura, pegando os dados de acordo com a ordem pre-determinada*/
			/*@brief Ordem: Identificador da pista, local da pista, formato dela, tamanho da pista*/		
			myfile2 >> aux_numero;
			myfile2 >> aux_local;
			myfile2 >> aux_formato;
			myfile2 >> aux_dist;

			/*@brief Declaração de uma pista com as informações obtidas do arquivos*/
			Pista *runway_ = new Pista(aux_dist, aux_local, aux_formato, aux_numero);

			aux = info.adc_pista(runway_); /*@brief Adição da pista declarada ao vetor com todos as pistas*/
		}

	} else { /*@brief Caso o arquivo não esteja aberto, imprimirá essa mensagem*/
		cout << "Impossivel abrir arquivo das pistas" << endl;
	
	}

	myfile2.close(); /*@brief Fechando o arquivo "sapo.txt"*/
	
	/*@brief Impressão da tela perguntando o que o usuário deseja fazer e recepção da resposta dele*/
	cerr << "O que voce deseja fazer?" << endl;
	cerr << "Digite '1' para ver as estatisticas dos sapos" << endl;
	cerr << "Digite '2' para ver as estatisticas das pistas" << endl;
	cerr << "Digite '3' para iniciar uma corrida" << endl;
	cerr << "Digite '4' para criar um sapo" << endl;
	cerr << "Digite '5' para criar uma pista" << endl;
	cin >> resposta;

	if (resposta == 1){ /*@brief Caso deseje ver as estatisticas dos sapos, chamará a função indicada*/

		info.stats_sapo(); /*@brief Função responsável pela mostragem das estatisticas dos sapos*/

	} else if (resposta == 2){ /*@brief Caso deseje ver as estatisticas das pistas, chamará a função indicada*/

		info.stats_pista(); /*@brief Função responsável pela mostragem das estatisticas das pistas*/

	} else if (resposta == 3){ /*@brief Caso deseje realizar a corrida, entrará nessa etapa*/

		srand(time(NULL)); /*@brief Reiniciará o seed do randomico*/
		info.run(); /*@brief Função responsável pela realização da corrida*/

	} else if (resposta == 4){ /*@brief Caso em que se deseja criar um novo sapo*/

		/*@brief Declaração das variavéis que irão receber os dados do sapo, indicados pelo usuário*/
		string nome;
		int ident;
		int pulos;
		int provas;
		int wins;
		int empate;
		int p_total;

		/*@brief Processo de recebimento do nome*/
		cin.ignore();
		cout << "Qual o nome do sapo?" << endl;
		getline (cin, nome);

		/*@brief Processo de recebimento do identificador do sapo*/
		cout << "Qual o identificador do sapo?" << endl;
		cin >> ident;

		/*@brief Processo de recebimento do número de pulos da última corrida*/
		cout << "Quantos pulos ele deu na ultima corrida?" << endl;
		cin >> pulos;

		/*@brief Processo de recebimento do número de provas*/
		cout << "Quantas provas ele ja disputou?" << endl;
		cin >> provas;

		/*@brief Processo de recebimento de quantas provas o sapo ganhou*/
		cout << "Quantas provas ele ganhou?" << endl;
		cin >> wins;

		/*@brief Processo de recebimento do número de provas empatadas*/
		cout << "Quantas provas ele empatou?" << endl;
		cin >> empate;

		/*@brief Processo de recebimento do número de pulos na carreira*/
		cout << "Quantos pulos ele deu em toda sua carreira" << endl;
		cin >> p_total;

		if ((empate + wins) <= provas && pulos <= p_total){ /*@brief Verificando se as informações são possíveis*/
			/*@brief Caso seja, criamos o sapo salvo com as informações dadas*/
			Sapo *salvo = new Sapo(nome, ident, pulos, provas, wins, empate, p_total);
			aux = info.adc_sapo(salvo); /*@brief Adição do sapo a lista de todos os sapos*/
			delete salvo; /*@brief Deletando o ponteiro salvo*/

			/*@brief Se o sapo for adicionado a lista, ele retornará 1, se isso acontecer adicionaremos o sapo ao arquivo*/
			if (aux == 1){ 
				ofstream myfile; /*@brief Declaração do arquivo myfile do tipo ofstream*/

				/*@brief Abertura do arquivo sapo.txt e indicação de que a adição do sapo no arquivo será feita no final dele*/
				myfile.open("sapo.txt", ios::out | ios::app); 

				/*@brief Se o arquivo estiver aberto, serão colocados as informações do sapo no arquivo, seguindo a ordem indicada*/
				if (myfile.is_open()){	
					myfile << "\n" << nome;
					myfile << "\n" << ident;
					myfile << "\n" << pulos;
					myfile << "\n" << provas;
					myfile << "\n" << wins;
					myfile << "\n" << empate;
					myfile << "\n" << p_total;

				} else { /*@brief Se não estiver aberto, mostrará a seguinte mensagem*/
					cout << "Não foi possivel abrir o arquivo" << endl;
				}

				myfile.close(); /*@brief Fechando o arquivo "sapo.txt"*/
			} else { /*@brief Se o aux != 1, mostrará a seguinte mensagem*/
				cout << "Resposta invalida" << endl;			
			}

		} else {  /*@brief Caso as informações nao sejam possíveis*/
			cerr << "Informações desconexas, tente novamente" << endl;
		}

	} else if (resposta == 5){ /*@brief Caso em que se deseja criar uma nova pista*/

		/*@brief Declaração das variavéis que irão receber os dados da pista, indicados pelo usuário*/
		string formato;
		string local;
		int dist;
		int numero;

		/*@brief Processo de recebimento do tamanho da pista*/
		cout << "Qual o tamanho da pista?" << endl;
		cout << "Para uma corrida mais rapida, digite um numero de 0 a 100" << endl;
		cin >> dist;

		/*@brief Processo de recebimento do formato da pista*/
		cin.ignore();
		cout << "Qual o formato da pista?" << endl;
		cout << "Por exemplo: circulo, retangulo..." << endl;
		getline (cin, formato);

		/*@brief Processo de recebimento do local onde a pista se localiza*/
		cout << "Onde essa pista se localiza?" << endl;
		getline(cin, local);

		/*@brief Processo de recebimento do identificador da pista*/
		cout << "Qual o identificador da pista?" << endl;
		cin >> numero;

		/*@brief Criamos a pista "salvo" com as informações dadas*/
		Pista *salvo = new Pista(dist, formato, local, numero);

		aux = info.adc_pista(salvo); /*@brief Adição da pista a lista de todas as pistas*/
		delete salvo; /*@brief Deletando o ponteiro salvo*/

		/*@brief Se a pista for adicionada a lista, ele retornará 1, se isso acontecer adicionaremos a pista ao arquivo*/
		if (aux == 1){ 
			ofstream myfile; /*@brief Declaração do arquivo myfile do tipo ofstream*/

			/*@brief Abertura do arquivo pista.txt e indicação de que a adição da pista no arquivo será feita no final dele*/
			myfile.open("pista.txt", ios::out | ios::app);

			/*@brief Se o arquivo estiver aberto, serão colocados as informações da pista no arquivo, seguindo a ordem indicada*/
			if (myfile.is_open()){
				myfile << "\n" << numero;
				myfile << "\n" << local;
				myfile << "\n"  << formato;
				myfile << "\n" << dist;
			} else { /*@brief Se não estiver aberto, mostrará a seguinte mensagem*/
				cout << "Não foi possivel abrir o arquivo";
			}

			myfile.close(); /*@brief Fechando o arquivo "pista.txt"*/

		} else { /*@brief Se o aux != 1, mostrará a seguinte mensagem*/
			cout << "Resposta invalida" << endl;			
		}
		
	}

	return 0; /*@brief Termino do programa*/
}
