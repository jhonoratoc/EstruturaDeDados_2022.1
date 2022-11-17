#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);
int fatorial(int n);


int main(){
    int n;
    puts("Digite um valor: ");
    scanf("%d", &n);
    printf("fatorial de %d = %d\n", n, fatorial(n));
}


int fibonacci(int n){
    int soma = 0;


}

int fatorial(int n){
    if(n == 0 || n == 1)
        return 1;
    if (n >= 2){
        return n * fatorial(n-1);
    }
}