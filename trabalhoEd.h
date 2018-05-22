/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém as classes;
*/

#ifndef TRABALHOED_H
#define TRABALHOED_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#define TAM_BLOCO 16

using namespace std;

struct Deuses {
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200];
};

typedef Deuses Dado;

int FuncaoHash (Dado* deus);

class TabelaH;

class Noh {
	friend class TabelaH;
	public:
		Noh ();
		~Noh ();
	protected:
		Noh* mProximo;
		Dado mConteudo;
};

class TabelaH {
	public:
		TabelaH (unsigned int cap = TAM_BLOCO);
		~TabelaH ();
		void Insere (Dado* deus);
		bool Existe (Dado* deus);
		void Remove (int id);
		void Imprime ();
		int ConverteBinario4Bits (Dado* deus);
	protected :
		Noh** mElementos;
		unsigned int mCapacidade;
};

void InserirDados (TabelaH* tabelaCadastro);
void Menu ();
int ConverteDecimal (int binario);

#endif
