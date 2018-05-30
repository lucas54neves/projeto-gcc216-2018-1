/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém as execuções;
*/

/*
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200]
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include "metodos.hpp"

// Constantes
#define CAP_BLOCO 4
#define CAP_TABELA 16

using namespace std;

int main() {
	cout << "Sistema de cadastro: " << endl;
	int opcao;
	char questao;

	// Criação da tabela hash
	TabelaH* tabelaCadastro =  new TabelaH;

	// Leitura das informações de uma tabela, caso exista uma no arquivo uppsala.txt
	tabelaCadastro->LeTabelaArquivo();
	
	// Loop principal do programa
	do {
		Menu();
		cin >> opcao;
		// Estrutura seletiva para a escola das opções
		switch (opcao) {
			case 0:
			{
				cout << "Programa terminado." << endl;
				
				break;
			}
			case 1:
			{
				// Subprograma para inserir um novo objeto no arquivo
				InsereDados(tabelaCadastro);
				
				cout << endl << "Deseja continuar no programa ? [y/n] " << endl;
				cin >> questao;
				if (questao == 'n') {
					opcao = 0; 
				}
				system("clear");

				break;
			}
			case 2:
			{
				// Subprograma para remover um objeto do arquivo.
				RemoveDados(tabelaCadastro);
				cout << endl << "Deseja continuar no programa ? [s/n] " << endl;
				cin >> questao;
				if (questao == 'n') {
					opcao = 0; 
				}
				system("clear");

				break;
			}
			case 3:
			{
				// Subprograma para consultar um deus no arquivo.
				ConsultaDados(tabelaCadastro);
				cout << endl << "Deseja continuar no programa ? [s/n] " << endl;
				cin >> questao;
				if (questao == 'n') {
					opcao = 0; 
				}
				system("clear");

				break;
			}
			case 4:
			{
				// Subprograma para imprimir todo o conteúdo do arquivo, na ordem de armazenamento.
				ImprimeArquivoOrdem();
				cout << endl << "Deseja continuar no programa ? [s/n] " << endl;
				cin >> questao;
				if (questao == 'n') {
					opcao = 0; 
				}
				system("clear");
			
				break;
			}
			case 5:
			{
				// Subprograma para imprimir todo o bloco com os deuses ordenados.
				ImprimeBlocoOrdem(tabelaCadastro);
				cout << endl << "Deseja continuar no programa ? [y/n] " << endl;
				cin >> questao;
				if (questao == 'n') {
					opcao = 0; 
				}
				system("clear");
				
				break;
			}
			default:
			{
				system("clear");
				cout << "Opção não cadastrada! Tente novamente." << endl;
				
				break;
			}
		}
	} while (opcao != 0);
	delete tabelaCadastro;
	return 0;
}
