#include <stdio.h>

int *fa () {
    int a = -9;
    int * i = &a;
    return i ;
}

int * fb () {
    static int a = 1;
    int * i = &a;
    return i;
}

void fc () {
    int s[10] = {0}; // stack ou data ?
}

int main () {
    int *b = fa () , *c = fb () ;
    fc ();
    printf ("%d %d\n", *b , *c); //0 1
    return 0;
}