#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
} Lista;


Lista* cria_lista();

void insere_inicio(Lista **ll, int n);
void remove_inicio(Lista **ll);

int lista_vazia(Lista *l);



int main(){

    Lista *lista = cria_lista();

    return 0;

}


Lista *cria_lista(){
    return NULL;
}

void insere_inicio(Lista **ll, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->valor = n;
    novo->prox = *ll;
    *ll = novo;
}

void remove_inicio(Lista **ll){
    Lista *temp = *ll;
    *ll = (*ll)->prox;
    free(temp);
}

int lista_vazia(Lista *l){
    return (l == NULL);         // retorna 1 se a lista estiver vazia
}