#include <stdio.h>

int main(){
    int ***p1;
    int **p2;
    int *p3;
    int i = 10;
    p3 = &i;
    p2 = &p3;
    p1 = &p2;

    printf("apontamento de p1: %p\n", **p1); 
    printf("apontamento de p2: %p\n", *p2); 
    printf("apontamento de p3: %d\n", *p3); 


}