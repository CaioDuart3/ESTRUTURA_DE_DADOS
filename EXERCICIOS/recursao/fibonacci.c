#include <stdio.h>

long int fibonacci (int n){
    if (n == 1 || n == 2){
        return 1;
    } else {
        return (fibonacci(n-1)+ fibonacci(n-2));
    }
}

int main(){
    int n; 
    scanf(" %d", &n);
    printf("%ld\n" , fibonacci(n));
    return 0;
}

// ! ta certo, porém no MOJ dá erro de compilação, não faço ideia do porquê.