#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    struct lista *ant;
    int valor;
    struct lista *prox;
} Lista;


Lista* cria_lista();

void insere_inicio(Lista **ll, int n);
void remove_inicio(Lista **ll);

void insere_fim(Lista **ll, int n);
void remove_fim(Lista **ll);

void mostra_lista(Lista **ll);
void mostra_lista_invertida(Lista **ll);

void limpa_lista(Lista **ll);
void menu(Lista **ll);


int main(){
    Lista *lista = cria_lista();
    menu(&lista);

    return 0;
}


Lista* cria_lista(){
    return NULL;
}


void insere_inicio(Lista **ll, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return;

    novo->valor = n;
    novo->ant = NULL;
    novo->prox = *ll;
    if(novo->prox)
        novo->prox->ant = novo;
    *ll = novo;
}

void remove_inicio(Lista **ll){
    Lista *aux = *ll;

    if(!aux){
        puts("\nlista vazia!");
        return;
    }

    *ll = aux->prox;

    if(!(aux->prox)){
        free(aux);
        puts("\nremovido!\n");
        return;
    }

    aux->prox = NULL;
    (*ll)->ant = NULL;
    free(aux);
    puts("\nremovido!\n");
}


void insere_fim(Lista **ll, int n){
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    if(!novo) return;

    novo->valor = n;
    novo->prox = NULL;

    Lista *aux = *ll;

    if(!aux){
        novo->ant = NULL;
        *ll = novo;
        return;
    }

    for (; aux->prox; aux=aux->prox);

    novo->ant = aux;
    aux->prox = novo;
        
}

void remove_fim(Lista **ll){
    Lista *aux = *ll;

    if(!aux){
        puts("\nlista vazia!");
        return;
    }

    if(!(aux->prox)){
        *ll = NULL;
        free(aux);
        puts("\nremovido!\n");
        return;
    }

    for(; aux->prox; aux=aux->prox);

    aux->ant->prox = NULL;
    aux->ant = NULL;
    free(aux);
    puts("\nremovido!\n");
}


void mostra_lista(Lista **ll){
    Lista *aux = *ll;
    if (!aux){
        puts("\n(vazia)\n");
        return;
    }

    for (; aux; aux=aux->prox){
        printf("%d ", aux->valor);
    }
    puts("\n");
}

void mostra_lista_invertida(Lista **ll){
    Lista *aux = *ll;
    if (!aux){
        puts("\n(vazia)\n");
        return;
    }

    for (; aux->prox; aux=aux->prox);

    for (; aux; aux=aux->ant){
        printf("%d ", aux->valor);
    }
    puts("\n");
}


void limpa_lista(Lista **ll){
    Lista *aux = *ll;
    *ll = NULL;

    if(!aux){
        puts("\nLista vazia!\n");
        return;
    }

    for (; aux->prox;){
        aux = aux->prox;
        aux->ant->prox = NULL;
        free(aux->ant);
        aux->ant = NULL;
    }

    free(aux);
    puts("lista limpa!\n");
}

void menu(Lista **ll){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar a lista");
    puts("2: mostrar a lista invertida");
    puts("3: inserir elemento no inicio da lista");
    puts("4: inserir elemento no fim da lista");
    puts("5: remover elemento no inicio da lista");
    puts("6: remover elemento no fim da lista");
    puts("7: limpar a lista");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);
    int n;

    switch (escolha) {
        case 1: puts("\nSua lista: ");
                mostra_lista(ll);
                break;

        case 2: puts("\nSua lista (invertida): ");
                mostra_lista_invertida(ll);
                break;
        

        case 3: puts("\nQue elemento deseja inserir? ");
                scanf("%d", &n);
                insere_inicio(ll, n);
                puts("inserido!\n");
                break;

        case 4: puts("\nQue elemento deseja inserir? ");
                scanf("%d", &n);
                insere_fim(ll, n);
                puts("inserido!\n");
                break;

        case 5: remove_inicio(ll);
                break;        
        
        case 6: remove_fim(ll);
                break;

        case 7: limpa_lista(ll);
                break;

        case -1: return;

        default: puts("Valor invalido!\n");
                break;
        }

    menu(ll);
}



