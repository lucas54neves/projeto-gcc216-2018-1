/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém as classes;
*/

#ifndef TRABALHOED_H
#define TRABALHOED_H

#include <iostream>
#define TAM_BLOCO 16

using namespace std;

void Menu ();

struct Deuses {
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200];
};

typedef Deuses Dado;

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
		TabelaH (unsigned int capsup = 100);
		~TabelaH ();
		void Insere (Dado* all);
		void Remove (int ident);
		void Percorre ();
	protected :
		Noh** mElementos;
		unsigned int mCapacidade;

};

#endif
