#include <iostream>
using namespace std;

typedef struct No {
    int info;
    struct No* prox;
} Lista;

// Inicializa a lista como vazia
Lista* inicializar() {
    return nullptr;
}

// Insere um elemento no início da lista
Lista* inserir(Lista* lista, int x) {
    Lista* novo = new No;
    novo->info = x;
    novo->prox = lista;
    return novo;
}

// Exibe todos os elementos da lista
void exibir(Lista* lista) {
    Lista* p = lista;
    while (p != nullptr) {
        std::cout << p->info << " ";
        p = p->prox;
    }
    std::cout << std::endl;
}

// Libera toda a memória alocada para a lista
void liberar(Lista* lista) {
    Lista* p = lista;
    while (p != nullptr) {
        Lista* temp = p->prox;
        delete p;
        p = temp;
    }
}

// Remove um elemento da lista (primeira ocorrência)
Lista* remover(Lista* lista, int x) {
    Lista* anterior = nullptr;
    Lista* p = lista;
    while (p != nullptr && p->info != x) {
        anterior = p;
        p = p->prox;
    }
    if (p == nullptr) return lista; // elemento não encontrado
    if (anterior == nullptr) {
        lista = p->prox; // remove o primeiro elemento
    } else {
        anterior->prox = p->prox; // remove um elemento do meio ou final
    }
    delete p;
    return lista;
}
bool encontrar(Lista* lista, int x){
    Lista* p = lista;
    while (p != nullptr) { // Percorre a lista
        if (p->info == x) { // Se encontrar o número, retorna true
            return true;
        }
        p = p->prox;
    }
    return false; // Retorna false se não encontrar
}



int main() {
    Lista* lista = inicializar();
    
   int x;
cin >> x;  // Lendo o primeiro número antes do loop

while(x != 0){  
    lista = inserir(lista, x);
    cin >> x;  // Lendo o próximo número
}

int procurado;
cin >> procurado;

bool auxiliar = encontrar(lista, procurado);

if(auxiliar==true) { // Forma mais limpa
    cout << "Encontrado" << endl;
} else {
    cout << "Nao encontrado" << endl;
}

liberar(lista);
return 0;
}
