#include <stdio.h>

void swapX2Y( char *txt){
    if (*txt == '\0') return;
    if (*txt == 'x') *txt='y';
    return swapX2Y(txt+1);
}
    //printf("%c\n", *txt); // imprime o caracter no endereço 0;
    // printf("%p\n", txt);// imprime o endereço da string
    //printf("%s\n", txt);// imprime a string a partid do endereço 0 até o \0
    //printf("%s\n", txt+1);// imprime a string a partir do endereço 1 até o \0


int main(){
    char text[82]; // 80 caracteres + \n + \0
    scanf(" %s", text);
    swapX2Y(text);
    printf("%s\n", text);
    return 0;
}