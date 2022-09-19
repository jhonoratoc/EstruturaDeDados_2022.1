#include <stdio.h>
#include <stdlib.h>

#define N 6

struct lista{
    int cti, ctf;
    int vetor[N];
};


int menu(struct lista *l);
void cria_lista(struct lista *);

int esta_cheia(struct lista *);
int esta_vazia(struct lista *);

void insere_fim(struct lista *);
void insere_inicio(struct lista *);

void limpa_lista(struct lista *);
void mostra_lista(struct lista *);

void remove_fim(struct lista *);
void remove_inicio(struct lista *);



int main(){

    struct lista l1;
    cria_lista(&l1);
    menu(&l1);

    return 0;
}



int menu(struct lista *l){
    puts("\nDigite o que deseja fazer:");
    puts("1: mostrar lista");
    puts("2: inserir elemento na lista");
    puts("3: remover elemento na lista");
    puts("4: limpar a lista");
    puts("0: encerrar");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: mostra_lista(l);
            break;
        case 2: 
            puts("1: inserir no inicio");
            puts("2: inserir no fim");
            scanf("%d", &escolha);

            switch (escolha){
                case 1: insere_inicio(l);
                    break;
                case 2: insere_fim(l);
                    break;
                default:{
                    puts("Codigo invalido!");
                    break;}
            }

            break;
        case 3:
            puts("1: remover no inicio");
            puts("2: remover no fim");
            scanf("%d", &escolha);

            switch (escolha){
                case 1: remove_inicio(l);
                    break;
                case 2: remove_fim(l);
                    break;
                default:{
                    puts("Codigo invalido!");
                    break;}
            }

            break;
        case 4: limpa_lista(l);
            break;
        case 0:
            return 0;
        default:
            puts("Codigo invalido!");
            break;
    }

    menu(l);
    
}

void cria_lista(struct lista *l){
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





void insere_fim(struct lista *l){
    if (esta_cheia(l))
        puts("Lista cheia!");

    else{ 
        int novo;
        puts("Digite o valor a ser inserido no fim da lista: ");
        scanf("%d", &novo);

        if (l->ctf == N-1)
            l->ctf = 0;
        else if (esta_vazia(l)){
            l->cti = 0;
            l->ctf = 0;
        }else 
            (l->ctf)++;

        l->vetor[l->ctf] == novo;
    }
}

void insere_inicio(struct lista *l){
    if (esta_cheia(l))
        puts("Lista cheia!");

    else{
        int novo;
        puts("Digite o valor a ser inserido no inicio da lista: ");
        scanf("%d", &novo);

        if (l->cti == 0)
            l->cti == N-1;
        else if (esta_vazia(l)){
            l->cti = 0;
            l->ctf = 0;
        }else
            (l->cti)--;

        l->vetor[l->cti] = novo;
    }
}





void limpa_lista(struct lista *l){
    l->cti=-1;
    l->ctf=-1;
}

void mostra_lista(struct lista *l){
    int i = l->cti;
    for (; i != l->ctf;){
        printf(" %d", l->vetor[i]);
        if (i == N-1)
            i = 0;
        else
            i++;
    }
    printf(" %d", l->vetor[l->ctf]);
}








void remove_fim(struct lista *l){

}

void remove_inicio(struct lista *l){

}