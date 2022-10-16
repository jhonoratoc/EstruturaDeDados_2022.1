#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
} Lista;


Lista* cria_lista();

void insere_inicio(Lista **ll, int n);
void remove_inicio(Lista **ll);

void insere_fim(Lista *l, int n);
void remove_fim(Lista *l);

int lista_vazia(Lista *l);



int main(){

    Lista *lista = cria_lista();

    return 0;

}


Lista *cria_lista(){
    return NULL;
}

void insere_inicio(Lista **ll, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));       // alocando memória para o novo elemento
    novo->valor = n;                                    // preenchendo o novo elemento
    novo->prox = *ll;                                   // encadeando o novo elemento ao antigo primeiro elemento da lista
    *ll = novo;                                         // adicionando o elemento ao início da lista
}

void remove_inicio(Lista **ll){
    Lista *temp = *ll;                                  // criando um ponteiro para lista para não perder o acesso ao elemento a ser retirado
    *ll = (*ll)->prox;                                  // a partir de agora, a lista começará do antigo segundo elemento
    free(temp);                                         // liberando o elemento retirado, utilizando o ponteiro para lista
}



void insere_fim(Lista *l, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));       // alocando memória para o novo elemento
    novo->valor = n;
    Lista *no = l;
    for (; no->prox != NULL; no = no->prox);
    no->prox = novo;
    novo->prox = NULL;
}

void remove_fim(Lista *l){
    Lista *temp = l;                                        // criando um ponteiro para lista para acessar o último elemento
    for (; temp->prox->prox != NULL; temp = temp->prox);    // acessando o PENÚLTIMO elemento
    free(temp->prox);                                       // liberando o último elemento
    temp->prox = NULL;                                      // transformando o penúltimo elemento no novo último elemento
}



int lista_vazia(Lista *l){
    return (l == NULL);         // retorna 1 se a lista estiver vazia
}