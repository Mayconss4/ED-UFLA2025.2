#include <iostream>
#include <cstdlib>

using namespace std;

class Heap {
private:
    int* dados;   
    int capacidade;
    int tamanho;  

    int pai(int i) { return (i - 1) / 2; }
    int esquerdo(int i) { return 2 * i + 1; }
    int direito(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {
        int maior = i;
        int esq = esquerdo(i);
        int dir = direito(i);

        if (esq < tamanho && dados[esq] > dados[maior]) {
            maior = esq;
        }
        if (dir < tamanho && dados[dir] > dados[maior]) {
            maior = dir;
        }

        if (maior != i) {
            swap(dados[i], dados[maior]);
            heapifyDown(maior);
        }
    }

    void heapifyUp(int i) {
        while (i > 0 && dados[i] > dados[pai(i)]) {
            swap(dados[i], dados[pai(i)]);
            i = pai(i);
        }
    }

public:
    Heap(int cap) {
        capacidade = cap;
        dados = new int[capacidade];
        tamanho = 0;
    }

    ~Heap() {
        delete[] dados;
    }

    bool vazio() {
        return tamanho == 0;
    }

    bool cheio() {
        return tamanho == capacidade;
    }

    void insere(int valor) {
        if (cheio()) {
            cout << "Erro: heap cheio!" << endl;
            return;
        }
        dados[tamanho] = valor;
        heapifyUp(tamanho);
        tamanho++;
    }

    int retiraRaiz() {
        if (vazio()) {
            cout << "Erro: heap vazio!" << endl;
            return -1;
        }
        int raiz = dados[0];
        dados[0] = dados[tamanho - 1];
        tamanho--;
        heapifyDown(0);
        return raiz;
    }

    int espiar() {
        if (vazio()) {
            cout << "Erro: heap vazio!" << endl;
            return -1;
        }
        return dados[0];
    }

    void buildHeap(int* vetor, int n) {
        if (n > capacidade) {
            cout << "Erro: vetor maior que capacidade do heap!" << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            dados[i] = vetor[i];
        }
        tamanho = n;
        for (int i = (tamanho / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void imprimir() {
        for (int i = 0; i < tamanho; i++) {
            cout << dados[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap(20);

    int vetor[] = {35, 38, 12, 14, 9, 71, 98, 3, 29, 10, 99, 31};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Construindo o heap com buildHeap...\n";
    heap.buildHeap(vetor, n);

    cout << "Heap construido: ";
    heap.imprimir();

    cout << "Maior elemento (raiz): " << heap.espiar() << endl;

    cout << "Removendo a raiz: " << heap.retiraRaiz() << endl;
    cout << "Heap apos remocao: ";
    heap.imprimir();

    return 0;
}

