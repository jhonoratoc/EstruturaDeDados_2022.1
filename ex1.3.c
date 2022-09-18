#include <stdio.h>

/*
Implemente uma função que retorna o n-ésimo termo da sequência de fibonacci
*/

int fibonacci(int);

int main(){
    printf("%d\n", fibonacci(5));
    return 0;

}

int fibonacci(int n){
    if (n==1 || n==2)
        return 1;
    int v1 = 1, v2 = 1, temp;
    for (int i=3; n>=i; i++){
        temp = v1+v2;
        v1=v2;
        v2=temp;
    }
    return v2;
}