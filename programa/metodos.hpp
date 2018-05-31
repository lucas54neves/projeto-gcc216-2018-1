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
	char dominio[50];
	char biografia[200];
};

// Declaração do tipo Dado
typedef Deuses Dado;

// Classe bloco
class BlocosDados {
	friend class TabelaH;
	friend void InsertionSort (Dado* deus, int tam);
	public:
		BlocosDados ();
		~BlocosDados ();
		void InsereBloco (Dado deus);
		inline bool EmUso ();
		bool BlocoCheio ();
		void ImprimeBloco ();
		void ImpressaoConsulta (int id);
		int PosDeus (int id);
		void RemoveDeus (int posId);
		bool ProcuraIdRepetido (int id);
		inline int TamanhoBloc ();
		void ImprimeDeusId ();
	protected:
		bool mUso;
		Dado mBloco[CAP_BLOCO];
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
		inline int PosicaoBytes (int h);
		void AtualizaTabela (int h);
	protected :
		int* mElementos;
		int mCapacidade;
};

// Módulos globais
int FuncaoHash (int i);
int ConverteBinario (int decimal);
void InsereDados (TabelaH* tabelaCadastro);
void Menu ();
int ConverteDecimal (int binario);
void EscreveArquivoNovo (BlocosDados* novoBloco);
void EscreveArquivoVelho (BlocosDados* auxBloco, int posBytes);
void CarregaBloco (BlocosDados* auxBloco, int posBytes);
void RemoveDados (TabelaH* tabelaCadastro);
void ConsultaDados (TabelaH* tabelaCadastro);
void ImprimeArquivoOrdem ();
void ImprimeBlocoOrdem (TabelaH* tabelaCadastro);
void InsertionSort (Dado* deus, int tam);
void ImprimeId ();

#endif // METODOS