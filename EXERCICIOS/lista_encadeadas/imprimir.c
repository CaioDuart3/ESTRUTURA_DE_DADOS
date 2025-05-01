#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le){
    for (celula *i = le-> prox; i ; i = i->prox)
    {
        printf("%d -> ", i->dado);
    }
    
    printf("NULL\n");
}
void imprime_rec(celula *le){
    if(le->prox == NULL) printf("NULL\n");
    else{
        printf("%d -> ", le->prox->dado);
        le = le->prox;
        return imprime_rec(le);
    }
}