#include <stdio.h>

int negativos(int n, float* vet);

int main(){
    float v[] = {1,2,3,4,5,-6,7,8,-9,10};

    printf("%d numeros negativos\n", negativos(10, v));

    return 0;
}

int negativos(int n, float* vet){
    int contadorNeg = 0;
    for (int i = 0; i<n; i++)
        if (*(vet+i) < 0)
            contadorNeg++;
    return contadorNeg;
}