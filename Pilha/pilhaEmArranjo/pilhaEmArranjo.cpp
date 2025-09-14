#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

class pilhav {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        pilhav(int cap = 100){
			capacidade = cap;
			dados = new Dado[cap];
			tamanho = 0;
			posTopo = -1;
		}
		
        ~pilhav(){
			delete[] dados;
		}
		
        void empilha(Dado valor){
			tamanho++;
			posTopo++;
			dados[posTopo] = valor;
		}
		
        Dado desempilha(){
			if(tamanho==0){
				exit(EXIT_FAILURE);
			}
			Dado valor;
			valor = dados[posTopo];
			posTopo--;
			tamanho--;
			return valor;
		}
		
        Dado espia(){
			if(tamanho==0){
				exit(EXIT_FAILURE);
			}
			Dado valor;
			valor = dados[posTopo];
			return valor;
		}
		
        void depura(){
			for(int i = 0; i<=posTopo; i++){
				cout << dados[i] << " ";
			}
			cout << endl;
		}
		
        void info(){
			cout << tamanho << " " << posTopo;
		}
};

int main (){
	pilhav* pilha = new pilhav(20);
	
	for(int i = 0; i<5; i++){
		int valor;
		cin >> valor;
		pilha->empilha(valor);
	}
	
	for(int i = 0; i<3; i++){
		int valor;
		valor = pilha->desempilha();
		cout << valor << " ";
	}
	
	cout << endl;
	
	for(int i = 0; i<4; i++){
		int valor;
		cin >> valor;
		pilha->empilha(valor);
	}
	
	for(int i = 0; i<3; i++){
		int valor;
		valor = pilha->desempilha();
		cout << valor << " ";
	}
	
	cout << endl;
	
	cout << pilha->espia() << endl;
	
	pilha->depura();
	
	pilha->info();
	
	return 0;
}
