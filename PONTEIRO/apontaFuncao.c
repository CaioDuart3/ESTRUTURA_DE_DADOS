#include <stdio.h>


// * modelo 1:

int mostrar(int n){
    int *i = &n;
    return *i;
}
int main(){
    int (*p)(int) = &mostrar; //ponteiro aponta para um função.

    printf("%d\n",(*p)(10)); // 10
}

// * modelo 2:

int *mostrar(int n){
    int *i = &n;
    return i;
}
int main(){
    int *p = mostrar(10);  //ponteiro recebe um ponteiro da função.

    printf("%d\n",*p); //10
}

// modelo 1 != modelo 2