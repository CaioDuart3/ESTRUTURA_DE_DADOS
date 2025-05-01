#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;
    int N;
    int inicio, fim;
} fila;

fila *criar_fila(int n){
    fila *pf = malloc(sizeof(fila));
    pf->N = n;
    pf->v = malloc(n*sizeof(int));
    pf->inicio = pf->fim = 0;
    return pf;
}
int enfileira(fila *f, int x){
    if (f->fim+1 == f->inicio || (f->inicio == 0 && f->fim == f->N)){
        return 0;
    } else {
        f->v[f->fim++]= x;
        if (f->fim == f->N) f->fim = 0;
        return 1;
    }
}
int desenfileira(fila *f, int y){
    if (f->inicio == f->fim){
        return 0;
    } else {
        f->v[f->inicio++];
        return 1;
    }
    
}