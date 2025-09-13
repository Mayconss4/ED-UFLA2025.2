#include <iostream>
#include <cstdlib>

using namespace std;

class Noh {
	friend class Fila;
	
	private:
		int dado;
		Noh* proximo;
	
	public:
		Noh(int valor){
			dado = valor;
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
		
		int getTamanho(){
			return tamanho;
		}
		
		bool estaVazia(){
			return(getTamanho()==0);
		}
		
		void enfileirar(int valor){
			Noh* novo = new Noh(valor);
			if(this->estaVazia()){
				inicio = novo;
				fim = novo;
			}else{
				fim->proximo = novo;
				fim = novo;
			}
			tamanho++;
		}
		
		int desenfileirar(){
			
			if(this->estaVazia()){
				exit(EXIT_FAILURE);
			}
			
			int valor = inicio->dado;
			Noh* aux = inicio;
			inicio = inicio->proximo;
			delete aux;
			tamanho--;
			
			if(this->estaVazia()){
				fim = NULL;
			}
			return valor;
		}
		
		void listarPrimeiroNegativo(int valor){
			Fila aux;
			
			while(!this->estaVazia()){
				int primeiroNegativo = 0;
				
				if(aux.estaVazia()){
					for (int i = 0; i<valor; i++){
						aux.enfileirar(this->desenfileirar());
					}
				}else{
					aux.desenfileirar();
					aux.enfileirar(this->desenfileirar());
				}
				
				int controle = 0;
				
				while ((controle < valor) ){
					int temp = aux.desenfileirar();
					if ((temp < 0) and (primeiroNegativo==0)){
						primeiroNegativo = temp;
					}
					aux.enfileirar(temp);
					controle++;
				}
				
				if(primeiroNegativo < 0){
					cout << primeiroNegativo << " ";
				}else{
					cout << "inexistente ";
				}
			}
		}
};

int main (){
	int num, subFila;
	Fila f1;
	
	cin >> num;
	
	for(int i = 0; i<num; i++){
		int valor;
		cin>> valor;
		f1.enfileirar(valor);
	}
	
	cin >> subFila;
	
	f1.listarPrimeiroNegativo(subFila);
	
	return 0;
}
