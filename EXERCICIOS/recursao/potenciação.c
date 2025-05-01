#include <stdio.h>

double potencia( double a, double b){
    if (b == 0) return 1;

    else if (b>0){
        return a*potencia(a,b-=1);
    }

    else if (b < 0){
        return 1/a*potencia(a,b+=1);
    }
}

int main(){
    double a,b;
    scanf(" %lf %lf", &a,&b);
    if (a==0 && b<=0 ){
        printf("indefinido\n");
        return 0;
    }
    printf("%lf\n", potencia(a,b));
    return 0;
}
