#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "sapo.hpp"
#include "pista.hpp"
#include "corrida.hpp"
using namespace std;

/**
*@file corrida.cpp
*@brief Arquivo .cpp resposável pela realização das ações, seja para mostrar as estatisticas, realizar a adição de um novo elemento ou realizar a corrida em si.
*@author Andre Ricardo
*@since 02/06/2018
*@date 06/06/2018
*@version 2.0
*/

/*@brief Declaração do construtor do construtor padrão da classe Pista*/
Corrida::Corrida(){

}


/*@brief Método responsável por adicionar um sapo a lista de sapo já existentes*/
int Corrida::adc_sapo(Sapo *frog){ 
	unsigned int i; /*@brief Variárivel auxiliar do for*/

	/*@brief Verificação de se o sapo mandando já não foi inicializado anteriormente*/
	for (i = 0; i < saparia.size(); i++){ 
		/*@brief Caso o nome e o identificador sejam iguais, imprimirá a seguinte mensagem e terminará a função indicando que o sapo não foi adicionado ao vetor*/
		if ((saparia[i]->getNome().compare(frog->getNome())) == 0 && saparia[i]->getIdent() == frog->getIdent()){ 
			cout << "O sapo ja foi inicializado antes" << endl;
			return 0;
		}

		/*@brief Caso somente o identificador igual, imprimirá a seguinte mensagem e terminará a função indicando que o sapo não foi adicionado ao vetor*/
		if (saparia[i]->getIdent() == frog->getIdent()){
		 	cout << "Escolha outro identificador de sapo" << endl;
		 	return 0;
		} 
	}

	/*@brief Caso nenhum dos dois casos seja verdadeiro, adicionará o novo sapo ao vetor de todos os sapos*/
	this->saparia.push_back(frog);

	/*@brief Retornará 1, indicando que o sapo foi adicionado ao vetor */
	return 1;
}


/*@brief Método responsável por adicionar uma pista a lista de pistas já existentes*/
int Corrida::adc_pista(Pista *runway){
	unsigned int i; /*@brief Variável auxiliar do for*/

	/*@brief Verificação de se a pista mandando já não foi inicializado anteriormente*/
	for (i = 0; i < pistas.size(); i++){ 
		/*@brief Caso o identificador seja igual, imprimirá a seguinte mensagem e terminará a função indicando que a ṕista não foi adicionada ao vetor*/
		if (pistas[i]->getNumero() == runway->getNumero()){
		 	cout << "Indique outro identificador da pista" << endl;
		 	return 0;
		} 
	}

	/*@brief Caso seja falso, adicionará a nova pista ao vetor de todas as pistas*/
	this->pistas.push_back(runway);

	/*@brief Retornará 1, indicando que a pista foi adicionado ao vetor */
	return 1;

}

/*@brief Método responsável por imprimir as estatisticas de cada sapo*/
void Corrida::stats_sapo(){
	unsigned int i = 0; /*@brief Variável auxiliar do for*/

	cout << "As estatisticas dos sapos são as seguintes" << endl;

	/*@brief Impressão dos dados de cada sapo por meio da utilização de um for que passa por cada sapo presente no vetor*/
	for (i = 0; i < saparia.size(); i++){
		cerr << "Sapo: "<< saparia[i]->getNome() << endl;
		cout << "Identificador: "<< saparia[i]->getIdent() << endl;
		cout << "Pulos na ultima prova: "<< saparia[i]->getPulos() << endl;
		cout << "Numero de provas: " << saparia[i]->getProvas() << endl;
		cout << "Vitorias: " << saparia[i]->getWins() << endl;
		cout << "Empates: " << saparia[i]->getEmpate() << endl;
		cout << "Pulos totais na carreira: " << saparia[i]->getP_Total() << endl << endl;
	}

}


/*@brief Método responsável por imprimir as estatisticas de cada pista*/
void Corrida::stats_pista(){
	unsigned int i = 0; /*@brief Variável auxiliar do for*/

	/*@brief Impressão dos dados de cada pista por meio da utilização de um for que passa por cada pista presente no vetor*/
	for (i = 0; i < pistas.size(); i++){
		cout << endl << "Pista " << pistas[i]->getNumero() << endl;
		cout << "Formato: " << pistas[i]->getFormato() << endl;
		cout << "Local: " << pistas[i]->getLocal() << endl;
		cout << "Tamanho: " << pistas[i]->getDist() << endl;
	}	

}

/*@brief Método responsável pela realização da corrida e disponibilização do ranking*/
void Corrida::run(){
	int resposta; /*@brief Variável que recebe a resposta do usuário quando este indica o identificador da pista onde será disputada a corrida*/
	unsigned int quant = 0; /*@brief Variável auxiliar que armazena a quantidade de sapos que acabaram a corrida*/
	int aux = -1; /*@brief Variável auxiliar que indica se a pista está */
	static int dist_corrida; /*@brief Variável que armazena o tamanho da pista*/
	unsigned int i = 0; /*@brief Variável auxiliar utilizada no for*/
	int soma; /*@brief Variável que recebe a soma da distância percorrida com o último pulo */
	int pulo; /*@brief Variavel que armazena a nova quantidade de pulos*/
	int aleatorio; /*@brief Variável que recebe o valor recebido pelo randomico*/
	int posicao = 1; /*@brief Variável auxiliar que ajuda na identificação da posição de cada sapo */
	int j = 0; /*@brief Variável auxiliar*/
	int aux3 = 0; /*@brief Variável auxiliar que ajuda na determinação do empate*/

	/*@brief Determinação da pista que será utilizada na corrida*/
	cout << "Digite o identificador da pista em que você deseja realizar a corrida" << endl;
	cin >> resposta;

	/*@brief Verificação se a pista escolhida está entre as indicadas, caso esteja, a variável aux sairá como 0*/
	for (i = 0; i < pistas.size(); i++){
		if (pistas[i]->getNumero() == resposta){
			dist_corrida = pistas[i]->getDist();
			aux = 0;
		}
	}

	/*@brief Caso a pista não esteja entre as indicadas, imprimirá a seguinte mensagem*/
	if (aux == -1){
		cout << "O numero digitado não corresponde a nenhuma pista listada" << endl;
	} else { /*@brief Caso esteja*/
		
		cout << "Sapos inscritos na corrida" << endl;

		/*@brief Imprimirá o nome e o identificador de cada sapo*/
		for (i = 0; i < saparia.size(); i++){
			cout << "Sapo: " << saparia[i]->getNome() << endl;
			cout << "Identificador: " << saparia[i]->getIdent() << endl << endl;
		}

		/*@brief Esperará pela iniciação da corrida pelo usuário*/
		cout << "Digite '1' para iniciar a corrida" << endl;
		cin >> resposta;

		if (resposta == 1){ /*@brief Se ele apertar o botão correto*/
			vector<Sapo*> vetor; /*@brief Criará um vetor auxiliar, que armazenará o resultado da corrida*/

			/*@brief Resetando o valor da distância percorrida e do número de pulos de cada sapo, para iniciar a corrida corretamente*/
			for (i = 0; i < saparia.size(); i++){
				saparia[i]->setDist(0); 
				saparia[i]->setPulos(0); 
			}

			while (quant < saparia.size()){ /*@brief Enquanto a quantidade de sapos que acabaram a corrida for menor do que os que entraram, realizará a ação*/
				for (i = 0; i < saparia.size(); i++){ /*@brief Realizando a ação para cada sapo*/
					if (saparia[i]->getDist() < dist_corrida){ /*@brief Verificando se o sapo ainda não completou a corrida*/
						
						/*@brief Aquisição da distância percorrida em um pulo por meio do uso do rand()*/
						aleatorio = 1 + rand()%10;
						soma = saparia[i]->getDist();
						soma = soma + aleatorio;
						saparia[i]->setDist(soma);

						/*@brief Soma 1 a quantidade de pulos anterior*/
						pulo = saparia[i]->getPulos();
						pulo++;
						saparia[i]->setPulos(pulo);

						/*@brief Adiciona 1 a quantidade de pulos totais*/
						saparia[i]->setP_Total(1 + saparia[i]->getP_Total());

						/*@brief Impressão das ações do sapo, indicando o seu nome, identificador, quantidade de pulos na corrida, a distancia do ultimo pulo 
						e a distância de total percorrida*/
						cout << "Sapo " << saparia[i]->getNome() << endl; 
						cout << "Identificador " << saparia[i]->getIdent() << endl;
						cout << "Pulo: "<< pulo << endl;
						cout << "Distancia do pulo: " << aleatorio << endl;
						cout << "Distancia percorrida: " << soma << endl <<endl;

						/*@brief Verificação de que se com o último pulo, o sapo acabou a corrida, se sim, entra na função */
						if (saparia[i]->getDist() >= dist_corrida){
							saparia[i]->setProvas(1 + saparia[i]->getProvas()); /*@brief Aumenta o número de provas disputada pelo sapo*/
							vetor.push_back(saparia[i]); /*@brief adiciona o sapo ao vetor auxiliar na sua última posição*/
							quant++; /*@brief Adiciona um a quantidade de sapos que acabaram a corrida*/
						}
					}
				}
			}

			/*@brief Faremos a impressão do ranking, imprimindo inicialmente o sapo na primeira posição do vetor*/
			cout << "Ranking" << endl;
			cout << "Posicao " << "1 " << vetor[0]->getNome() << " " << vetor[0]->getIdent() << endl; 
			cout << "Numero de pulos:" << vetor[0]->getPulos() << endl;  

			/*@brief Passagem por todos os elementos do vetor por meio de um for*/
			for (i = 1; i < saparia.size(); i++){
				/*@brief verificando se o sapo empatou com o primeiro colocado*/
				if (vetor[0]->getPulos() == vetor[i]->getPulos()){
					/*@brief Se sim, adiciona 1 aos número de empates e indica que se deve colocar um no empate do primeiro colocado*/
					vetor[i]->setEmpate(1 + vetor[i]->getEmpate());
					aux3 = 1;
			
				} else if (vetor[j]->getPulos() == vetor[i]->getPulos()){ /*@brief Se empatou com algum outro sapo*/
					/*@brief Ele recebe a mesma posição do anterior*/
					posicao = posicao;
			
				} else { /*@brief Se nao empatou com algum outra posição*/
					/*@brief indica o sapo atual e aumenta 1 posição em relação a posição anterior*/
					j = i;
					posicao++;
				} 
				
				/*@brief Imprime a posição do sapo junto ao seu nome e identificador*/
				cout << endl << "Posicao " << posicao << " " << ": " << vetor[i]->getNome() << " " << vetor[i]->getIdent() << endl;
				cout << "Numero de pulos:" << vetor[i]->getPulos() << endl;
				
			}


			if (aux3 == 1){ /*@brief Se o primeiro lugar empatou com alguem, aumentará um em seu valor de empates*/
				vetor[0]->setEmpate(1 + vetor[0]->getEmpate());
			} else {
				/*@brief Se não empatou, o primeiro lugar receberá mais um em seu numero de vitórias*/
				vetor[0]->setWins(1 + vetor[0]->getWins());
			}
				

			/*@brief Imprime no arquivo o dados atualizados de cada sapo, utilzando a lógica já utilizada anteriormente no arquivo*/
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
