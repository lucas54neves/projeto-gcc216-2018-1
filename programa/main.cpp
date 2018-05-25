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
	cout << "Sistema de cadastro em Hashing Extensível" << endl;
	int opcao;
	TabelaH* tabelaCadastro =  new TabelaH;
	tabelaCadastro->LeTabelaArquivo();
	do {
		Menu();
		cin >> opcao;
		switch (opcao) {
			case 0:
			{
				cout << "Programa terminado." << endl;
				
				break;
			}
			case 1:
			{
				// Subprograma para inserir um novo objeto no arquivo
				// InsereDados(tabelaCadastro);

				Dado deus;
				// Leitura de Dados:
				cout << "Entre com o id do deus:" << endl;
				cin >> deus.id;
				cin.ignore();
				cout << "Entre com o nome do deus:" << endl;
				cin.getline(deus.nome, 50);
				cout << "Entre com o domínio do deus:" << endl;
				cin.getline(deus.dominio, 10);
				cout << "Entre com a biografia do deus:" << endl;
				cin.getline(deus.biografia, 200);
				
				tabelaCadastro->InsereTabela(deus);

				break;
			}
			case 2:
			{
				// Subprograma para remover um objeto do arquivo
				RemoveDados();
				
				break;
			}
			case 3:
			{
				// Subprograma para consultar um objeto no arquivo
				ConsultaDados();
				
				break;
			}
			case 4:
			{
				// Subprograma para imprimir todo o conteúdo do arquivo, na ordem de armazenamento
				ImprimeArquivoOrdem();
				
				break;
			}
			case 5:
			{
				// Subprograma para imprimir os registros de um dado bloco de modo ordenado, caso o
				// armazenamento não seja feito de forma ordenada
				ImprimeBlocoOrdem();
				
				break;
			}
			default:
			{
				cout << "Opção não cadastrada! Tente novamente." << endl;
				
				break;
			}
		}
	} while (opcao != 0);
	delete tabelaCadastro;
	return 0;
}
