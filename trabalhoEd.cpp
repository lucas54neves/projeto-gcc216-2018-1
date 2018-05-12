/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém as implementações das classes;
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include "trabalhoEd.h"

/*
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200]
*/
int FuncaoHash (Dado* deus) {
	int h = deus->id % TAM_BLOCO;

	return h;
}

Noh::Noh () {
	mProximo = NULL;
	mConteudo.id = -1;
	mConteudo.nome[50] = ' ';
	mConteudo.dominio[10] = ' ';
	mConteudo.biografia[200] = ' ';
}

Noh::~Noh () {
	mProximo = NULL;
	mConteudo.id = -1;
	mConteudo.nome[50] = ' ';
	mConteudo.dominio[10] = ' ';
	mConteudo.biografia[200] = ' ';
}

TabelaH::TabelaH (unsigned int cap) : mCapacidade (cap) {
	mElementos = new Noh*[cap];
	for (int i = 0; i < cap; ++i) {
		mElementos[i] = NULL;
	}
}

TabelaH::~TabelaH () {
	for (int i = 0; i < mCapacidade; ++i) {
		Noh* aquelequemorre = mElementos[i];
		while (aquelequemorre != NULL) {
			Noh* aux = aquelequemorre;
			aquelequemorre = aquelequemorre->mProximo;
			delete aux;
		}
	}
	delete[] mElementos;
}

void TabelaH::Insere (Dado* deus) {
	int h;
	h = FuncaoHash(deus);

	if (Existe(deus)) {
		cout << "O item já se encontra na tabela" << endl;
	} else {
		if (mElementos[h] == NULL) {
			mElementos[h] = new Noh;
			mElementos[h]->mConteudo.id = deus->id;
			strncpy(mElementos[h]->mConteudo.nome, deus->nome, 49);
			mElementos[h]->mConteudo.nome[50] = '\0';
			strncpy(mElementos[h]->mConteudo.dominio, deus->dominio, 9);
			mElementos[h]->mConteudo.dominio[10] ='\0';
			strncpy(mElementos[h]->mConteudo.biografia, deus->biografia, 199);
			mElementos[h]->mConteudo.biografia[200] = '\0';
		} else {
			Noh* atual = mElementos[h];

			while (atual->mProximo != NULL) {
				atual = atual->mProximo;
			}

			Noh* novo = new Noh;
			novo->mConteudo.id = deus->id;
			strncpy(novo->mConteudo.nome, deus->nome, 49);
			//novo->mConteudo.nome[50] = '\0';
			strncpy(novo->mConteudo.dominio, deus->dominio, 9);
			//novo->mConteudo.dominio[10] ='\0';
			strncpy(novo->mConteudo.biografia, deus->biografia, 199);		
			//novo->mConteudo.biografia[200] = '\0';
		}
	}
}

bool TabelaH::Existe (Dado* deus) {
	int h;
	h = FuncaoHash(deus);

	if ((mElementos[h] != NULL) && (mElementos[h]->mConteudo.id == deus->id)) {
		return true;
	} else {
		Noh* atual = mElementos[h];

		while ((atual != NULL) && (atual->mConteudo.id != deus->id)) {
			atual = atual->mProximo;
		}

		if ((atual != NULL) && (atual->mConteudo.id == deus->id)) {
			return true;
		} else {
			return false;
		}
	}
}

void TabelaH::Imprime () {
	Noh* atual;
	for (int i = 0; i < mCapacidade; ++i) {
		cout << i << ": ";
		atual = mElementos[i];

		while (atual != NULL) {
			cout << "[" << atual->mConteudo.id << " / " << atual->mConteudo.nome << " / "
			<< atual->mConteudo.dominio << " / " << atual->mConteudo.biografia << "]->";
			atual = atual->mProximo;
		}
		cout << "NULL " << endl;
	}
}

void Menu() {
	cout << endl;
	cout << "|*********************[MENU]*************************|" <<endl;
	cout << "| Entre com a opção desejada :                       |" << endl;
	cout << "| (1) - para inserir um novo deus no arquivo :       |" << endl;
	cout << "| (2) -  para remover um deus do arquivo :           |" << endl;
	cout << "| (3) -  para consultar um deus no arquivo :         |" << endl;
	cout << "| (4) -  para imprimir todos registros :             |" << endl;
	cout << "| (0) -  para sair :                                 |" << endl;
	cout <<"|****************************************************|" << endl << endl;
}
