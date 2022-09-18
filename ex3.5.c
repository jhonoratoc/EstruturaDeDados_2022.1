#include <stdio.h>

void deriva(double* poli, int grau, double* out);

int main(){

    double p[] = {1,2,3,4};
    double derivada[3];

    deriva(p, 3, derivada);

    for (int i=0; i<3; i++)
        printf("%f ", *(derivada+i));

    return 0;
}

void deriva(double* poli, int grau, double* out){
    for (int i=0; i<grau; i++)
        out[i] = poli[i+1]*(i+1);
}