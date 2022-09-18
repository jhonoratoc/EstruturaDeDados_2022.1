#include <stdio.h>

#define N 10

struct lista{
    int n;
    int vetor[N];
};


int menu(struct lista *);

void cria_lista(struct lista *); // OK

int esta_cheia(struct lista *); // OK
int esta_vazia(struct lista *); // OK

void insere_fim(struct lista *); // OK
void remove_fim(struct lista *); // OK

void limpa_lista(struct lista *); // OK
void mostra_lista(struct lista *); // OK



int main(){
    struct lista l1;

    cria_lista(&l1);
    menu(&l1);
    
    return 0;
}


int menu(struct lista *l){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar lista");
    puts("2: inserir elemento no fim da lista");
    puts("3: remover ultimo elemento da lista");
    puts("4: limpar a lista");
    puts("0: encerrar");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: mostra_lista(l);
                break;
        case 2: insere_fim(l);
                break;
        case 3: remove_fim(l);
                break;
        case 4: limpa_lista(l);
                break;
        case 0: return 0;
    }

    while (escolha != 0)
        menu(l);
    
    return 0;
}


void cria_lista(struct lista *l){
    l->n = -1;
}




int esta_cheia(struct lista *l){
    if (l->n == N-1)
        return 1;
    return 0;
}

int esta_vazia(struct lista *l){
    if (l->n == -1)
        return 1;
    return 0;
}




void insere_fim(struct lista *l){
    if (esta_cheia(l) == 0){
        int novo;
        puts("Digite o numero a ser inserido no final da lista: ");
        scanf("%d", &novo);
        l->vetor[++(l->n)] = novo;
    }
}

void remove_fim(struct lista *l){
    if (esta_vazia(l) == 0)
        l->n--;
}




void limpa_lista(struct lista *l){
    l->n = -1;
}

void mostra_lista(struct lista *l){
    for (int i=0; i<=l->n; i++){
        printf("%d ", l->vetor[i]);
    }
    printf("\n");
}

