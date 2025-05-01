#include <stdlib.h>
#include <stdio.h>


typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

// void imprime(celula *le){
//     for (celula *i = le-> prox; i ; i = i->prox)
//     {
//         printf("%d -> ", i->dado);
//     }
    
//     printf("NULL\n");
// }

void insere_inicio(  celula *le, int x){
    celula *no0 = malloc(sizeof(celula));
    no0->prox = le->prox;
    le->prox = no0;
    no0->dado = x;
}

void insere_antes( celula *le, int x , int y){
    celula *noN = le->prox; //recebe quem a cabeca aponta, logo no1;
    celula *noN_1 = le; // recebe a cabeca;
    celula *noInserir = malloc(sizeof(int));
    int verifica_y =0;

    while (noN){ // enqto n for nulo

        if(noN->dado == y ){
            verifica_y++;
            noN_1->prox=noInserir;
            noInserir->dado = x;
            noInserir->prox=noN;
            break;
        }
        noN=noN->prox; // o atual aponta para o proximo                            //! na ultima iteração ele aponta para o NULL
        noN_1= noN_1->prox; //o anterior aponta para o ex-atual ;
    }
    if (verifica_y==0){ //não achou y
        noInserir->dado = x;
        noInserir->prox=NULL;
        noN_1 ->prox= noInserir;                             //! colocar noN_1, pois noN é NULL.
    }
    
}

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
//     no3->dado = 4;

//     insere_antes(le, 3,5);
//     imprime(le);

//     return 0;
// }
