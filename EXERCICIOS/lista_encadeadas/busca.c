#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    for (celula *i = le; i; i=i->prox){
        if (i->dado == x){
            return i;
        }
    }
    return NULL;
}

celula *busca_rec( celula *le, int x){
        if (le->dado == x || le ==  NULL){
            return le;
        }
        le=le->prox; //recebe o proximo nó.
        return busca_rec(le, x);
}

// ! dá erro de time limit exceeded no moj, creio q é pq n há tratamento para os NULL, mas tb n sei oq o moj espera.


// int main(){
//     celula *le = malloc(sizeof(celula));
//     celula *no1 = malloc(sizeof(celula));
//     celula *no2 = malloc(sizeof(celula));
//     celula *no3 = malloc(sizeof(celula));

//     le->prox = no1;
//     no1->prox = no2;
//     no2->prox = no3;
//     no3->prox = NULL;

//     no1->dado = 1;
//     no2->dado = 2;
//     no3->dado = 3;

//     printf("%d\n", busca(le,2)->dado);
//     return 0;
// }

