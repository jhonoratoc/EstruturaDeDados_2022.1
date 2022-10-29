#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
} Lista;


Lista* cria_lista();

void insere_inicio(Lista **ll, int n);
void remove_inicio(Lista **ll);

void insere_fim(Lista **ll, int n);
void remove_fim(Lista **ll);

void mostra_lista(Lista **ll);

void limpa_lista(Lista **ll);
int lista_vazia(Lista *l);

// exercício 2.1
int comprimento(Lista *l);
// exercício 2.2
int maiores(Lista *l, int n);
// exercício 2.3
Lista *ultimo(Lista *l);
// exercício 2.4
Lista *concatena(Lista *l1, Lista *l2);

void menu(Lista **ll);



int main(){

    // Lista *lista1 = cria_lista();
    // puts("\n============ LISTA 01 ==============");
    // menu(&lista1);
    
    // Lista *lista2 = cria_lista();
    // puts("\n============ LISTA 02 ==============");
    // menu(&lista2);

    // Lista *lista3 = concatena(lista1, lista2);
    // puts("\n============ LISTA 03 ==============");
    // menu(&lista3);

    Lista *lista1 = cria_lista();
    menu(&lista1);
    
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

// exercício 2.1
int comprimento(Lista *l){
    int nos = 0;
    for(Lista *aux = l; aux; aux=aux->prox)
        nos++;
    return nos;
}

// exercício 2.2
int maiores(Lista *l, int n){
    int maiores = 0;
    for(Lista *aux = l; aux; aux=aux->prox){
        if(aux->valor > n)
            maiores++;
    }

    return maiores;
}

// exercício 2.3
Lista *ultimo(Lista *l){
    Lista *aux = l;
    for(; aux->prox; aux=aux->prox);
    return aux;
}

Lista *concatena(Lista *l1, Lista *l2){
    Lista *aux = l1;
    for(; aux->prox; aux=aux->prox);

    aux->prox = l2;
    l2 = NULL;

    return l1;
}






















void menu(Lista **ll){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar a lista");
    puts("2: inserir elemento no inicio da lista");
    puts("3: inserir elemento no fim da lista");
    puts("4: remover elemento no inicio da lista");
    puts("5: remover elemento no fim da lista");
    puts("6: limpar a lista");
    puts("-------------- EXERCICIOS -------------");
    // puts("7: comprimento da lista");
    // puts("7: quantidade de elementos maiores do que n");
    // puts("7: ultimo elemento da lista");

    
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
        
        // case 7: printf("\n%d elementos\n", comprimento(*ll));
        //         break;

        // case 7: puts("\nDigite um valor inteiro");
        //         scanf("%d", &n);
        //         printf("\nExiste %d elementos maiores do que %d\n\n", maiores(*ll, n), n);
        //         break;

        // case 7: 
        //         if(!(*ll)){
        //             puts("\nlista vazia!\n");
        //             break;
        //         }
        //         printf("\nUltimo elemento:\n%d\n\n", (ultimo(*ll))->valor);
        //         break;

        case -1: return;

        default: puts("Valor invalido!\n");
                break;
        }

    menu(ll);
}
