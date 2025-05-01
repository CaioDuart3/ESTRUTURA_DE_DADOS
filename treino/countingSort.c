#include <stdio.h>
#define MAX 10000
#define R 5

int aux[MAX];

void countingsort(int *v, int l, int r) {
    int i, count[R + 1];

    // zerando
    for (i = 0; i <= R; i++) count[i] = 0;

    // frequências
    for (i = l; i <= r; i++) count[v[i] + 1]++;

    // posições
    for (i = 1; i <= R; i++) count[i] += count[i - 1];

    // distribuição
    for (i = l; i <= r; i++) aux[count[v[i]]++] = v[i];

    // cópia: a partir de aux[l]; ex.: i=l=3, i-l=0
    for ( i = l ; i <= r ; i ++) v [ i ] = aux [i - l ];
}

int main() {
    int N;
    scanf("%d", &N);

    int v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    countingsort(v, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d, ", v[i]);
    }
    return 0;
}
