#include <stdio.h>
#include <stdlib.h>

/* notas do desenvolvedor: 

Uma Red black tem a mesma implementação de uma BST, com a adição das funções:
isRed, RotateLeft, RotateRight, FlipColors.

e uma adaptação na inserção e criação do nó, acrescentando mais 3 ifs

além disso vale ressaltar que:
- red black tem inserções sempre de nós vermelhos
- red black tem a raiz preta
- os nós vermelhos devem estar sempre a esquerda na left-learning
*/

#define less(A,B )((A)<(B))
#define RED 0
#define BLACK 1

typedef struct STnode *no;
struct STnode{
    int chave, cor;
    no esq, dir;
};

int isRed(no link){
    //1 se a cor do nó for vermelha (0) e obviamente o nó não for nulo
    return link != NULL && RED == link->cor; 
}

void flipColors(no link){
    //filhos ficam pretos e pai vermelho
    link->esq->cor = BLACK;
    link->dir->cor = BLACK;
    link->cor = RED;
}

no rotateRight(no h){
    //rotação, o filho esquerdo de h sobe e adota h como filho direito
    no x = h->esq;
    h->esq= x->dir;
    x->dir = h;
    //mudança de cores
    x->cor = h->cor;   //como x sobe, ele pega a cor de h
    h->cor = RED;
    return x;
}

no rotateLeft(no h){
    //rotação, o filho direito de h sobe e adota h como filho esquerdo
    no x = h->dir;
    h->dir= x->esq;
    x->esq = h;
    //mudança de cores
    x->cor = h->cor;   //como x sobe, ele pega a cor de h
    h->cor = RED;
    return x;
}


no criar_no(int inserido, no esq, no dir){
    no raiz = malloc(sizeof(no));
    raiz->esq = esq;
    raiz->dir = dir;
    raiz->chave = inserido;
    // adaptação para RED BLACK
    raiz->cor = RED; // inserimos sempre como vermelho.
    return raiz;
}

no inserir_RB(no raiz, int inserido){
    if(raiz == NULL) return criar_no(inserido, NULL,NULL);
    
    if(less(inserido,raiz->chave)){
        raiz->esq = inserir_RB(raiz->esq, inserido);
    } else if(less(raiz->chave, inserido)) {
        raiz->dir = inserir_RB(raiz->dir, inserido);
    } 

    //adaptação para RED BLACK
    if(isRed(raiz->dir) && !isRed(raiz->esq)) raiz = rotateLeft(raiz); 
    if(isRed(raiz->esq) && isRed(raiz->esq->esq)) raiz = rotateRight(raiz); 
    if(isRed(raiz->esq) && isRed(raiz->dir)) flipColors(raiz); 

    return raiz;
}

no buscar_RB( no raiz, int buscado){
    if(raiz == NULL) return NULL;
    if(raiz->chave == buscado) return raiz;
    
    if(less(buscado, raiz->chave)) return buscar_RB(raiz->esq, buscado);
    else return buscar_RB(raiz->dir,buscado);
}

no raiz = NULL;

// Função para imprimir em ordem a árvore com as cores
void imprimir_em_ordem(no raiz) {
    if (raiz == NULL) return;
    imprimir_em_ordem(raiz->esq);
    printf("Chave: %d, Cor: %s\n", raiz->chave, raiz->cor == RED ? "VERMELHO" : "PRETO");
    imprimir_em_ordem(raiz->dir);
}

int main() {
    // Inserindo valores
    int valores[] = {13, 5, 14, 9, 14, 1, 19, 3, 15, 13, 16};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir_RB(raiz, valores[i]);
        raiz->cor = BLACK; // Garante que a raiz sempre seja preta
    }

    printf("Árvore Red-Black (em ordem):\n");
    imprimir_em_ordem(raiz);

    return 0;
}
