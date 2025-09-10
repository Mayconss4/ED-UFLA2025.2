#include<iostream>

using namespace std;

class Noh{
	friend class Pilha;
	
	private:
		Noh* proximoNoh;
		int dadoNoh;
		
	public:
		Noh(int valor){
			proximoNoh = NULL;
			dadoNoh = valor;
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
			novo->proximoNoh = this->topo;
			this->topo = novo;
			tamanho++;
		}
		
		int desempilhar(){
			if(this->tamanho<=0){
				cout << "VAZIA" << endl;
				return -1;
			}
			int valor;
			Noh* aux = this->topo;
			valor = aux->dadoNoh;
			this->topo = aux->proximoNoh;
			delete aux;
			tamanho--;
			return valor;
		}
		
		int getTamanho(){
			return this->tamanho;
		}
		
		int encontrarMenorValor(){
			int menorValor;
			Pilha comparativa;
			Pilha conservaElementos;
			while (this->tamanho>0){
				int temp = this->desempilhar();
				comparativa.empilhar(temp);
				conservaElementos.empilhar(temp);
			}
			
			menorValor = comparativa.desempilhar();
			
			while(comparativa.tamanho>0){
				int aux = comparativa.desempilhar();
				if(menorValor>aux){
					menorValor = aux;
				}
			}
			
			while(conservaElementos.tamanho>0){
				this->empilhar(conservaElementos.desempilhar());
			}
			return menorValor;
		}
};

int main(){
	char entrada;
	Pilha p1;
	
	do{
		cin >> entrada;
		switch(entrada){
			case 'e': {
				int valor;
				cin >> valor;
				p1.empilhar(valor);
				break;
			}
			case 'd': {
				int retirado = p1.desempilhar();
				if (retirado != -1) {
					cout << retirado << endl;
				}
				break;
			}
			case 'm': {
				int menor = p1.encontrarMenorValor();
				if (menor != -1) {
					cout << menor << endl;
				}
				break;
			}

			case 's': {
				while(p1.getTamanho()>0){
					cout << p1.desempilhar() << " ";
				}
				break;
			}
		} 
	}while (entrada != 's');

	return 0;
}
