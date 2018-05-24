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
#define Cap_TAB 16
#define CAP_BLOCO 4

/*
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200]
*/

int FuncaoHash (int i) {
	h = i % Cap_TAB;
	return ConverteBinario(h);
}

BlocosDados::BlocosDados () {
	for (int i = 0; i < CAP_BLOCO; ++i) {
		mBloco[i].id = -1;
		mBloco[i].nome[50] = ' ';
		mBloco[i].dominio[10] = ' ';
		mBloco[i].biografia[200] = ' ';
	}
	mTamBloco = 0;
	mUso = false;
}

void BlocosDados::Insere (Dado deus) {
	mBloco[mTamBloco] = deus;
	++mTamBloco;
	mUso = true;
	mCabecalho = FuncaoHash(deus.id);
}

BlocosDados::~BlocosDados () {
	for (int i = 0; i < CAP_BLOCO; ++i) {
		mBloco[i].id = -1;
		mBloco[i].nome[50] = ' ';
		mBloco[i].dominio[10] = ' ';
		mBloco[i].biografia[200] = ' ';
	}
	mTamBloco = 0;
	mCabecalho = -1;
}

bool BlocosDados::EmUso () {
	return mUso;
}

TabelaH::TabelaH (unsigned int cap) : mCapacidade(cap) {
	mElementos = new int[mCapacidade];
	for (int i = 0; i < mCapacidade; ++i) {
		mElementos[i] = -1;
	}
}

void TabelaH::Insere (Dado deus) {
	int pos = ConverteDecimal(FuncaoHash(deus.id));
	if (PosOcupada(pos)) { // Bloco existe
		// Posição no arquivo = mElementos[pos]
		// Puxa no arquivo binário o bloco
		// Verifica se o bloco não está cheio
	} else { // Bloco não existe
		// Crie um novo bloco
	}
}

// void TabelaH::Imprime () {
// 	Noh* atual;
// 	for (int i = 0; i < mCapacidade; ++i) {
// 		cout << i << ": ";
// 		atual = mElementos[i];

// 		while (atual != NULL) {
// 			cout << "[" << atual->mConteudo.id << " / " << atual->mConteudo.nome << " / "
// 			<< atual->mConteudo.dominio << " / " << atual->mConteudo.biografia << "]->";
// 			atual = atual->mProximo;
// 		}
// 		cout << "NULL " << endl;
// 	}
// }

TabelaH::~TabelaH () {
	ofstream saida("Enderecos.txt");
	for (int i = 0; i < mTamHash; ++i) {
		saida << ConverteBinario(i) << " " << mElementos[i] << endl;
	}
	saida << mTamHash << endl; 

	saida.close();

	delete[] mElementos;
}

bool TabelaH::PosOcupada (int pos) {
	if (mElementos[pos] == -1) {
		return false;
	} else {
		return true;
	}
}

int ConverteBinario (int decimal) {
    int aux[4];
    int resto, binario;

    aux[3] = decimal % 2;
    resto = decimal / 2;
    aux[2] = resto % 2;
    resto = resto / 2;
    aux[1] = resto % 2;
    resto = resto / 2;
    aux[0] = resto % 2;

    binario = aux[0]*1000 + aux[1]*100 + aux[2]*10 + aux[3]*1;

    return binario;
}

int ConverteDecimal (int binario) {
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

void InsereDados (TabelaH* tabelaCadastro) {
	Dado deus;
	// Leitura de Dados:
	deus.id = rand() % 64;
	cin.ignore();
	cout << "Entre com o nome do deus:" << endl;
	cin.getline(deus.nome, 50);
	cout << "Entre com o domínio do deus:" << endl;
	cin.getline(deus.dominio, 10);
	cout << "Entre com a biografia do deus:" << endl;
	cin.getline(deus.biografia, 200);
	
	tabelaCadastro->Insere(deus);
}

void RemoveDados () {

	return;
}

void ConsultaDados () {

	return;
}


void Menu() {
	cout << endl;
	cout << "              |*********************[MENU]*************************|    " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "             | |        Entre com a opção desejada:               | |   " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (1) - para inserir um novo deus no arquivo:        |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (2) - para remover um deus do arquivo:             |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (3) - para consultar um deus no arquivo:           |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (4) - para imprimir todos registros:               |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (0) - para sair:                                   |    " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "             | |                                                  | |   " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "              |****************************************************|    " << endl;
	cout << endl;
}
