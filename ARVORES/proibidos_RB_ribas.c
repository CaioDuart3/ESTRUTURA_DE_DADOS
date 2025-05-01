#include <stdlib.h>
#include <stdio.h>

// Defines para RED-BLACK
enum tipo { RED, BLACK };

#define Key int
#define data char*
#define less(a, b) ((a) < (b))
#define NULLitem (Item){-1}
#define RED 0 
#define BLACK 1


typedef struct {
    Key K;
    // data D;
} Item;

typedef struct STnode *link;

struct STnode {
    Item item;
    link left, right;
    int N;
    int color;
};

link h, z; //h é a raiz e z é o nó nulo.

// Verifica se nó é vermelho
int isRed(link no) {
    return no != NULL && no->color == RED;
}

// Troca as cores dos nós
void flipColors(link no) {
    no->right->color = BLACK;
    no->left->color = BLACK;
    no->color = RED;
}

// Cria um novo nó
link NEW(Item item, link left, link right, int N) {
    link no = malloc(sizeof(*no));
    no->item = item;
    no->left = left;
    no->right = right;
    no->N = N;
    no->color = RED; // inicializa como vermelho
    return no;
}

// Inicializa a árvore
void STinit() {
    z = NEW(NULLitem, NULL, NULL, 0);
    z->color = BLACK;
    h = z;
}

// Retorna a quantidade de nós
int STcount() {
    return h->N;
}

// Rotação para a esquerda
link rotateLeft(link h) {
    link x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    x->N = h->N;
    h->N = 1 + h->left->N + h->right->N;
    return x;
}

// Rotação para a direita
link rotateRight(link h) {
    link x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    x->N = h->N;
    h->N = 1 + h->left->N + h->right->N;
    return x;
}

// Inserção recursiva
link insertR(link h, Item item) {
    if (h == z) return NEW(item, z, z, 1);

    if (less(item.K, h->item.K)) {
        h->left = insertR(h->left, item);
    } else {
        h->right = insertR(h->right, item);
    }

    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) flipColors(h);

    h->N = 1 + h->left->N + h->right->N;
    return h;
}

// Busca por item
link STsearch(link h, Item item) {
    if (h == z) return NULL;

    if (h->item.K == item.K) return h;

    if (less(item.K, h->item.K)) {
        return STsearch(h->left, item);
    } else {
        return STsearch(h->right, item);
    }
}

int main() {
    int qtd_num_proib, proibidos, num;
    Item item;

    STinit(); // Inicializa a árvore rubro-negra

    scanf("%d", &qtd_num_proib);

    for (int x = 0; x < qtd_num_proib; x++) {
        scanf("%d", &proibidos);
        item.K = proibidos;
        h = insertR(h, item); // atualiza o ponteiro raiz da árvore
    }

    while (scanf("%d", &num) != EOF) {
        item.K = num;
        if (STsearch(h, item) != NULL)
            printf("Sim\n");
        else
            printf("Nao\n");
    }

    return 0;
}
