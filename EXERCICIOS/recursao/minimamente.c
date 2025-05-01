#include <stdio.h>

// ! incompleto e não testado

void minimamente( int *v, int limite){
    
    return minimamente(v,limite);
}


int main(){
    int v[1000];
    int limite;
    int i = 0;
    
    while (1){
        scanf(" %d", &v[i]);
        if (v[i] == 0) break;
        i++;
    }
    i+=1; //ultimo incremento para acompanhar o vetor v

    scanf(" %d", &limite);
    
    minimamente(v,limite);
}

