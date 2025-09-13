#include <iostream>
#include <cstdlib>

using namespace std;

class Noh {
    friend class Fila;

private:
    int dado;
    Noh* proximo;

public:
    Noh(int valor) {
        dado = valor;
        proximo = NULL;
    }
};

class Fila {
private:
    Noh* inicio;
    Noh* fim;
    int tamanho;

public:
    Fila() {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }

    int getTamanho() {
        return tamanho;
    }

    bool estaVazia() {
        return (getTamanho() == 0);
    }

    void enfileirar(int valor) {
        Noh* novo = new Noh(valor);
        if (this->estaVazia()) {
            inicio = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }
        tamanho++;
    }

    int desenfileirar() {
        if (this->estaVazia()) {
            exit(EXIT_FAILURE);
        }

        int valor = inicio->dado;
        Noh* aux = inicio;
        inicio = inicio->proximo;
        delete aux;
        tamanho--;

        if (this->estaVazia()) {
            fim = NULL;
        }
        return valor;
    }
};

int main() {
    int num, valor;
    Fila f1, aux;

    cin >> num;

    for (int i = 0; i < num; i++) {
        int valor;
        cin >> valor;
        f1.enfileirar(valor);
    }

    cin >> valor;

    while (!f1.estaVazia()) {
        int primeiroNegativo = 0;

        if (aux.estaVazia()) {
            for (int i = 0; i < valor; i++) {
                aux.enfileirar(f1.desenfileirar());
            }
        } else {
            aux.desenfileirar();
            aux.enfileirar(f1.desenfileirar());
        }

        int controle = 0;

        while (controle < valor) {
            int temp = aux.desenfileirar();
            if ((temp < 0) && (primeiroNegativo == 0)) {
                primeiroNegativo = temp;
            }
            aux.enfileirar(temp);
            controle++;
        }

        if (primeiroNegativo < 0) {
            cout << primeiroNegativo << " ";
        } else {
            cout << "inexistente ";
        }
    }

    return 0;
}
