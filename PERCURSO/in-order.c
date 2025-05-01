#include <stdio.h>
#include <stdlib.h> //para usar malloc e free

// Primeiro declaramos a struct no
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Agora declaramos a pilha com ponteiros para struct no
no **pilha; //faremos dela um vetor de ponteiros, entt é um ponteiro que aponta para ponteiros do tipo no
int topo, tam;

// Cria a pilha com tamanho 'tam'
void criar_pilha(int tamanho) {
    pilha = malloc(tamanho * sizeof(no*));  
    topo = 0;
    tam = tamanho;
}

// Empilha um ponteiro para nó
void empilha(no *elem) {
    if (topo < tam) {
        pilha[topo++] = elem;
    }
}

// Desempilha e retorna um ponteiro para nó
no* desempilha() {
    if (topo > 0) {
        return pilha[--topo];
    }
    return NULL;
}

// Percurso em ordem (in-order) iterativo
void em_ordem(no *raiz) {
    criar_pilha(100); // Tamanho arbitrário da pilha

    no *atual = raiz;

    while (topo != 0 || atual != NULL) {
        // Vai o mais à esquerda possível
        while (atual != NULL) {
            empilha(atual);
            atual = atual->esq;
        }

        atual = desempilha();
        printf("%d ", atual->dado);  // Mostra o valor

        atual = atual->dir;
    }

    free(pilha); // Libera memória da pilha
}
