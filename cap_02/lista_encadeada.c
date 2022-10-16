#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
} Lista;


Lista* cria_lista();

void insere_inicio(Lista **ll, int n);      // precisa de ponteiro pra ponteiro
void remove_inicio(Lista **ll);             // precisa de ponteiro pra ponteiro

void insere_fim(Lista **ll, int n);
void remove_fim(Lista **ll);

void mostra_lista(Lista **ll);

void limpa_lista(Lista **ll);

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



void insere_fim(Lista **ll, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));       // alocando memória para o novo elemento
    novo->valor = n;                                    // construindo o novo elemento
    Lista *no = *ll;                                    // Lista *no com o objetivo de percorrer a lista
    for (; no->prox != NULL; no = no->prox);            // no = atual último elemento da lista
    no->prox = novo;                                    // adiciona o novo elemento ao final da lista
    novo->prox = NULL;                                  // o novo último elemento aponta para NULL
}

void remove_fim(Lista **ll){
    Lista *temp = *ll;                                      // criando um ponteiro para lista para acessar o último elemento
    for (; temp->prox->prox != NULL; temp = temp->prox);    // acessando o PENÚLTIMO elemento
    free(temp->prox);                                       // liberando o último elemento
    temp->prox = NULL;                                      // transformando o penúltimo elemento no novo último elemento
}


void mostra_lista(Lista **ll){
    
}


void limpa_lista(Lista **ll){
    Lista *temp_free = *ll;                     // apontará para o elemento a ser liberado
    Lista *temp_prox = (*ll)->prox;             // apontará para o elemento seguinte
    *ll = NULL;                                 // esvazia a lista

    // hora de liberar os elementos
    for (; temp_prox =! NULL; temp_prox = temp_prox->prox){
        temp_free->prox = NULL;         // anula o ponteiro pro próximo elemento
        free(temp_free);                // libera o elemento
        temp_free = temp_prox;          // prepara o próximo elemento a ser liberado
    }

    // liberando o último elemento
    free(temp_free);
}


int lista_vazia(Lista *l){
    return (l == NULL);         // retorna 1 se a lista estiver vazia
}