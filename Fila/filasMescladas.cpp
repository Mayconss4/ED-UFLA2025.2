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
    fila f1, f2, fResult;
    int qtde, valor;

    cin >> qtde;
    for (int i = 0; i < qtde; ++i) {
        cin >> valor;
        f1.enfileira(valor);
    }

    cin >> qtde;
    for (int i = 0; i < qtde; ++i) {
        cin >> valor;
        f2.enfileira(valor);
    }

    int ultimoInserido = -1; 

    while (!f1.vazia() && !f2.vazia()) {
        int v1 = f1.espia();
        int v2 = f2.espia();

        if (v1 == v2) {
            if (v1 != ultimoInserido) {
                fResult.enfileira(v1);
                ultimoInserido = v1;
            }
            f1.desenfileira();
            f2.desenfileira();
        } else if (v1 < v2) {
            if (v1 != ultimoInserido) {
                fResult.enfileira(v1);
                ultimoInserido = v1;
            }
            f1.desenfileira();
        } else {
            if (v2 != ultimoInserido) {
                fResult.enfileira(v2);
                ultimoInserido = v2;
            }
            f2.desenfileira();
        }
    }

    
    while (!f1.vazia()) {
        int v = f1.desenfileira();
        if (v != ultimoInserido) {
            fResult.enfileira(v);
            ultimoInserido = v;
        }
    }

    while (!f2.vazia()) {
        int v = f2.desenfileira();
        if (v != ultimoInserido) {
            fResult.enfileira(v);
            ultimoInserido = v;
        }
    }

    while (!fResult.vazia()) {
        cout << fResult.desenfileira() << " ";
    }
    cout << endl;

    return 0;
}

