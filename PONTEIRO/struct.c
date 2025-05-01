#include <stdio.h>
#include <string.h>

struct  Pessoa{
    char nome[82];
    int idade;
    float altura;
};

typedef struct
{
    char nome[22];
    int idade;
    float altura;
} Cachorro;



int main(){
    struct Pessoa p1;
    strcpy(p1.nome, "Caio Duarte");
    p1.idade = 20;
    p1.altura = 1.80;

    Cachorro c1;
    strcpy(c1.nome, "Bob");
    c1.idade = 8;
    c1.altura = 0.2;

    printf("p1: %s\nc1: %s\n", p1.nome, c1.nome);
}