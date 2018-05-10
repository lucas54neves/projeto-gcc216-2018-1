/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém as implementações das classes;
*/

#include <iostream>
#include "trabalhoEd.h"

/*
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200]
*/
int FuncaoHash (Dado deus) {
	int h = deus.id % TAM_BLOCO;

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
		// Colidiu
	}

/*
void tabelaHash::insere(string c, string v) {
	int h;
	h = funcaoHash(c, capacidade);
	if (recupera(c) == "NÃO ENCONTRADO!") {
		if (elementos[h] == NULL) {
			elementos[h] = new noh;
			elementos[h]->chave = c;
			elementos[h]->valor = v;
		} else {
			cout << "Colidiu: " << c << endl;
			noh* atual = elementos[h];
			// Achando local para inserção
			while (atual->proximo != NULL) {
				atual = atual->proximo;
			}
			noh* novo = new noh;
			novo->chave = c;
			novo->valor = v;
			atual->proximo = novo;
		}
	} else {
		cout << "ITEM JÁ ESTÁ NA TABELA!" << endl;
	}
}
*/
}

bool TabelaH::Existe (Dado* deus) {
	int h;
	h = FuncaoHash(deus);

	if ((mElementos[h] != NULL) && (mElementos[h]->mConteudo.id == deus.id)) {
		return true;
	} else {
		Noh* atual = mElementos[h];

		while ((atual != NULL) && (atual->mConteudo.id != deus.id)) {
			atual = atual->mProximo;
		}

		if ((atual != NULL) && (atual->mConteudo.id == deus.id)) {
			return true;
		} else {
			return false;
		}
	}
}

void Menu() {
	cout <<"***********************************************" << endl;
	cout << "Entre com a opção desejada:" << endl;
	cout << "1 para inserir um novo deus no arquivo;" << endl;
	cout << "2 para remover um deus do arquivo;" << endl;
	cout << "3 para consultar um deus no arquivo;" << endl;
	cout << "4 para imprimir todos registros;" << endl;
	cout << "0 para sair" << endl;
	cout <<"*************************************************" << endl;
}
