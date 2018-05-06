/* 
  --Trabalho de Hashing Extensível :
    Estrutura de Dados.
  --Método de ++++++++++++++ 
     (aqui vai o nome do seu trabalho)
  --Copyright 2018 by Lucas, Andrew e Vinicius.  
  --Arquivo contém as implementações das classes;
*/

#include <iostream>
#include "workEd.h"

/*int id;
	char nome[50];
	char dominio[10];
	char biografia[200]*/



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

TabelaH::TabelaH (unsigned int capsup) : mCapacidade (capsup) {
	mElementos = new Noh*[capsup];
	for (int i = 0; i < capsup; ++i) {
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

void Menu() {
	cout <<"***********************************************" << endl;
	cout <<"   1 - Inserir novo ---- no arquivo "<< endl;
	cout <<"   2 -  Remover ---- do arquivo"<< endl;
	cout <<"   3 - Consultar ----- no arquivo "<< endl;
	cout <<"   4 - Imprimir todos registros "<< endl;
	cout <<"*************************************************" << endl;
}