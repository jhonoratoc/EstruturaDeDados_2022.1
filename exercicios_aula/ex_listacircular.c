#include <stdio.h>
#include <stdlib.h>

#define N 6

struct lista{
    int cti, ctf;
    int vetor[N];
};

void criar_lista(struct lista *);

int esta_cheia(struct lista *);
int esta_vazia(struct lista *);

void inserir_fim(struct lista *);
void inserir_inicio(struct lista *);

void limpar_lista(struct lista *);
void mostrar_lista(struct lista *); // mostra lixo

void remover_fim(struct lista *);
void remover_inicio(struct lista *);


int main(){

    struct lista l1;
    criar_lista(&l1);
    inserir_fim(&l1);
    inserir_fim(&l1);
    //inserir_inicio(&l1);
    mostrar_lista(&l1);
    limpar_lista(&l1);
    inserir_fim(&l1);
    inserir_fim(&l1);
    mostrar_lista(&l1);

    return 0;
}





void criar_lista(struct lista *l){
    l->cti=-1;
    l->ctf=-1;
}

int esta_cheia(struct lista *l){
    int cti_temp;
    if (l->cti == 0)
        cti_temp = N;
    else
        cti_temp = l->cti;

    if (cti_temp - 1 == l->ctf)
        return 1;
    return 0;
}

int esta_vazia(struct lista *l){
    if (l->cti == -1)
        return 1;
    return 0;
}





void inserir_fim(struct lista *l){
    if (esta_cheia(l) == 1)
        puts("Lista cheia!");

    else{ 
        int novo;
        puts("Digite o valor a ser inserido no fim da lista: ");
        scanf("%d", &novo);

        if (l->ctf == N-1)
            l->ctf = 0;
        else if (l->cti == -1){
            l->cti = 0;
            l->ctf = 0;
        }else 
            (l->ctf)++;

        l->vetor[l->ctf] == novo;
    }
}

void inserir_inicio(struct lista *l){
    if (esta_cheia(l) == 1)
        puts("Lista cheia!");

    else{
        int novo;
        puts("Digite o valor a ser inserido no inicio da lista: ");
        scanf("%d", &novo);

        if (l->cti == 0)
            l->cti == N-1;
        else if (l->cti == -1){
            l->cti = 0;
            l->ctf = 0;
        }else
            (l->cti)--;

        l->vetor[l->cti] = novo;
    }
}





void limpar_lista(struct lista *l){
    l->cti = l->ctf = -1;
}

void mostrar_lista(struct lista *l){
    int i = l->cti;
    while(i!=(l->ctf)+1){
        printf("%d ", l->vetor[i]);
        if (i == N-1)
            i = 0;
        else
            i++;
    }
}





void remover_fim(struct lista *l){

}

void remover_inicio(struct lista *l){

}