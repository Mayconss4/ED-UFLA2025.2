#include <iostream>
#include <cstdlib>

using namespace std;

class noh {
    friend class pilha;
private:
    int mValor;
    noh* mProximo;
    
public:
    noh(int valor);
};

noh::noh(int valor){
    mValor = valor;
    mProximo = NULL;
}

class pilha {
private:
    noh* mTopo;
    unsigned mTamanho;

public:
    pilha();
    ~pilha();
    unsigned tamanho();
    void limpaPilha();
    void empilha(int dado);
    int desempilha();
    bool vazia();
    void inverter();
};

pilha::pilha(){
    mTopo = NULL;
    mTamanho = 0;
}

void pilha::limpaPilha(){
    while (mTamanho > 0){
        desempilha();
    }
}

unsigned pilha::tamanho(){
    return mTamanho;
}

int pilha::desempilha(){
    int valor = mTopo->mValor;
    noh* temp = mTopo;
    mTopo = mTopo->mProximo;
    delete temp;
    mTamanho--;
    return valor;
}

void pilha::empilha(int valor){
    noh* novo = new noh(valor);
    novo->mProximo = this->mTopo;
    this->mTopo = novo;
    mTamanho++;
}

pilha::~pilha(){
    limpaPilha();
}

bool pilha::vazia(){
    return (mTamanho == 0);
}

void pilha::inverter(){
    pilha pAux;
    pilha pAux2;  

    while (!this->vazia()) {
        pAux.empilha(this->desempilha()); 
    }
    
    while (!pAux.vazia()) {
        pAux2.empilha(pAux.desempilha()); 
    }
    
    while (!pAux2.vazia()) {
        this->empilha(pAux2.desempilha()); 
    }

    
}

int main (){
    pilha p1;
    int num;
    int valor;
    
    cin >> num;
    
    for (int i = 0; i<num; i++){
		cin >> valor; 
		p1.empilha(valor);
           
	}
    p1.inverter();
    
    while (!p1.vazia()){
        cout << p1.desempilha() << " ";
    }
    
    cout << endl;
}
