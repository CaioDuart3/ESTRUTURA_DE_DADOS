#include <stdio.h>
#include <stdlib.h>

//LISTA SEMPLESMENTE ENCADEADA.

int main(){
    struct no{
        int info;
        struct no *prox;
    };
    //cabeca so servira para apontar para o no1, não possuindo info nem prox, ele só aponta para nós do q é do tipo struct no
    struct no *cabeca = NULL;
    struct no *no1 = malloc(sizeof(struct no)); //o uso do maloc é importante pois o tamanho do primeiro no pode variar de acordo com a qtd de nós.
    struct no *no2 = malloc(sizeof(struct no));

    no1->info = 1;
    no1->prox = no2;
    no2->info = 2;
    no2->prox = NULL;

    cabeca = no1;

    printf("no1: %d\n", cabeca->info); //1
    printf("no2: %d\n", cabeca->prox->info); //2

//  cabeca -> no1 -> no2 -> null

    return 0;
}