#include <stdio.h>

//acepted 86p;

int verificaBissexto(int *ano){
    if((*ano % 4 == 0 &&  *ano %100 != 0) || (*ano % 400 == 0)){
        return 1;
    }
    return 0;
}

int verificaValidade(int *dia, int *ano){
    if(*dia < 1 && *dia > 1000){
        return 0;
    } else if (*ano < 0 && *ano > 9999){
        return 0;
    }
    return 1;
}

void calculaDiaMes(int *dia, int *ano){
    int i =0, soma=0;

    if (verificaValidade(dia, ano) == 0 ){
        printf("Entradas invalidas!\n");
        return;
    }

    if(verificaBissexto(ano) == 1){ //bissexto
        int mes[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        while (*dia > soma){
            soma+=mes[i];
            i++;
        }
        //                 148-151+31 - soma mais 31 pra achar o dia exato pelo mes completo.
        printf("%02d/%02d/%04d\n", *dia-soma+mes[i-1], i, *ano);
    }
    else{
        int mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        while (*dia > soma){
            soma+=mes[i];
            i++;
        }
        printf("%02d/%02d/%04d\n", *dia-soma+mes[i-1], i, *ano);
    }
}
int main(){
    int d , a;
    scanf(" %d %d", &d, &a);
    calculaDiaMes(&d,&a);
    return 0;
}