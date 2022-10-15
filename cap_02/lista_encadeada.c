#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *no;
}Lista;


void cria_lista(Lista *l);
int lista_vazia(Lista *l);



int main(){

    // criando lista encadeada



    




}



void cria_lista(Lista *l){
    l = NULL;                   // lista l aponta para NULL
}

int lista_vazia(Lista *l){
    return (l == NULL);         // retorna 1 se a lista estiver vazia
}

