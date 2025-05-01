#include <stdio.h>


struct Pessoa{
    int idade;
};
int main(){
    struct Pessoa p1;
    struct Pessoa *p  = &p1; //ponteiro é definido como uma struct do tipo Pessoa.
    (*p).idade = 12;  //como acessar pelo ponteiro
    printf("%d\n", p->idade); //outra forma de acessar pelo ponteiro
}