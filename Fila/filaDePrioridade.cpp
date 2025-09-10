#include <iostream>
#include <string>

using namespace std;

class Noh {
	friend class Fila;
	private:
		string dado;
		Noh *proximo;
	public:
		Noh(string info){
			dado = info;
            proximo = NULL;
        }
        ~Noh(){
			proximo = NULL;
            delete proximo;
		 }
};

class Fila {
    private:
        Noh* inicio;
        Noh* fim;
        int tamanho;
    
    public:
        Fila();
        ~Fila();
        void enfileira(string info);
        string desenfileira();
        bool estaVazia();  
};


Fila::Fila() {
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

Fila::~Fila() { 
	while(!estaVazia()){
		desenfileira();
	}
}


void Fila::enfileira(string info) {
    Noh* novo = new Noh (info);
    
	if(estaVazia()){
		inicio = novo;
		fim = novo;
	}else{
		fim->proximo = novo;
		fim = novo;
	}
    tamanho++;
    
}

string Fila::desenfileira() {
	string temp;
    if (!this->estaVazia()){
		temp = inicio->dado;
		Noh *aux = inicio;
		inicio = inicio->proximo;
		delete aux;
		tamanho--;
	}else{
		temp = "AGUARDE";
	}
	return temp;
}
    
bool Fila::estaVazia() {
	
    return (tamanho == 0);
}

int main() {

	Fila filaNormal;
	Fila filaPrioritaria;
	
	string comando;
	
	cin >> comando;
	int contadorPrioritario = 0;
	
	while(comando != "fim"){
		if(comando == "normal"){
			string paciente;
			cin >> paciente;
			filaNormal.enfileira(paciente);
		}else if(comando == "prioridade"){
			string paciente;
			cin >> paciente;
			filaPrioritaria.enfileira(paciente);
		}else if(comando == "atender"){
			if (contadorPrioritario < 3 and !filaPrioritaria.estaVazia()){
				cout << filaPrioritaria.desenfileira() << endl;
				contadorPrioritario++;
			}else if (contadorPrioritario < 3 and filaPrioritaria.estaVazia()){
				cout << filaNormal.desenfileira() << endl;
			}else if (contadorPrioritario > 2 and !filaNormal.estaVazia()){
				cout << filaNormal.desenfileira() << endl;
				contadorPrioritario = 0;
			}else if (contadorPrioritario > 2 and filaNormal.estaVazia()){
				cout << filaPrioritaria.desenfileira() << endl;
				contadorPrioritario = 0;
			}else if (filaPrioritaria.estaVazia()){
				cout << filaNormal.desenfileira() << endl;
			}else if (filaNormal.estaVazia()){
				cout << filaPrioritaria.desenfileira() << endl;
			}
		}
		cin>> comando;
	}
    
}
