#include <stdio.h>

/*
Implemente uma função que calcula a área e o volume de uma esfera de raio r, obedecendo o seguinte protótipo: 
*/

void calc_esfera(float r, float* area, float* volume);

int main(){
    float A, V;
    calc_esfera(4, &A, &V);
    printf("area = %f\nvolume = %f\n", A, V);
    return 0;
}

void calc_esfera(float r, float* area, float* volume){
    *area = 4*r*r;
    *volume = *area * r/3;
}