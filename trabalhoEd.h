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
#define CAP_TAB 16
#define CAP_BLOCO 4

using namespace std;

struct Deuses {
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200];
};

typedef Deuses Dado;

int FuncaoHash (int i);

class BlocosDados {
	friend class TabelaH;
	public:
		BlocosDados ();
		~BlocosDados ();
		void Insere (Dado deus);
		inline bool EmUso ();
		bool BlocoCheio ();
		void Imprime ();
	protected:
		bool mUso;
		Dado mBloco[CAP_TAB];
		unsigned int mTamBloco;
		int mCabecalho;
		int PosicaoArquivo (BlocosDados* novoBloco);
};

class TabelaH {
	public:
		TabelaH (unsigned int cap = CAP_TAB);
		TabelaH ();
		~TabelaH ();
		void Insere (Dado deus);
		void Remove (int id);
		bool PosOcupada (int pos);
	protected :
		int* mElementos;
		unsigned int mCapacidade;
};

int ConverteBinario (int decimal);
void InserirDados (TabelaH* tabelaCadastro);
void Menu ();
int ConverteDecimal (int binario);
void EscreveArquivo (BlocosDados* novoBloco, int posBytes);
void CarregaBloco (BlocosDados* auxBloco, int posBytes);
void RemoveDados ();
void ConsultaDados ();
void ImprimeArquivoOrdem ();
void ImprimeBlocoOrdem ();

#endif