#include <stdio.h>
#include <stdlib.h>

// Definições para cores dos nós
#define VERMELHO 0
#define PRETO 1

// Tipo chave e valor do item armazenado
typedef int Chave;

typedef struct {
    Chave chave;
} Item;

// Estrutura do nó da árvore Rubro-Negra
typedef struct No *PonteiroNo;

struct No {
    Item item;              // Item armazenado
    PonteiroNo esquerda;    // Ponteiro para subárvore esquerda
    PonteiroNo direita;     // Ponteiro para subárvore direita
    int tamanho;            // Número de nós na subárvore
    int cor;                // Cor do nó: VERMELHO ou PRETO
};

// Ponteiros globais para a raiz e nó nulo (sentinela)
PonteiroNo raiz, nulo;

// Função que verifica se um nó é vermelho
int ehVermelho(PonteiroNo no) {
    return no != NULL && no->cor == VERMELHO;
}

// Troca as cores de um nó e seus filhos (usado para balanceamento)
void inverterCores(PonteiroNo no) {
    no->cor = VERMELHO;
    no->esquerda->cor = PRETO;
    no->direita->cor = PRETO;
}

// Cria um novo nó com item, subárvores esquerda e direita, e tamanho
PonteiroNo novoNo(Item item, PonteiroNo esq, PonteiroNo dir, int tamanho) {
    PonteiroNo novo = malloc(sizeof(*novo));
    novo->item = item;
    novo->esquerda = esq;
    novo->direita = dir;
    novo->tamanho = tamanho;
    novo->cor = VERMELHO; // Novos nós sempre começam como vermelhos
    return novo;
}

// Inicializa a árvore Rubro-Negra
void inicializarArvore() {
    Item itemNulo = { -1 };
    nulo = novoNo(itemNulo, NULL, NULL, 0);
    nulo->cor = PRETO;
    raiz = nulo;
}

// Retorna o número total de elementos na árvore
int quantidadeElementos() {
    return raiz->tamanho;
}

// Rotação à esquerda (balanceamento)
PonteiroNo rotacionaEsquerda(PonteiroNo h) {
    PonteiroNo x = h->direita;
    h->direita = x->esquerda;
    x->esquerda = h;
    x->cor = h->cor;
    h->cor = VERMELHO;

    x->tamanho = h->tamanho;
    h->tamanho = 1 + h->esquerda->tamanho + h->direita->tamanho;
    return x;
}

// Rotação à direita (balanceamento)
PonteiroNo rotacionaDireita(PonteiroNo h) {
    PonteiroNo x = h->esquerda;
    h->esquerda = x->direita;
    x->direita = h;
    x->cor = h->cor;
    h->cor = VERMELHO;

    x->tamanho = h->tamanho;
    h->tamanho = 1 + h->esquerda->tamanho + h->direita->tamanho;
    return x;
}

// Inserção recursiva com balanceamento
PonteiroNo inserirRecursivo(PonteiroNo h, Item item) {
    if (h == nulo)
        return novoNo(item, nulo, nulo, 1);

    // Inserção na subárvore correta
    if (item.chave < h->item.chave) {
        h->esquerda = inserirRecursivo(h->esquerda, item);
    } else {
        h->direita = inserirRecursivo(h->direita, item);
    }

    // Rebalanceamentos conforme regras da árvore Rubro-Negra
    if (ehVermelho(h->direita) && !ehVermelho(h->esquerda))
        h = rotacionaEsquerda(h);
    if (ehVermelho(h->esquerda) && ehVermelho(h->esquerda->esquerda))
        h = rotacionaDireita(h);
    if (ehVermelho(h->esquerda) && ehVermelho(h->direita))
        inverterCores(h);

    h->tamanho = 1 + h->esquerda->tamanho + h->direita->tamanho;
    return h;
}

// Busca um item pela chave
PonteiroNo buscarItem(PonteiroNo noAtual, Item item) {
    if (noAtual == nulo)
        return NULL;

    if (item.chave == noAtual->item.chave)
        return noAtual;

    if (item.chave < noAtual->item.chave)
        return buscarItem(noAtual->esquerda, item);
    else
        return buscarItem(noAtual->direita, item);
}

// Função principal para leitura e busca de números proibidos
int main() {
    int quantidadeProibidos, numeroProibido, numeroConsulta;
    Item novoItem;

    inicializarArvore();

    // Leitura da quantidade de números proibidos e inserção na árvore
    scanf("%d", &quantidadeProibidos);
    for (int i = 0; i < quantidadeProibidos; i++) {
        scanf("%d", &numeroProibido);
        novoItem.chave = numeroProibido;
        raiz = inserirRecursivo(raiz, novoItem);
    }

    // Consulta de números (até o fim da entrada)
    while (scanf("%d", &numeroConsulta) != EOF) {
        novoItem.chave = numeroConsulta;
        if (buscarItem(raiz, novoItem) != NULL)
            printf("Sim\n");  // Número está na árvore (é proibido)
        else
            printf("Nao\n"); // Número não está na árvore
    }

    return 0;
}
