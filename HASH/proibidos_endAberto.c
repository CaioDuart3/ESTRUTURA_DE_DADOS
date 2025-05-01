//endereçamento aberto

#include <stdio.h>
#include <stdlib.h>
#define hash(v,m) (v%m)
#define maxCol 10
#define eq(A,B) ((A)==(B))

int *ht; //aponta para uma lista de inteiros
int M; //qtd de posiçoes em ht (tamanho da lista)

void STinit(int max){
    //aloca na memória
    ht = malloc(sizeof(int)*max);
    M = max;
    //preenche os endereços de ht com -1 (valores nulo)
    for (int i = 0; i < max; i++){
        ht[i] = -1;
    }
}

void HTinsert(int inserido){
    int h = hash(inserido, M); //encontra a posição hasheada
    int hn = -1;
    
    for(int colisoes = maxCol; colisoes > 0; colisoes--, h = (h+1)%M){
        if(eq(ht[h], -1)){ //inserir
            hn = h;
        } else if (eq(ht[h], inserido)){
            return;
        }
    }
    if(hn != -1){
        ht[hn] = inserido;
    }
}

int HTsearch(int inserido){
    int h = hash(inserido, M); //encontra a posição hasheada
    int colisoes = maxCol;

    //enquanto puder dar colisão e encontrar valores nas posições da lista
    while (colisoes && !eq(ht[h],inserido)){
        colisoes--; //diminui as colisões
        h = (h+1)%M;
    }
    if(!colisoes){
        return -1;
    }
    return ht[h];
}


int main(){
    int qtd_num_proibi, numero, proibido;
    scanf("%d", &qtd_num_proibi);
    STinit(999999);
    for (int x = 0; x < qtd_num_proibi; x++){
        scanf("%d", &proibido);
        HTinsert(proibido);
    }
    while(scanf("%d", &numero) != EOF){
        if(HTsearch(numero) != -1) printf("sim\n");
        else printf("nao\n");
    }
    return 0;
}