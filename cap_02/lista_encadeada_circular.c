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
void limpa_lista(Lista **ll);               // precisa de ponteiro pra ponteiro
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
    if(!novo) return;

    novo->valor = n;

    if(!(*ll)){
        novo->prox = novo;
        *ll = novo;
        puts("inserido!\n");
        return;
    }

    Lista *aux = *ll;
    for (; aux->prox != (*ll); aux = aux->prox);

    novo->prox = *ll;
    aux->prox = novo;
    *ll = novo;
    puts("inserido!\n");
}

void remove_inicio(Lista **ll){
    Lista *aux = *ll;

    if(!(*ll)){     // lista vazia
        puts("\nlista vazia!\n");
        return;
    }

    if(aux->prox == aux){       // lista unitária
        *ll = NULL;
        free(aux);
        puts("\nremovido!\n");
        return;
    }

    for(; aux->prox != (*ll); aux = aux->prox);     // aux = último elemento

    Lista *remove = *ll;
    *ll = remove->prox;
    remove->prox = NULL;
    aux->prox = *ll;
    free(remove);
    puts("\nremovido!\n");
}


void insere_fim(Lista **ll, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return;

    novo->valor = n;

    if(!(*ll)){
        novo->prox = novo;
        *ll = novo;
        puts("inserido!\n");
        return;
    }

    novo->prox = *ll;
    Lista *aux = *ll;
    for(; aux->prox != (*ll); aux = aux->prox);
    aux->prox = novo;
    puts("inserido!\n");
}

void remove_fim(Lista **ll){
    Lista *aux = *ll;

    if(!(*ll)){
        puts("\nlista vazia!\n");
        return;
    }

    if(aux->prox == aux){       // lista unitária
        *ll = NULL;
        free(aux);
        puts("\nremovido!\n");
        return;
    }

    for (; aux->prox->prox != (*ll); aux = aux->prox);

    Lista *remove = aux->prox;
    aux->prox = *ll;
    remove->prox = NULL;
    free(remove);
    puts("\nremovido!\n");
}


void mostra_lista(Lista **ll){
    Lista *aux = *ll;

    if(!aux){
        puts("\n(lista vazia)\n");
        return;
    }

    printf("%d ", aux->valor);
    aux = aux->prox;

    for(; aux != (*ll); aux=aux->prox){
        printf("%d ", aux->valor);
    }
    puts("\n");
}

void limpa_lista(Lista **ll){
    if(!(*ll)){
        puts("\n(lista vazia)\n");
        return;
    }

    Lista *aux = *ll;
    for (; aux->prox != (*ll); aux = aux->prox);
    aux->prox = NULL;       // transforma uma lista encadeada simples

    // preparando para limpar
    Lista *limpa = *ll;
    aux = *ll;

    // manutenção da integridade da lista
    *ll = NULL;             

    for(; aux != NULL; ){
        aux = aux->prox;
        limpa->prox = NULL;
        free(limpa);
        limpa = aux;
    }

    puts("\nlista limpa!\n");
}

void menu(Lista **ll){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar a lista");
    puts("2: inserir elemento no inicio da lista");
    puts("3: inserir elemento no fim da lista");
    puts("4: remover elemento no inicio da lista");
    puts("5: remover elemento no fim da lista");
    puts("6: limpar a lista");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);
    int n;

    switch (escolha) {
        case 1: puts("\nSua lista: ");
                mostra_lista(ll);
                break;

        case 2: puts("\nQue elemento deseja inserir? ");
                scanf("%d", &n);
                insere_inicio(ll, n);
                break;

        case 3: puts("\nQue elemento deseja inserir? ");
                scanf("%d", &n);
                insere_fim(ll, n);
                break;

        case 4: remove_inicio(ll);
                break;        
        
        case 5: remove_fim(ll);
                break;

        case 6: limpa_lista(ll);
                break;

        case -1: return;

        default: puts("Valor invalido!\n");
                break;
        }

    menu(ll);
}