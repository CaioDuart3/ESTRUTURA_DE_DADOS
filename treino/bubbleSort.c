#include <stdio.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *v, int l, int r) {
    int flag;
    for (int i = l; i < r; i++) {
        flag = 0;
        for (int j = l; j < r; j++) { // Ajuste no limite
            if (v[j] > v[j + 1]) {
                swap(&v[j], &v[j + 1]); // Corrigido com &
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

// Testando o código
int main() {
    int v[] = {1, 3, 2, 5, 7};
    int n = sizeof(v) / sizeof(v[0]);

    bubbleSort(v, 0, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
