#include <stdio.h>

void inverte(int n, int* vet);

int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10};

    inverte(10, v);
    for (int i=0; i<10; i++)
        printf("%d ", v[i]);

    return 0;
}

void inverte(int n, int* vet){
    int temp;
    for (int i=0, j=n-1; i<j; i++, j--){
        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}