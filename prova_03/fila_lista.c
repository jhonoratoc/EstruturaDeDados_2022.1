#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *prox;
} Lista;

typedef struct fila {
    Lista *inicio;
    Lista *fim;
} Fila;


void cria_fila(Fila *f);
void insere_fim(Fila **ff, int n);
void limpa_fila(Fila **ff);
void mostra_fila(Lista *l);
void remove_inicio(Fila **ff);
void menu(Fila **ff);



int main(){
    Fila *fila;
    cria_fila(fila);

    menu(&fila);

    return 0;
}


void cria_fila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void insere_fim(Fila **ff, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return;

    novo->valor = n;

    if(!((*ff)->fim)){              // se a fila estiver vazia
        novo->prox = NULL;
        (*ff)->inicio = novo;
        (*ff)->fim = novo;
        return;
    }

    (*ff)->fim->prox = novo;        // qualquer outro caso
    (*ff)->fim = novo;
}

void remove_inicio(Fila **ff){
    if(!((*ff)->inicio)){
        puts("\nfila vazia!\n\n");
        return;
    }
    
    Lista *aux = (*ff)->inicio;

    if(((*ff)->fim) == ((*ff)->inicio))
        (*ff)->fim = NULL;

    (*ff)->inicio = aux->prox;
    free(aux);
}

void limpa_fila(Fila **ff){
    if(((*ff)->inicio)){
        remove_inicio(ff);
        limpa_fila(ff);
    }

    puts("\n\nlista limpa!\n");
}

void menu(Fila **ff){

    int op, n;

    do{
        puts("Digite um valor:");
        puts("1 - mostra");
        puts("2 - inserir");
        puts("3 - remover");
        puts("4 - limpar");
        puts("5 - sair");
        scanf("%d", &op);

        switch(op){
            case 1:
                if(!(*(ff))->inicio){
                    puts("\nfila vazia!\n");
                    break;
                }
                puts("FILA:");
                mostra_fila((*(ff))->inicio);
                puts("");
                break;
            case 2:
                puts("digite o valor a ser inserido: ");
                scanf("%d", &n);
                insere_fim(ff, n);
                break;
            case 3:
                remove_inicio(ff);
                break;
            case 4:
                limpa_fila(ff);
                break;
            case 5:
                puts("\n\nsaindo...\n\n");
                break;
            default:
                puts("\n\nopcao invalida!\n\n");
                break;
        }
    } while(op != 4);
}

void mostra_fila(Lista *l){
    if(l){
        printf("%d ", l->valor);
        mostra_fila(l->prox);
    }
}