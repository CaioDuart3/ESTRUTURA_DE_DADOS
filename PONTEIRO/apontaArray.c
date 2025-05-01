#include <stdio.h>
int main(){
    int v[3]= {0,1,2};
    int *p = v; // pega o endereço
    // p = v; // pega o endereço
    printf("%d\n", p[0]); //0
}