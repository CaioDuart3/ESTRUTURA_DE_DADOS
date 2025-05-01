#include <stdio.h>
#include <stdlib.h>

#define hash(v, m) ((v) % (m))
#define eq(A, B) ((A) == (B))
#define max 999999


typedef struct node *link;
struct node{
    int valor, colisoes;
    link prox;
    
};

link ht[max];

void STinit(){
    for (int i = 0; i < max; i++){
        ht[i] = NULL;
    }
}

link criar_item(int valor){
    link item = malloc(sizeof(link));
    item->valor = valor;
    item->colisoes = 1;
    item->prox = NULL;
    return item;
}

void HTinsert(int valor){
    int h = hash(valor, max); //chave
    link inicio = ht[h];
    
    // tratar valores iguais
    for (link i = inicio; i != NULL; i= i->prox){ //pior caso: O(colisoes)
        if(eq(i->valor, valor)) return;
    }
    
    //insere quando o inicio é nulo OU tem menos de 10 colisoes
    if(inicio == NULL || inicio->colisoes < 10){
        link inserir = criar_item(valor);
        if(inicio != NULL){
            inserir->prox = inicio;
            inserir->colisoes += inicio->colisoes;
        }
        ht[h] = inserir;
    }
}

link HTsearch(int valor){
    int h = hash(valor, max);
    link inicio = ht[h];

    for(link i = inicio; i != NULL; i = i->prox){
        if(eq(i->valor, valor)) return i;
    }
    return NULL;
}

int main(){
    int qtd_num_proibi, numero, proibido;
    scanf("%d", &qtd_num_proibi);
    STinit();
    for (int x = 0; x < qtd_num_proibi; x++){
        scanf("%d", &proibido);
        HTinsert(proibido);
    }
    while(scanf("%d", &numero) != EOF){
        if(HTsearch(numero) != NULL) printf("Sim\n");
        else printf("Nao\n");
    }
    return 0;
}