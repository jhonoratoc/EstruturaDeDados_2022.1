#include <stdio.h>
#include <math.h>

/*
Implemente uma função que calcula as raízes de uma equação de 2º grau, de acordo com o seguinte protótipo:
*/

int raizes (float a, float b, float c, float *x1, float *x2);

int main(){
    float raiz1 = 0, raiz2 = 0;
    printf("%d raizes:\n", raizes(4,-4,1,&raiz1, &raiz2));
    printf("%f e %f\n", raiz1, raiz2);
    return 0;
}

int raizes (float a, float b, float c, float *x1, float *x2){
    if((b*b - 4*a*c) < 0)
        return 0;
    else if((b*b - 4*a*c) == 0){
        *x1 = *x2 = -b/(2*a);
        return 1;
    } else {
        *x1 = (-b + sqrt(b*b - 4*a*c))/2*a;
        *x2 = (-b - sqrt(b*b - 4*a*c))/2*a;
        return 2; 
    }
}