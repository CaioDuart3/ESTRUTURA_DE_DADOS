#include <stdio.h>
#include <stdlib.h>

#define hash(v,m) (v % m)
#define eq(A,B) ((A) == (B))

int *ht; // tabela hash
int M;   // tamanho da tabela

void STinit(int max) {
    ht = malloc(sizeof(int) * max);
    M = max;
    for (int i = 0; i < max; i++) {
        ht[i] = -1; // -1 representa "vazio"
    }
}

void HTinsert(int inserido) {
    int h = hash(inserido, M);
    while (ht[h] != -1 && !eq(ht[h], inserido)) {
        h = (h + 1) % M;
    }
    ht[h] = inserido;
}

int HTsearch(int inserido) {
    int h = hash(inserido, M);
    int start = h; // para evitar loop infinito
    while (ht[h] != -1) {
        if (eq(ht[h], inserido)) {
            return h;
        }
        h = (h + 1) % M;
        if (h == start) break; // percorreu toda a tabela
    }
    return -1;
}

// Função de remoção que reordena os elementos para manter a propriedade da tabela hash
void HTdelete(int inserido) {
    int pos = HTsearch(inserido);
    if (pos == -1) return; // não encontrado

    ht[pos] = -1; // remove o elemento

    // Reorganiza os elementos seguintes
    int h = (pos + 1) % M;
    while (ht[h] != -1) {
        int val = ht[h];
        ht[h] = -1;
        HTinsert(val); // reinserir o elemento
        h = (h + 1) % M;
    }
}

int main() {
    int qtd_num_proibi, numero, proibido;
    scanf("%d", &qtd_num_proibi);
    STinit(999999);

    for (int x = 0; x < qtd_num_proibi; x++) {
        scanf("%d", &proibido);
        HTinsert(proibido);
    }

    while (scanf("%d", &numero) != EOF) {
        if (HTsearch(numero) != -1) printf("sim\n");
        else printf("nao\n");
    }

    return 0;
}
