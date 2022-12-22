#include <stdio.h>

#define N 5

typedef struct lista{
    int cti, ctf;
    int vetor[N];
} Lista;


void cria_lista(Lista *l);
int esta_cheia(Lista *l);
int esta_vazia(Lista *l);
void inserir_fim(Lista *l, int n);
void inserir_inicio(Lista *l, int n);
void limpar_lista(Lista *l);
void mostrar_lista(Lista *l);
void remover_fim(Lista *l);
void remover_inicio(Lista *l);
void menu(Lista *l);

int main(){
    Lista l1;
    cria_lista(&l1);
    menu(&l1);
    return 0;
}


void cria_lista(Lista *l){
    l->ctf = -1;
    l->cti = -1;
}

int esta_cheia(Lista *l){
    if (((l->ctf)+1)%N == (l->cti)%N)
        return 1;
    return 0;
}

int esta_vazia(Lista *l){
    if(l->ctf == -1)
        return 1;
    return 0;
}

void inserir_fim(Lista *l, int n){
    if(esta_cheia(l)){
        printf("\nlista cheia!\n\n");
        return;
    }

    if(esta_vazia(l)){
        l->cti = l->ctf = 0;
        l->vetor[l->ctf] = n;
        return;
    }

    l->ctf = (l->ctf + 1)%N;
    l->vetor[l->ctf] = n;
}

void inserir_inicio(Lista *l, int n){
    if(esta_cheia(l)){
        printf("\nlista cheia!\n\n");
        return;
    }

    if(esta_vazia(l)){
        l->cti = l->ctf = 0;
        l->vetor[l->cti] = n;
        return;
    }

    l->cti = (l->cti + N - 1)%N;
    l->vetor[l->cti] = n;
}

void limpar_lista(Lista *l){
    l->cti = l->ctf = -1;
    printf("\nlista limpa!\n\n");
}

void mostrar_lista(Lista *l){
    if(esta_vazia(l))
        printf("\nlista vazia!\n\n");
    
    else{
        printf("\nLista:\n");
        for(int n = l->cti; n != l->ctf; n = (n+1)%N){
            printf("%d ", l->vetor[n]);
        }
        printf("%d\n\n", l->vetor[l->ctf]);
    }
}

void remover_fim(Lista *l){
    if(esta_vazia(l))
        printf("\nlista vazia!\n\n");

    else if ((l->ctf == l->cti) && (l->ctf != -1))
        limpar_lista(l);

    else{
        l->ctf = (l->ctf + N - 1)%N;
    }
}

void remover_inicio(Lista *l){
    if(esta_vazia(l))
        printf("\nlista vazia!\n\n");

    else if ((l->ctf == l->cti) && (l->ctf != -1))
        limpar_lista(l);

    else{
        l->cti = (l->cti + 1)%N;
    }
}


void menu(Lista *l){
    int escolha = 1;

    do{
        puts("Digite o que deseja fazer:");
        puts("1: mostrar lista");
        puts("2: inserir elemento no inicio");
        puts("3: inserir elemento no fim");
        puts("4: limpar a lista");
        puts("5: remover elemento no inicio");
        puts("6: remover elemento no fim");
        puts("-1: encerrar");

        int escolha, n;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: mostrar_lista(l);
                    break;
            case 2: 
                    puts("\nQue numero deseja inserir?");
                    scanf("%d", &n);
                    inserir_inicio(l, n);
                    break;
            case 3: 
                    puts("\nQue numero deseja inserir?");
                    scanf("%d", &n);
                    inserir_fim(l, n);
                    break;
            case 4: limpar_lista(l);
                    break;
            case 5: remover_inicio(l);
                    break;
            case 6: remover_fim(l);
                    break;
            case -1: 
                    return;
            default: puts("Valor invalido!");
                    break;
        } 
    } while (escolha);
}