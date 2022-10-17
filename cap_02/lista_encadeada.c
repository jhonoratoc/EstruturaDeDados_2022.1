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
int lista_vazia(Lista *l);

int menu(Lista **ll);



int main(){

    Lista *lista = cria_lista();
    menu(&lista);

    return 0;
}


Lista *cria_lista(){
    return NULL;
}



void insere_inicio(Lista **ll, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));       // alocando memória para o novo elemento
    if (!novo) return;                                      // verificando a alocação
    novo->valor = n;                                    // preenchendo o novo elemento
    novo->prox = *ll;                                   // encadeando o novo elemento ao antigo primeiro elemento da lista
    *ll = novo;                                         // adicionando o elemento ao início da lista
}

void remove_inicio(Lista **ll){
    if (!(*ll)) return;
    Lista *temp = *ll;                                  // criando um ponteiro para lista para não perder o acesso ao elemento a ser retirado
    *ll = (*ll)->prox;                                  // a partir de agora, a lista começará do antigo segundo elemento
    free(temp);                                         // liberando o elemento retirado, utilizando o ponteiro para lista
    puts("removido!\n");
}


void insere_fim(Lista **ll, int n){
    if (*ll == NULL)
        insere_inicio(ll, n);
    else{
        Lista *novo = (Lista*) malloc(sizeof(Lista));       // alocando memória para o novo elemento
        if (!novo) return;                                      // verificando a alocação
        novo->valor = n;                                    // construindo o novo elemento
        Lista *no = *ll;                                    // Lista *no com o objetivo de percorrer a lista
        for (; no->prox != NULL; no = no->prox);            // no = atual último elemento da lista
        no->prox = novo;                                    // adiciona o novo elemento ao final da lista
        novo->prox = NULL;                                  // o novo último elemento aponta para NULL
    }
}

void remove_fim(Lista **ll){
    if (!(*ll)) return;
    Lista *temp = *ll;                                      // criando um ponteiro para lista para acessar o último elemento
    if ((*ll)->prox == NULL){
        remove_inicio(ll);
        return;
    }
    for (; temp->prox->prox != NULL; temp = temp->prox);    // acessando o PENÚLTIMO elemento
    free(temp->prox);                                       // liberando o último elemento
    temp->prox = NULL;                                      // transformando o penúltimo elemento no novo último elemento
    puts("removido!\n");
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


int menu(Lista **ll){
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
                puts("inserido!\n");
                break;

        case 3: puts("\nQue elemento deseja inserir? ");
                scanf("%d", &n);
                insere_fim(ll, n);
                puts("inserido!\n");
                break;

        case 4: remove_inicio(ll);
                break;        
        
        case 5: remove_fim(ll);
                break;

        case 6: limpa_lista(ll);
                puts("lista limpa!\n");
                break;

        case -1: return 0;

        default: puts("Valor invalido!\n");
                break;
        }

    menu(ll);
}
