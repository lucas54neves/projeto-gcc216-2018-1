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

using namespace std;

int main() {
	cout << "Sistema de cadastro em Hashing Extensível" << endl;
	int opcao;
	int i = 0;
	TabelaH tabelaCadastro;
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
				InserirDados(tabelaCadastro);
				cout << "Funciona agora !!!" << endl;
				break;
			}
			case 2:
			{
				// Subprograma para remover um objeto do arquivo

				break;
			}
			case 3:
			{
				// Subprograma para consultar um objeto no arquivo
				break;
			}
			case 4:
			{
				tabelaCadastro.Imprime();
				// Subprograma para imprimir todo o conteúdo do arquivo, na ordem de armazenamento
				break;
			}
			case 5:
			{
				// Subprograma para imprimir os registros de um dado bloco de modo ordenado, caso o
				// armazenamento não seja feito de forma ordenada
				break;
			}
			default:
			{
				cout << "Opção não cadastrada! Tente novamente." << endl;
				break;
			}
		}
	} while (opcao != 0);
	return 0;
}
