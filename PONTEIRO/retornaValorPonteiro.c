#include <stdio.h>

int mostra(int n){
    int *i= &n;
    return *i;
}
int main(){
    printf("%d\n", mostra(3));
}