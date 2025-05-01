#include <stdio.h>
int main(){
    char palavra[12] = "Caio";
    char *ptr_char = palavra;
    //ptr_char = palavra;

    float pi = 3.1415;
    float *ptr_fl = &pi;
    //ptr_fl = &pi;

    printf("%ld\n%ld\n", (long )ptr_char, (long) ptr_fl); // endereco endereco

    printf("%s\n%p\n", ptr_char, ptr_fl); // Caio endereco

    printf("%c\n%f\n", *ptr_char, *ptr_fl); // C 3.141500

    return 0;
}