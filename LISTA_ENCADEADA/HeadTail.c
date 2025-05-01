#include <stdio.h>
#include <stdlib.h>
int main(){
    typedef struct node no;
    
    struct node{
        int info;
        no *prox;
    };
    no *cabeca = malloc(sizeof(no));
    no *no1 = malloc(sizeof(no));
    no *no2 = malloc(sizeof(no));
    no *cauda = malloc(sizeof(no));

    cabeca->prox = no1;
    cauda->prox = no2;
    
    no1->prox = no2;
    no1->info = 6;

    no2->prox = NULL;
    no2->info = 9;

    printf("no1: %d\n", cabeca->prox->info);
    printf("no2: %d\n", cabeca->prox->prox->info);

    printf("no2 pela cauda: %d\n", cauda->prox->info);

}