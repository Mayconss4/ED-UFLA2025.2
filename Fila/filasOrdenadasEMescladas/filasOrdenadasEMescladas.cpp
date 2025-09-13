#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Noh{
	friend class Fila;
	
	private:
		int dado;
		Noh* proximo;
		
	public:
		Noh(int dado){
			this->dado = dado;
			proximo = NULL;
		}
};

class Fila{
	private:
		Noh* inicio;
		Noh* fim;
		int tamanho;
		
	public:
		Fila(){
			inicio = NULL;
			fim = NULL;
			tamanho = 0;
		}
		
		int retornaTamanho(){
			return tamanho;
		}
		
		bool estaVazia(){
			return (retornaTamanho()==0);
		}
		
		void enfileirar(int dado){
			Noh* novo = new Noh(dado);
			
			if(estaVazia()){
				inicio = novo;
				fim = novo;
			}else{
				fim->proximo = novo;
				fim = novo;
			}
			tamanho++;
		}
		
		int desenfileirar(){
			int valor = inicio->dado;
			Noh* aux = inicio;
			inicio = inicio->proximo;
			delete aux;
			tamanho--;
			if(estaVazia()){
				fim = NULL;
			}
			return valor;
		}
		
		int espiar(){
			int valor = inicio->dado;
			return valor;
		}
		
		~Fila(){
			while(!estaVazia()){
				desenfileirar();
			}
		}
};

int main (){
	
	Fila f1, f2;
	char entrada;
	
	cin >> entrada;
	
	while (entrada != 't'){
		switch(entrada){
			case 'i':
				char inserir;
				cin >> inserir;
				int inserido;
				cin >> inserido;
				
				if (inserir == 'a'){
					f1.enfileirar(inserido);
				}else if (inserir == 'b'){
					f2.enfileirar(inserido);
				}
				break;
			case 'e':
				char escrever;
				cin >> escrever;
				
				if(escrever=='a'){
					int valor;
					for (int i = 0; i<f1.retornaTamanho(); i++){
						valor = f1.desenfileirar();
						cout << valor << " ";
						f1.enfileirar(valor);
					}
				}else if(escrever=='b'){
					int valor;
					for (int i = 0; i<f2.retornaTamanho(); i++){
						valor = f2.desenfileirar();
						cout << valor << " ";
						f2.enfileirar(valor);
					}
				}
				cout << endl;
				break;
			case 'm':
				Fila f1Aux, f2Aux, fResult;
				for (int i = 0; i<f1.retornaTamanho(); i++){
					int valor = f1.desenfileirar();
					f1Aux.enfileirar(valor);
					f1.enfileirar(valor);
				}
				for (int i = 0; i<f2.retornaTamanho(); i++){
					int valor = f2.desenfileirar();
					f2Aux.enfileirar(valor);
					f2.enfileirar(valor);
				}
				while (!f1Aux.estaVazia() and !f2Aux.estaVazia()){
					if(f1Aux.espiar() < f2Aux.espiar()){
						fResult.enfileirar(f1Aux.desenfileirar());
					}else{
						fResult.enfileirar(f2Aux.desenfileirar());
					}
				}
				while (!f1Aux.estaVazia()){
					fResult.enfileirar(f1Aux.desenfileirar());
				}
				while (!f2Aux.estaVazia()){
					fResult.enfileirar(f2Aux.desenfileirar());
				}
				while (!fResult.estaVazia()){
					cout << fResult.desenfileirar() << " ";
				}
				cout << endl;
				break;
		}
		cin >> entrada;
	}	
	
	
	return 0;
}
