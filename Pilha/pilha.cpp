#include <iostream>
#include <cstdlib>

using namespace std;

class noh{
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

pilha::desempilha(){
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
	return (mTamanho==0);
}

int main (){
	pilha p1;
	int num;
	
	cin >> num;
	
	while (num >= 0){
		p1.empilha(num);
		cin >> num;	
	} 
	
	cout << "Tamanho: " << p1.tamanho() << endl;
	cout << "Elementos: " ; 

	while (not p1.vazia()){
		cout << p1.desempilha() << " ";
	}
	
	cout << endl;
}































