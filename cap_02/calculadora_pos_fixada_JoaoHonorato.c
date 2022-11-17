/*
Aluno: João Antonio Honorato Carvalho
Matrícula: 20210026680
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 21

typedef struct pilha{
    float valor;
    struct pilha *prox;
} Pilha;

void cria_pilha(Pilha** pp);
void eh_numero(Pilha** pp, float n);
void eh_operador(Pilha** pp, char o);
void mostra_pilha(Pilha *p);
float mostra_topo(Pilha* pilha);
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
        if(entrada[i] >= '0' && entrada[i] <= '9'){
            eh_numero(&pilha, (float)entrada[i] - 48);
        } else if (entrada[i] == '*' || entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '/'){
            eh_operador(&pilha, entrada[i]);
        }
    }

    printf("Resposta: %.2f\n", mostra_topo(pilha));
    return;
}

void cria_pilha(Pilha** pp){
    (*pp) = NULL;
}

int pilha_vazia(Pilha* p){
    if(!p)
        return 1;
    return 0;
}

void push(Pilha** pp, float n){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if(!novo) return;

    novo->valor = n;
    novo->prox = (*pp);
    *pp = novo;
}

void pop(Pilha** pp){
    if (!(*pp)) return;

    Pilha* aux = (*pp);
    *pp = aux->prox;
    aux->prox = NULL;
    free(aux);
}

float mostra_topo(Pilha* pilha){
    if (!pilha) return;
    return pilha->valor;
}

void eh_numero(Pilha** pp, float n){
    push(pp, n);
}

void eh_operador(Pilha** pp, char operador){
    float n1, n2, result;
    if (pilha_vazia(*pp)){
        n1 = 0;
        n2 = 0;

    }else{
        n1 = mostra_topo(*pp);
        pop(pp);
        n2 = mostra_topo(*pp);
        pop(pp);
    }

    switch (operador)
    {
    case '+':
        result = n2+n1;
        break;
    case '-':
        result = n2-n1;
        break;
    case '/':
        result = n2/n1;
        break;
    case '*':
        result = n2*n1;
        break;
    default:
        break;
    }

    push(pp, result);
}

void mostra_pilha(Pilha *p){
    if(!p) return;

    printf("%d ", p->valor);
    mostra_pilha(p->prox);
}