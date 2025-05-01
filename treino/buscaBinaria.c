#include <stdio.h>


int buscaBinaria(int *v, int l, int r, int elem){
    if(l > r){
        return -1;
    }
    int m = (l+r)/2;
    if(elem == v[m]){
        return m;
    }
    if (elem < v[m]){
        return buscaBinaria(v,l,m-1,elem);
    }
    return buscaBinaria(v,m+1, r ,elem);
}
int main(){
    int v[] = {1,2,3,4,5,6,7,7,8};
    int l = 0, r = 8;
    int elem = 3;
    int resposta = buscaBinaria(v,l,r,elem);
    printf("i: %d valor: %d\n", resposta, v[resposta]);
    return 0;
}