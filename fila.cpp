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
Lista* enfileirar(Lista* lista, int valor) {
    Lista* novo = new No;
    novo->info = valor;
    novo->prox = NULL;
    
     if (lista == nullptr) { // Caso a lista esteja vazia  //não tenho um elemento previamente insrido
        return novo;
    }
    
    
    Lista* p = lista;
    while(p->prox != NULL)        
    {
        p = p->prox;
    }
    
    p -> prox = novo;
    
    return lista;
}

// Exibe todos os elementos da lista
void exibir(Lista* lista) {
    Lista* p = lista;
    while (p != nullptr) {
        cout << p->info << " ";
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
Lista* remover(Lista* lista, int valor) {
    Lista* anterior = nullptr;
    Lista* p = lista;
    while (p != nullptr && p->info != valor) {
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

int main() {
    Lista* lista = inicializar();
    
    
    int num;
    
    for(int i = 0; i < 4; i++) {
        cin >> num;
        lista = enfileirar(lista, num);
    }
    
    exibir(lista);
    

    liberar(lista);
    
    
    return 0;
}
