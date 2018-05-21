/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém as implementações das classes;
*/

#include <iostream>
#include <cmath>
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
		Noh* aux;
		while (aquelequemorre != NULL) {
			aux = aquelequemorre;
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
			cout << "Funciona agora2 !!!" << endl;
			Noh* novo = new Noh;
			novo->mConteudo.id = deus->id;
			strncpy(novo->mConteudo.nome, deus->nome, 49);
			novo->mConteudo.nome[50] = '\0';
			strncpy(novo->mConteudo.dominio, deus->dominio, 9);
			novo->mConteudo.dominio[10] ='\0';
			strncpy(novo->mConteudo.biografia, deus->biografia, 199);		
			novo->mConteudo.biografia[200] = '\0';
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

int TabelaH::ConverteBinario4Bits () {
    int aux[4];
    int resto, binario;

    Noh* temp;
    aux[3] = temp->mConteudo.id % 2;
    resto = temp->mConteudo.id / 2;
    aux[2] = resto % 2;
    resto = resto / 2;
    aux[1] = resto % 2;
    resto = resto / 2;
    aux[0] = resto % 2;

    binario = aux[0]*1000 + aux[1]*100 + aux[2]*10 + aux[3]*1;

    return binario;
}

int TabelaH::ConverteDecimal (int binario) {
    int aux[4];
    int decimal;

    aux[0] = binario / 1000;
    binario = binario % 1000;
    aux[1] = binario / 100;
    binario = binario % 100;
    aux[2] = binario / 10;
    aux[3] = binario % 10;

    decimal = (int)(aux[0] * pow(2, 3) + aux[1] * pow(2, 2) + aux[2] * pow(2, 1) + aux[3] * pow(2, 0));
    return decimal;
}

void InserirDados (TabelaH tabelaCadastro) {
	Deuses* deus = new Deuses;
	deus->id = rand() % 64;

	// Leitura de Dados:
	cin.ignore();
	cout << "Entre com o nome do deus" << endl;
	cin.getline(deus->nome, 50);
	cout << "Entre com o domínio do deus" << endl;
	cin.getline(deus->dominio, 10);
	cout << "Entre com a biografia do deus" << endl;
	cin.getline(deus->biografia, 200);

	cout << "Funciona agora000 !!!" << endl;
	tabelaCadastro.Insere(deus);

	cout << "Aqui !" << endl;
	int bin = tabelaCadastro.ConverteBinario4Bits();
	// Abertura para salvar no arquivo:
	ofstream saida("Conteudo.dat", ios::binary|ios::app);
	saida.write ((const char *) (&tabelaCadastro), sizeof(TabelaH));
	saida.close();

	cout << "Aqui2 !" << endl;
	ofstream saida2("Enderecos.dat", ios::binary|ios::app);
	saida2.write((const char *) (&bin), sizeof(int));
	saida2.close();

	cout << "Aqui3 !" << endl;
	delete deus;

	//cout << "Deus com id " << tabelaCadastro.mConteudo.id  << " inserido com sucesso!" << endl;
}

void Menu() {
	cout << endl;
	cout << "|*********************[MENU]*************************|" << endl;
	cout << "| Entre com a opção desejada:                        |" << endl;
	cout << "| (1) - para inserir um novo deus no arquivo:        |" << endl;
	cout << "| (2) - para remover um deus do arquivo:             |" << endl;
	cout << "| (3) - para consultar um deus no arquivo:           |" << endl;
	cout << "| (4) - para imprimir todos registros:               |" << endl;
	cout << "| (0) - para sair:                                   |" << endl;
	cout << "|****************************************************|" << endl;
	cout << endl;
}
