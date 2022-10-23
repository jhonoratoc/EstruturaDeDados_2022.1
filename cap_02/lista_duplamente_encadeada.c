#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    struct lista *ant;
    int valor;
    struct lista *prox;
} Lista;

Lista* cria_lista();

