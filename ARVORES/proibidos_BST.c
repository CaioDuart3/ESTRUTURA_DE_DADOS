#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A)<(B))

typedef struct STnode *no;
struct STnode{
    int chave; 
    no esq, dir;
};

no criar_no( int chave , no esq, no dir){
    no raiz = malloc(sizeof(no));

    raiz->dir = dir;
    raiz->esq = esq;
    raiz->chave = chave;
    return raiz;
}

no inserir_BST(no raiz, int inserido){
    if(raiz == NULL){ 
        return criar_no(inserido, NULL, NULL);
    }

    if( less(inserido, raiz->chave) ){                          
        raiz->esq = inserir_BST(raiz->esq, inserido);
    } else if ( less(raiz->chave, inserido)) {
        raiz->dir = inserir_BST(raiz->dir, inserido);
    }
    return raiz;
}

no buscar_BST(no raiz, int buscado) {
    if (raiz == NULL) return NULL;  
    if (raiz->chave == buscado) return raiz; 

    if (less(buscado, raiz->chave)) {  
        return buscar_BST(raiz->esq, buscado); 
    } else {
        return buscar_BST(raiz->dir, buscado);
    }
}

no raiz = NULL;

int main(){
    
    int qtd_num_proib, numero, proibido;
    
    scanf("%d", &qtd_num_proib); 

    for(int x= 0; x < qtd_num_proib; x++){
        scanf("%d", &proibido);
        raiz = inserir_BST(raiz, proibido);
    }

    while(scanf("%d", &numero) != EOF){
        if(buscar_BST(raiz, numero) != NULL){
            printf("Sim\n");
        } else{
            printf("Nao\n");
        }
    }

    return 0;
}



