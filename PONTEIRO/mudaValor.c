#include <stdio.h>

void troca (int *a){
    *a = 5;
}

int main(){
    int num =3;
    printf("antigo valor: %d\n", num);
    troca(&num);
    printf("novo valor: %d\n", num);
}