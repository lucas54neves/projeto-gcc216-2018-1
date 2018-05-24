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
#include "trabalhoEd.h"
#define CAP_TAB 16
#define CAP_BLOCO 4

using namespace std;

int main() {
	cout << "Sistema de cadastro em Hashing Extensível" << endl;
	int opcao;
	int i = 0;
	TabelaH* tabelaCadastro =  new TabelaH;
	ifstream leituraTH;
  	leituraTH.open("Enderecos.txt");
  	if (!leituraTH.eof()) {
  		int posTH, byte;
  		while (!leituraTH.eof()) {
  			leituraTH >> posTH >> byte;
  			tabelaCadastro.Insere(posTH, byte);
  		}
  	}
	
	do {
		Menu();
		cin >> opcao;
		switch (opcao) {
			case 0:
			{
				cout << "Programa terminado." << endl;
				system("clear");
				break;
			}
			case 1:
			{
				// Subprograma para inserir um novo objeto no arquivo
				InsereDados(tabelaCadastro);
				system("clear");
				break;
			}
			case 2:
			{
				// Subprograma para remover um objeto do arquivo
				RemoveDados();
				system("clear");
				break;
			}
			case 3:
			{
				// Subprograma para consultar um objeto no arquivo
				ConsultaDados();
				system("clear");
				break;
			}
			case 4:
			{
				// Subprograma para imprimir todo o conteúdo do arquivo, na ordem de armazenamento
				ImprimeArquivoOrdem();
				system("clear");
				break;
			}
			case 5:
			{
				// Subprograma para imprimir os registros de um dado bloco de modo ordenado, caso o
				// armazenamento não seja feito de forma ordenada
				ImprimeBlocoOrdem();
				system("clear");
				break;
			}
			default:
			{
				cout << "Opção não cadastrada! Tente novamente." << endl;
				system("clear");
				break;
			}
		}
	} while (opcao != 0);
	delete tabelaCadastro;
	return 0;
}
