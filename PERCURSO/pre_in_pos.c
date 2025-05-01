#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq, *dir;
} no;

no *criar_no(int elem, no *esq, no *dir){
    no *node = malloc(sizeof(no));  
    node->dado = elem;
    node->esq = esq;
    node->dir = dir;
    return node;
}

no* inserir_no(no *node, int elem){  
    if(node == NULL){ // Se o nó não existe, ele cria um nó para ser a raiz da atual subarvore e retorna-o
        return criar_no(elem, NULL, NULL);
    }
    
    if(elem < node->dado){ // Se  o elemento a ser inserido for menor, ele é inserido na esquerda
        node->esq = inserir_no(node->esq, elem);  
    } else {
        node->dir = inserir_no(node->dir, elem);  // Se  o elemento a ser inserido for menor, ele é inserido na direita
    }
    return node;
}

// Percurso pre ordem
void pre_ordem (no *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
// Percurso em ordem
void em_ordem (no *raiz){
    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        em_ordem(raiz->dir);
    }
}
// Percurso pos ordem
void pos_ordem (no *raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}
int main(){
    int num;
    no *arvore = NULL;  // Inicializando a árvore como NULL

    while(scanf("%d", &num) != EOF){ //Enquanto a árvore não chegar ao fim de arquivo, continua lendo
        arvore = inserir_no(arvore, num);   //insere na árvore
    }
    // roda os algoritimos de busca em DFS
    pre_ordem(arvore);
    printf(".\n");
    em_ordem(arvore);
    printf(".\n");
    pos_ordem(arvore);
    printf(".\n");

    return 0;
}
