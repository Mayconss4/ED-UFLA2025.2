#include <iostream>
#include <cstdlib>

using namespace std;

class Noh{
	friend class Pilha;
	
	private:
		int dado;
		Noh* proximo;
		
	public:
		Noh(int valor){
			dado = valor;
			proximo = NULL;
		}
};

class Pilha{
	private:
		Noh* topo;
		int tamanho;
		
	public:
		Pilha(){
			topo = NULL;
			tamanho = 0;
		}
		
		void empilhar(int valor){
			Noh* novo = new Noh(valor);
			novo->proximo = topo;
			topo = novo;
			tamanho++;
		}
		
		int desempilhar(){
			int valor;
			Noh* auxiliar = topo;
			valor = auxiliar->dado;
			topo = auxiliar->proximo;
			tamanho--;
			delete auxiliar;
			return valor;
		}
		
		int espiar(){
			int valor = topo->dado;
			return valor;
		}
		
		int getTamanho(){
			return tamanho;
		}
		
		void ordenar(Pilha* p1){
			Pilha p2;
			int v1;
			
			while (p1->tamanho > 0 ){
				v1 = p1->desempilhar();
				while (p2.getTamanho() > 0 and p2.espiar() > v1){
					p1->empilhar(p2.desempilhar());
				}
				p2.empilhar(v1);
			}
			
			while (p2.getTamanho()!=0){
				p1->empilhar(p2.desempilhar());
			}
		}
		
		~Pilha(){
			while(tamanho != 0){
				this->desempilhar();
			}
		}
};


int main (){
	Pilha p1;
	int num;
	
	cin >> num;
	
	while (num>0){
		int valor;
		cin >> valor;
		p1.empilhar(valor);
		num--;
	}
	
	p1.ordenar(&p1);
	
	while (p1.getTamanho()!=0){
		cout << p1.desempilhar() << " ";
	}
	return 0;	
}
