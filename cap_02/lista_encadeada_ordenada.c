#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
} Lista;


Lista* cria_lista();

void insere(Lista **ll, int n);      // precisa de ponteiro pra ponteiro
void remove1(Lista **ll, int n);      // precisa de ponteiro pra ponteiro

void mostra_lista(Lista **ll);

void limpa_lista(Lista **ll);               // precisa de ponteiro pra ponteiro
int lista_vazia(Lista *l);

void menu(Lista **ll);



int main(){

    Lista *lista = cria_lista();
    menu(&lista);
    return 0;
}


Lista *cria_lista(){
    return NULL;
}



void insere(Lista **ll, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return;
    
    novo->valor = n;

    if (((*ll) == NULL) || ((*ll)->valor >= n)){
        novo->prox = *ll;
        *ll = novo;
        puts("inserido!\n");
    } else {
        Lista *insere;
        insere = *ll;
        for (; insere->prox && insere->prox->valor < n; insere = insere->prox);
        novo->prox = insere->prox;
        insere->prox = novo;
        puts("inserido!\n");
    }
}

void remove1(Lista **ll, int n){
    if (!(*ll)){
        puts("\nlista vazia!\n");
        return;
    }

    Lista *aux = *ll;

    if((*ll)->prox == NULL || (*ll)->valor == n){
        if((*ll)->valor == n){
            *ll = aux->prox;
            aux->prox = NULL;
            free(aux);
            puts("removido!\n");
        }else{
            puts("valor nao existe!\n");
        }
    } else {
        for(; aux->prox->prox && aux->prox->prox->valor <= n; aux = aux->prox);
        Lista *remove = aux->prox;
        if (remove->valor != n)
            puts("valor nao existe!\n");
        else{
            aux->prox = remove->prox;
            remove->prox = NULL;
            free(remove);
            puts("removido!\n");
        }
    }
}


void mostra_lista(Lista **ll){
    if (!(*ll)){
        puts("(vazia)\n");
        return;
    }
    Lista *no = *ll;
    for (; no != NULL; no = no->prox)
        printf("%d ", no->valor);
    puts("\n");
}


void limpa_lista(Lista **ll){
    Lista *temp_free = *ll;                     // apontará para o elemento a ser liberado
    Lista *temp_prox = (*ll)->prox;             // apontará para o elemento seguinte
    *ll = NULL;                                 // esvazia a lista

    // hora de liberar os elementos
    for (; temp_prox != NULL; temp_prox = temp_prox->prox){
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


void menu(Lista **ll){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar a lista");
    puts("2: inserir elemento");
    puts("3: remover elemento");
    puts("4: limpar a lista");
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
                insere(ll, n);
                break;

        case 3: puts("\nQue elemento deseja remover? ");
                scanf("%d", &n);
                remove1(ll, n);
                break;

        case 4: limpa_lista(ll);
                puts("lista limpa!\n");
                break;

        case -1: return;

        default: puts("Valor invalido!\n");
                break;
        }

    menu(ll);
}
