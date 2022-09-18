#include <stdio.h>

#define N 100

struct lista{
    int n;
    int vetor[N];
};

int soma_todos(struct lista *);

int main() {
    struct lista l = {-1, {1, 2, 3, 4, 5}};
    printf("soma = %d\n", soma_todos(&l));
    return 0;
}

int soma_todos(struct lista *l1) {
    int soma = 0;
    for (int i = 0; i <= l1->n; i++)
        soma += l1->vetor[i];
    return soma;
}









