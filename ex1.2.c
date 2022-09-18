#include <stdio.h>

/*
Implemente uma função para testar se um número é primo ou não
A função deve retornar 1 se n for primo e 0 se não for
*/

int primo (int);

int main(){
    printf("%d\n", primo(1));
    return 0;
}


int primo (int n){
    if (n==0 || n==1)
        return 0;
    else
        for (int j=n-1; j>1; j--)
            if (n%j == 0)
                return 0;
    return 1;
}