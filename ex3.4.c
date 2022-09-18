#include <stdio.h>
#include <math.h>

double avalia(double *poli, int grau, double x);

int main(){
    double p[] = {1,2,3};

    printf("%f\n", avalia(p, 2, 4));
    return 0;
}

double avalia(double *poli, int grau, double x){
    double soma=0;
    for (int i=0; i<=grau; i++)
        soma += *(poli+i)*pow(x,i);
    return soma;
}