#include <stdio.h>

/*
Implemente uma função que retorna a soma dos n primeiros números naturais ímpares
*/

int soma_impares(int);

int main(){
    printf("%d\n", soma_impares(2));
    return 0;
}

int soma_impares(int n){
    return n*n;
}