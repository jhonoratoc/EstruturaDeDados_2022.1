#include <stdio.h>

/*
Implemente uma função que retorna uma aproximação do valor de pi, de acordo com a fórmula de Leibniz

pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 .....)
*/

double pi(int);

int main(){
    printf("%f\n", pi(6));
    printf("%d\n", 1%2);
    return 0;
}

double pi(int n){
    double soma=0;
    for(double i=0; i<=n; i++){
        if((int)i%2==0)
            soma+=1/(2*i+1);
        else
            soma-=1/(2*i+1);
    }
    return 4*soma;
}