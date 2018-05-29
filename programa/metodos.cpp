/* 
  --Trabalho de Estrutura de Dados.
  --Sistema de Cadastro em Hashing Extensível
  --Copyright 2018 by Lucas Neves, Andrew e Vinicius.  
  --Arquivo contém a implementação das classes e dos módulos;
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include "metodos.hpp"

// Constantes
#define CAP_BLOCO 4
#define CAP_TABELA 16

using namespace std;

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ Início da implementação do bloco\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

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

void BlocosDados::InsereBloco (Dado deus) {
	if (!EmUso()) {
		mBloco[mTamBloco] = deus;
		++mTamBloco;
		mUso = true;
		mCabecalho = FuncaoHash(deus.id);
	} else if (BlocoCheio()) {
		cout << "|***************[ERRO]***************|" << endl;
		cout << "| O bloco está cheio.                |" << endl;
		cout << "| Não é possível inserir mais dados. |" << endl;
		cout << "|************************************|" << endl;
		exit(EXIT_FAILURE);
	} else {
		mBloco[mTamBloco] = deus;
		++mTamBloco;
	}
}

//Ḿétodo para encontrar a posição do bloco em bytes do arquivo
int BlocosDados::PosicaoArquivo (BlocosDados* novoBloco) {
	ifstream Leitura;
	int pos = 0;
  	Leitura.open("asgard.bin", ios::binary);
  	if (Leitura) {
		Leitura.seekg(0, Leitura.end);
		int tamArq = Leitura.tellg();
		Leitura.seekg(0, Leitura.beg);
		int qntBloc = tamArq / sizeof(BlocosDados);
		BlocosDados* aux = new BlocosDados;
		for (int i = 0; i < qntBloc; ++i) {
  			Leitura.read((char*)(aux), sizeof(BlocosDados));
  			if (aux->mCabecalho == novoBloco->mCabecalho) {
				pos = i*sizeof(BlocosDados);
			}
  		}
  	} else if (!Leitura) {
  		cout << endl << "Essa deus não está cadastrado" << endl;
  		pos = -1;
  	}
  	Leitura.close();
  	return pos;	
}

bool BlocosDados::EmUso () {
	return mUso;
}

bool BlocosDados::BlocoCheio () {
	return (mTamBloco == 4);
}

void BlocosDados::ImprimeBloco () {
	if (mUso) {
		cout << ">>>>>>>>>>>>>>>>>>>>>>[BLOCO]<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "Tamanho: " << mTamBloco << endl;
		cout << "Cabeçalho: " << mCabecalho << endl;
		cout << "Uso: " << mUso << endl;
		Dado* deus = new Dado[mTamBloco];
		deus = mBloco;
		InsertionSort(deus, mTamBloco);
		for (int i = 0; i < mTamBloco; ++i) {
			cout << "=====================(Deus"<< " " << i <<")======================" << endl;
			cout << "ID: " << deus[i].id << endl;
			cout << "Nome:" << deus[i].nome << endl;
			cout << "Dominio: " << deus[i].dominio << endl;
			cout << "Biografia: " << deus[i].biografia << endl;
			cout << "===================================================" << endl;
		}
		//Isto é necessário pois como deus é um ponteiro se não fosse apontado para NULL antes de deletado
		//estará apagando o endero dos blocos.
		deus = NULL;
		delete[] deus;
	}
	cout << endl << endl;
}

void BlocosDados::ImpressaoConsulta (int id) {
	bool existe = false;
	for (int i = 0; i < mTamBloco; ++i) {
		if (mBloco[i].id == id) {
			cout << "======================(Deus)======================" << endl;
			cout << "ID: " << mBloco[i].id << endl;
			cout << "Nome:" << mBloco[i].nome << endl;
			cout << "Dominio: " << mBloco[i].dominio << endl;
			cout << "Biografia: " << mBloco[i].biografia << endl;
			cout << "===================================================" << endl;
			existe = true;
		}
	}
	if (!existe)
		cout << "Esse id não está na cadastrado " << endl;
}

//Método para encontrar a posição no vetor de struct no bloco
int BlocosDados::PosDeus (int id) {
	bool existe = false;
	int posD = -1;
	for (int i = 0; i < mTamBloco; ++i) {
		if (mBloco[i].id == id) {
			posD = i;
			existe = true;
		}
	}
	if (!existe) {
		return posD;
	}
	return posD;
}

//Método para remover deus na posição do vetor e também atualizar posições.
void BlocosDados::RemoveDeus (int posId) {
	mBloco[posId].id = -1;
	if (posId < mTamBloco -1) {
		for (int i = posId; i < mTamBloco-1; ++i) {
			mBloco[i] = mBloco[i+1];  
		}
	cout << "mTamBloco: " << mTamBloco << endl; 
	} else if (mTamBloco == 1) {
		cout << "mTamBloco: " << mTamBloco << endl; 
		mUso = false;
	}
	--mTamBloco; 
}

bool BlocosDados::ProcuraIdRepetido (int id) {
	bool existe = false;
	for (int i = 0; i < mTamBloco; ++i) {
		if (mBloco[i].id == id) {
			existe = true;
		}
	}
	return existe;
}

/*////////////////////////////////////////// Fim da implementação do bloco/////////////////////////////*/

/*/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ Início da implementação da tabela\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

TabelaH::TabelaH (int cap)  {
	mCapacidade = cap;
	mElementos = new int[mCapacidade];
	for (int i = 0; i < mCapacidade; ++i) {
		mElementos[i] = -1;
	}
}

TabelaH::~TabelaH () {
	ofstream saida("uppsala.txt");
	for (int i = 0; i < mCapacidade; ++i) {
		saida << ConverteBinario(i) << "\t" << mElementos[i] << endl;
	}
	saida.close();

	delete[] mElementos;
}

void TabelaH::InsereTabela (Dado deus) {
	int pos = ConverteDecimal(FuncaoHash(deus.id));
	if (PosOcupada(pos)) { // Bloco existe
		BlocosDados* auxBloco = new BlocosDados;
		CarregaBloco(auxBloco, mElementos[pos]);
		auxBloco->InsereBloco(deus);
		EscreveArquivoVelho(auxBloco, mElementos[pos]);
		delete auxBloco;
		// Posição no arquivo = mElementos[pos]
		// Puxa no arquivo binário o bloco
		// Verifica se o bloco não está cheio
	} else { // Bloco não existe
		// Crie um novo bloco
		BlocosDados* novoBloco = new BlocosDados;
		novoBloco->InsereBloco(deus);
		EscreveArquivoNovo(novoBloco);
		int bytes = novoBloco->PosicaoArquivo(novoBloco);
		mElementos[pos] = bytes;
		delete novoBloco;
	}
}

void TabelaH::LeTabelaArquivo () {
	ifstream leituraTH("uppsala.txt");
  	int posTH, byte;
  	if (leituraTH.is_open()) {
  		for (int i = 0; i < CAP_TABELA; ++i) {
  			leituraTH >> posTH;
  			leituraTH >> byte;
  			mElementos[ConverteDecimal(posTH)] = byte;
  		}
  		leituraTH.close();
  		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  		ImprimeTabela();
  	}
}

 void TabelaH::ImprimeTabela () {
 	for (int i = 0; i < mCapacidade; ++i) {
 		cout << ConverteBinario(i) << "\t" << mElementos[i] << endl;
 	}
 }

bool TabelaH::PosOcupada (int pos) {
	if (mElementos[pos] == -1) {
		return false;
	} else {
		return true;
	}
}

int TabelaH::PosicaoBytes (int h) {
	return mElementos[h];
}

/*////////////////////////////////// Fim da implementação da tabela//////////////////////////////////*/

/*/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ Início da implementação dos módulos globais\\\\\\\\\\\\\\\\\\\\*/

int FuncaoHash (int i) {
	int h = i % CAP_TABELA;
	return ConverteBinario(h);
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
	cout << "Entre com o id do deus:" << endl;
	cin >> deus.id;
	cin.ignore();
	cout << "Entre com o nome do deus:" << endl;
	cin.getline(deus.nome, 50);
	cout << "Entre com o domínio do deus:" << endl;
	cin.getline(deus.dominio, 10);
	cout << "Entre com a biografia do deus:" << endl;
	cin.getline(deus.biografia, 200);
	
	cout << "Aqui !!! " << endl;
	int posVal = tabelaCadastro->PosicaoBytes(ConverteDecimal(FuncaoHash(deus.id)));
	if (posVal != -1) {
		BlocosDados* blocIns = new BlocosDados;
		CarregaBloco(blocIns, posVal);
		bool existeRep = blocIns->ProcuraIdRepetido(deus.id);
		if (existeRep) {
			cout << "Id repetido !" << endl;
			char opcao;
			cout << "Deseja tentar outro id [y/n] " << endl;
			cin >> opcao;
			if (opcao == 'y') {
				InsereDados(tabelaCadastro);
			} else {
				system("clear");
				Menu();
				return;
			}
		} else {
			tabelaCadastro->InsereTabela(deus);
		}
	}
}

void EscreveArquivoNovo (BlocosDados* auxBloco) {
	ofstream salva("asgard.bin", ios::binary|ios::app);
	if (salva.is_open()) {
		salva.write(reinterpret_cast<const char*> (auxBloco), sizeof(BlocosDados));
	}	
	salva.close();
}

void EscreveArquivoVelho (BlocosDados* auxBloco, int posBytes) {
	fstream salva("asgard.bin", ios::binary| ios::out| ios::in);
	if (salva.is_open()) {
		salva.seekp(posBytes, ios::cur);
		salva.write(reinterpret_cast<const char*> (auxBloco), sizeof(BlocosDados));
	}	
	salva.close();
}

void CarregaBloco (BlocosDados* auxBloco, int posBytes) {
	ifstream Carregar;
	Carregar.open("asgard.bin", ios::binary);
	if (Carregar.is_open()) {
		Carregar.seekg(posBytes, ios::cur);
		Carregar.read((char*)(auxBloco), sizeof(BlocosDados));
	} else {
		cout << endl <<"Erro na leitura do arquivo ou arquivo inesistente !" << endl << endl;
	}
	Carregar.close();
}

void RemoveDados (TabelaH* tabelaCadastro) {
	int id, numH;
	cout << "Insira um ID: " << endl;
	cin >> id;
	numH = ConverteDecimal(FuncaoHash(id));
	if (tabelaCadastro->PosOcupada(numH)) {
		BlocosDados* blocRem = new BlocosDados;
		int posBytes = tabelaCadastro->PosicaoBytes(numH);
		CarregaBloco(blocRem, posBytes);
		int posId = blocRem->PosDeus(id);
 		if (posId == -1) {
			cout << "Não exite deus com esse id não está na cadastrado " << endl;
			char opcao;
			cout << "Deseja sair da posição [y/n] " << endl;
			cin >> opcao;
			if (opcao == 'n') {
				RemoveDados(tabelaCadastro);
			} else {
				system("clear");
				Menu();
				return;
			}
		} else {
			blocRem->RemoveDeus(posId);
			EscreveArquivoVelho(blocRem, posBytes);
			cout << "deus Removido com sucesso" << endl;
		}
		delete blocRem;
	} else  {
		cout << "Não exite deus com esse id não está na cadastrado " << endl;
		char opcao;
		cout << "Deseja sair da posição [y/n] " << endl;
		cin >> opcao;
		if (opcao == 'n') {
			RemoveDados(tabelaCadastro);
		} else {
			system("clear");
			Menu();
			return;
		}
	}
}

void ConsultaDados (TabelaH* tabelaCadastro) {
	int id, numH;
	cout << "Insira um ID: " << endl;
	cin >> id;
	numH = ConverteDecimal(FuncaoHash(id));
	if (tabelaCadastro->PosOcupada(numH)) {
		BlocosDados* blocCons = new BlocosDados;
		CarregaBloco(blocCons, tabelaCadastro->PosicaoBytes(numH));
		blocCons->ImpressaoConsulta(id);
		delete blocCons;
	}
}

void ImprimeArquivoOrdem () {
	ifstream leitura;
	leitura.open("asgard.bin", ios::binary);
	if (leitura.is_open()) {
		BlocosDados* impTodo = new BlocosDados;
		leitura.seekg(0, ios::end);
		int tamArq = leitura.tellg();
		leitura.seekg(0, ios::beg);
		int var = sizeof(BlocosDados);
		int qntBloco = tamArq/var;
		for (int i = 0; i < qntBloco; ++i) {		
			leitura.read(reinterpret_cast<char*> (impTodo), sizeof(BlocosDados));
			impTodo->ImprimeBloco();
		}
	}
	
  	leitura.close();
}
void ImprimeBlocoOrdem (TabelaH* tabelaCadastro) {
	int numBin;
	tabelaCadastro->ImprimeTabela();
	cout << endl << "Insira uma posicao em número binário correspondente a Tabela: " << endl;
	cin >> numBin;
	if (tabelaCadastro->PosicaoBytes(ConverteDecimal(numBin)) == -1) {
		cout << "Posição Desocupada ! " << endl << endl;
		char opcao;
		cout << "Deseja sair da posição [y/n] " << endl;
		cin >> opcao;
		if (opcao == 'n') {
			ImprimeBlocoOrdem(tabelaCadastro);
			cout << endl;
		} else if (opcao != 'n') {
			system("clear");
			Menu();
			return;
		}
	} else {
		BlocosDados* blocOrd = new BlocosDados;
		CarregaBloco(blocOrd, tabelaCadastro->PosicaoBytes(ConverteDecimal(numBin)));
		blocOrd->ImprimeBloco();
	}
}

void InsertionSort(Dado* deus, int tam){
	int i, j, aux;
	char charAux1[50], charAux2[50], charAux3[200]; 
	for (i = 1; i < tam; i++){
		aux = deus[i].id;
		strcpy(charAux1, deus[i].nome);
		strcpy(charAux2, deus[i].dominio);
		strcpy(charAux3, deus[i].biografia);
		j = i - 1;
		while ((j >= 0) and (aux < signed(deus[j].id))) {
			deus[j+1].id = deus[j].id;
			strcpy(deus[j+1].nome, deus[j].nome);
			strcpy(deus[j+1].dominio, deus[j].dominio);
			strcpy(deus[j+1].biografia, deus[j].biografia);

			j--;
		}
	deus[j+1].id = aux;
	strcpy(deus[j+1].nome, charAux1);
	strcpy(deus[j+1].dominio, charAux2);
	strcpy(deus[j+1].biografia, charAux3);
	}
}

void Menu() {
	cout << endl;
	cout << "              |&&&&&&&&&&&&&&&&&&&&&[MENU]&&&&&&&&&&&&&&&&&&&&&&&&&|    " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "             | |        Entre com a opção desejada:               | |   " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (1) - para inserir um novo deus no arquivo:        |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (2) - para remover um deus do arquivo:             |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (3) - para consultar um deus no arquivo:           |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (4) - para imprimir todos registros:               |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (5) - para imprimir Bloco:                         |    " << endl;
	cout << "              |                                                    |    " << endl;
	cout << "              | (0) - para sair:                                   |    " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "             | |                                                  | |   " << endl;
	cout << "              =                                                    =    " << endl;
	cout << "              |&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|    " << endl;
	cout << endl;
}

/*///////////////////////////Fim da implementação dos módulos globais///////////////////////*/