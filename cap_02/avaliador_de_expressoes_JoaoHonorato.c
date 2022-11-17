/*
Aluno: João Antonio Honorato Carvalho
Matrícula: 20210026680
*/

#include <stdio.h>
#include <string.h>

#define N 21

typedef struct pilha{
    int valor;
    struct pilha *prox;
} Pilha;


void cria_pilha(Pilha** pp);
int mostra_topo(Pilha* pilha);
int pilha_vazia(Pilha* pilha);
void pop(Pilha** pp);
void push(Pilha** pp, float n);


int main(){
    char entrada[N];
    puts("Digite a expressao matematica, sem espacos: ");
    scanf("%s", entrada);

    Pilha* pilha;
    cria_pilha(&pilha);

    for(int i=0; entrada[i]!='\0'; i++){
        if (entrada[i] == '(' || entrada[i] == '[' || entrada[i] == '{'){
            push(&pilha, entrada[i]);

        }else if (entrada[i] == '}'){
            if(mostra_topo(pilha) == '{'){
                pop(&pilha);
            } else {
                puts("Algo de errado nao esta certo na sua expressao...");
                return;
            }

        }else if (entrada[i] == ')'){
            if(mostra_topo(pilha) == '('){
                pop(&pilha);
            } else {
                puts("Algo de errado nao esta certo na sua expressao...");
                return;
            }

        }else if (entrada[i] == ']'){
            if(mostra_topo(pilha) == '['){
                pop(&pilha);
            } else {
                puts("Algo de errado nao esta certo na sua expressao...");
                return;
            }
        }

    }

    if(pilha_vazia(pilha))
        puts("Tudo certo com a sua expressao!");

    else
        puts("Algo de errado nao esta certo na sua expressao..."); 
    
    return 0;
}



void cria_pilha(Pilha** pp){
    (*pp) = NULL;
}

int mostra_topo(Pilha* pilha){
    if (!pilha) return;
    return pilha->valor;
}

int pilha_vazia(Pilha* p){
    if(!p)
        return 1;
    return 0;
}

void pop(Pilha** pp){
    if (!(*pp)) return;

    Pilha* aux = (*pp);
    *pp = aux->prox;
    aux->prox = NULL;
    free(aux);
}

void push(Pilha** pp, float n){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if(!novo) return;

    novo->valor = n;
    novo->prox = (*pp);
    *pp = novo;
}