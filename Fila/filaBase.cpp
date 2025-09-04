#include <iostream>
#include <cstdlib>

using namespace std;

class noh {
    friend class fila;
	private:
		int mValor;
		noh* mProximo;

	public:
		noh(int valor);
};

noh::noh(int valor) {
    mValor = valor;
    mProximo = NULL;
}

class fila {
	private:
		noh* mInicio;
		noh* mFim;
		unsigned mTamanho;

	public:
		fila();
		~fila();
		void enfileira(int dado);
		int desenfileira();
		bool vazia();
		unsigned tamanho();
		void limpaFila();
		int espia();
};

fila::fila() {
    mInicio = NULL;
    mFim = NULL;
    mTamanho = 0;
}

fila::~fila() {
    limpaFila();
}

void fila::limpaFila() {
    while (!vazia()) {
        desenfileira();
    }
}

bool fila::vazia() {
    return (mTamanho == 0);
}

unsigned fila::tamanho() {
    return mTamanho;
}

void fila::enfileira(int valor) {
    noh* novo = new noh(valor);
    if (vazia()) {
        mInicio = novo;
        mFim = novo;
    } else {
        mFim->mProximo = novo;
        mFim = novo;
    }
    mTamanho++;
}

int fila::desenfileira() {
    if (vazia()) {
        cerr << "Erro: fila vazia!" << endl;
        exit(EXIT_FAILURE);
    }

    int valor = mInicio->mValor;
    noh* temp = mInicio;
    mInicio = mInicio->mProximo;
    delete temp;
    mTamanho--;

    if (mTamanho == 0) {
        mFim = NULL;
    }

    return valor;
}

int fila::espia(){
		int valor = -1;
		if (!this->vazia()){
			valor = this->mInicio->mValor;
		}else{
			cout << "Fila vazia!" << endl;
			
		}
		return valor;
}

int main() {
    fila f1;
	int num;
	
	cin >> num;
	
	while (num >= 0){
		f1.enfileira(num);
		cin >> num;	
	} 
	
	cout << "Tamanho: " << f1.tamanho() << endl;
	cout << "Elementos: " ; 

	while (not f1.vazia()){
		cout << f1.desenfileira() << " ";
	}

    return 0;
}


