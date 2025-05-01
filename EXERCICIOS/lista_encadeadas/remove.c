#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void remove_depois(celula *p){
    if (p->prox == NULL)
    {
        return;
    }
    p->prox = p->prox->prox;
}

void remove_elemento(celula *le , int x){
    celula *noN = le->prox;
    celula *noN_1 = le;
    while(noN){
        if (noN->dado == x)
        {
            noN_1->prox = noN->prox;
            break;
        }
        noN=noN->prox;
        noN_1 = noN_1->prox;
    }
}

void remove_todos_elementos(celula *le, int x){
    celula *noN = le->prox;
    celula *noN_1 = le;

    while(noN){ //enquanto não ser nulo.
        if (noN->dado == x){
            noN_1->prox =noN->prox; //achou o elemento X, o anterior aponta pro posterior de X, pra X sumir, logo ele itera.
            noN = noN->prox; //itera o atual para continuar em sincronia
            continue; //continue pra pular a iteração e não iterar novamente.
        }
        // se não achou itera para o próximo:
        noN = noN->prox; 
        noN_1 = noN_1->prox;
    }
}

// int main(){
    // celula *le = malloc(sizeof(celula));
    // celula *no1 = malloc(sizeof(celula));
    // celula *no2 = malloc(sizeof(celula));
    // celula *no3 = malloc(sizeof(celula));
    // celula *no4 = malloc(sizeof(celula));
    // le->prox = no1;
    // no1->prox = no2;
    // no2->prox = no3;
    // no3->prox = no4;
    // no4->prox = NULL;

    // int x = 2;
    // no1->dado = 1;
    // no2->dado = 2;
    // no3->dado = 2;
    // no4->dado = 2;
    //remove_elemento(le,x);
    //remove_depois(no4);
    // remove_todos_elementos(le,x);
    // imprime(le);
// }