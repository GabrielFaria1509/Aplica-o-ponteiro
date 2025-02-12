
#include <iostream>
using namespace std;

typedef struct No {
    int info;
    struct No* prox;
} Pilha;

// Inicializa a pilha como vazia
Pilha* inicializar() {
    return nullptr;
}

// Empilha um elemento (push)
Pilha* empilhar(Pilha* topo, int valor) {
    Pilha* novo = new No;
    novo->info = valor;
    novo->prox = topo;
    return novo;
}

// Desempilha um elemento (pop)
Pilha* desempilhar(Pilha* topo, int* valor) {
    if (topo == nullptr) return nullptr;
    *valor = topo->info;
    Pilha* temp = topo->prox;
    delete topo;
    return temp;
}

// Exibe todos os elementos da pilha
void exibir(Pilha* topo) {
    Pilha* p = topo;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->prox;
    }
    std::cout << std::endl;
}

// Libera toda a memória alocada para a pilha
void liberar(Pilha* topo) {
    Pilha* p = topo;
    while (p != nullptr) {
        Pilha* temp = p->prox;
        delete p;
        p = temp;
    }
}

int main() {
    Pilha* pilha = inicializar();
    int valor;
    for(int i = 0;i <4 ;i++){
        cin >> valor;
        pilha = empilhar(pilha,valor);
    
    }
    exibir(pilha);

    liberar(pilha);
    return 0;
}
