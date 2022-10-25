#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int valor;
    struct pilha *prox;
} Pilha;



Pilha *cria_pilha();

void limpa_pilha(Pilha **pp);

void mostra_pilha(Pilha **pp);
void mostra_topo(Pilha **pp);

void pop(Pilha **pp);
void push(Pilha **pp, int n);

void menu(Pilha **pp);


int main(){
    Pilha *pilha = cria_pilha();
    menu(&pilha);

    return 0;
}



Pilha *cria_pilha(){
    return NULL;
}

void limpa_pilha(Pilha **pp);

void mostra_pilha(Pilha **pp);

void mostra_topo(Pilha **pp){
    if(!(*pp)){
        puts("\npilha vazia!\n");
        return;
    }

    printf("Topo da pilha:\n%d", (*pp)->valor);
}

void pop(Pilha **pp){
    if(!(*pp)){
        puts("\npilha vazia!\n");
        return;
    }

    Pilha *aux = *pp;
    *pp = aux->prox;
    aux->prox = NULL;
    free(aux);
    puts("\nremovido!\n");
}

void push(Pilha **pp, int n){
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
    if(!novo) return;

    novo->valor = n;
    novo->prox = *pp;
    *pp = novo;
    puts("\ninserido!\n");
}

void menu(Pilha **pp){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar o topo da pilha");
    puts("2: inserir elemento (push)");
    puts("3: remover elemento (pop)");
    puts("4: limpar a lista");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);
    int n;

    switch (escolha) {
        case 1: puts("\nTopo da pilha: ");
                mostra_topo(pp);
                break;

        case 2: puts("\nQue elemento deseja inserir? ");
                scanf("%d", &n);
                push(pp, n);
                break;

        case 3: pop(pp);
                break;

        case 4: limpa_pilha(pp);
                break;

        case -1: return;

        default: puts("Valor invalido!\n");
                break;
        }

    menu(pp);
}
