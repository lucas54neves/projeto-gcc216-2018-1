/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém as classes e as declarações dos módulos globais;
*/

#ifndef METODOS
#define METODOS

// Constantes
#define CAP_BLOCO 4
#define CAP_TABELA 16

using namespace std;

// Struct Deus
struct Deuses {
	int id;
	char nome[50];
	char dominio[10];
	char biografia[200];
};

// Declaração do tipo Dado
typedef Deuses Dado;

// Classe bloco
class BlocosDados {
	friend class TabelaH;
	public:
		BlocosDados ();
		~BlocosDados ();
		void InsereBloco (Dado deus);
		inline bool EmUso ();
		bool BlocoCheio ();
		void ImprimeBloco ();
	protected:
		bool mUso;
		Dado mBloco[CAP_TABELA];
		int mTamBloco;
		int mCabecalho;
		int PosicaoArquivo (BlocosDados* novoBloco);
};

// Classe tabela
class TabelaH {
	public:
		TabelaH (int cap = CAP_TABELA);
		~TabelaH ();
		void InsereTabela (Dado deus);
		void Remove (int id);
		bool PosOcupada (int pos);
		void LeTabelaArquivo ();
		void ImprimeTabela ();
	protected :
		int* mElementos;
		int mCapacidade;
};

// Módulos globais
int FuncaoHash (int i);
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

#endif // METODOS