#include <stdio.h>

int pares(int n, int* vet);

int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d numeros pares\n", pares(10, v));

    return 0;
}

int pares(int n, int* vet){
    int contadorPar = 0;
    for (int i = 0; i<n; i++)
        if (vet[i]%2 == 0)
            contadorPar++;
    return contadorPar;
}