#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira( fila *f, int x ){
    if ( f->u+1==f->p || (f->u== f->N && f->p == 0)){
        f->N*=2;
        f->dados = realloc(f->dados, f->N*sizeof(int));
        return 0;
    } else {
        f->dados[f->u++] = x;
        return 1;
    }
}
// fila *criar(int n){
//     fila *pf = malloc(sizeof(fila));
//     pf->N = n;
//     pf->dados = malloc(n*sizeof(int));
//     pf->p = pf->u = 0;
//     return pf;
// }

// int main(){
//     fila *pf = criar(5);
    
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,5), pf->p, pf->u, pf->dados[pf->u-1]);
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,4), pf->p, pf->u, pf->dados[pf->u-1]);
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,3), pf->p, pf->u, pf->dados[pf->u-1]);
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,2), pf->p, pf->u, pf->dados[pf->u-1]);
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,1), pf->p, pf->u, pf->dados[pf->u-1]);
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,1), pf->p, pf->u, pf->dados[pf->u-1]);
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,3), pf->p, pf->u, pf->dados[pf->u-1]);
//     printf("status:%d p: %d u: %d elem: %d\n" , enfileira(pf,3), pf->p, pf->u, pf->dados[pf->u-1]);
//     return 0;
// }