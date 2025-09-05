#include <iostream>

typedef int Dado;

class Noh {
    friend class Pilha;
    private:
        Dado mDado; 
        Noh* mPtProx;
        
    public:
		Noh(Dado dado){
			mDado = dado;
			mPtProx = NULL;
		}
};

class Pilha {
    public:
        Pilha();
        ~Pilha();
        Dado Desempilhar();
        void Empilhar(const Dado& d);
        void LimparTudo();
        int Tamanho();
        Dado Topo() const;
        bool Vazia() const;
    private:
        Noh* mPtTopo;
        unsigned mTamanho;
};

using namespace std;

Pilha::Pilha() {
	mPtTopo = NULL;
	mTamanho = 0;
}

Pilha::~Pilha() {
}

Dado Pilha::Desempilhar() {
	if (Vazia()) {
        cerr << "Erro: Pilha vazia!" << endl;
        exit(EXIT_FAILURE);
    }
	Dado valor = this-> mPtTopo -> mDado;
	Noh* temp = this->mPtTopo;
	this->mPtTopo = temp->mPtProx;
	delete temp;
	mTamanho--;
	return valor;
}

void Pilha::Empilhar(const Dado& d) {
	Noh* novo = new Noh(d);
	novo->mPtProx = this->mPtTopo;
	this->mPtTopo = novo;
	mTamanho++;
}

void Pilha::LimparTudo() {
	while(mTamanho>0){
		Desempilhar();
	}
}

Dado Pilha::Tamanho(){
	return mTamanho;
}

Dado Pilha::Topo() const {
	Dado valor;
	valor = this->mPtTopo->mDado;
	return valor;
}

bool Pilha::Vazia() const {
	if(mTamanho>0){
			return false;
	}else{
		return true;
	}
}

int main() {
    Pilha pilha;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': 
                cin >> valor;
                pilha.Empilhar(valor);
                break;
            case 'r':
                cout << pilha.Desempilhar() << endl;
                break;
            case 'l': 
                pilha.LimparTudo();
                break;
            case 't': 
                cout << pilha.Tamanho() << endl;
                break;
            case 'e': 
                cout << pilha.Topo() << endl;
                break;
            case 'f':
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 'f');
    while (not pilha.Vazia()) {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}
