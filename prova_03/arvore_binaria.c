#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    int valor;
    struct arv *esq;
    struct arv *dir;
} Arv;



int altura_arv(Arv *a);
int esta_na_arvore(Arv *a, int n);
void imprime_arv_infix(Arv *a);
void imprime_arv_prefix(Arv *a);
void imprime_arv_posfix(Arv *a);
Arv *insere_arv(Arv *a, int n);
void menu(Arv *a);
int nivel_no(Arv *a, int n);
Arv *limpa_arv(Arv *a);
Arv *remove_arv(Arv *a, int n);



int main(){
    Arv *raiz = 0;      // criando árvore vazia

    menu(raiz);

    return 0;

}

void imprime_arv_infix(Arv *a){       // versão infix (ordenado): sae, raiz, sad
    printf("<");
    if(a){
        imprime_arv_infix(a->esq);
        printf("%d ", a->valor);
        imprime_arv_infix(a->dir);
    }
    printf(">");
}

void imprime_arv_prefix(Arv *a){       // versão prefix: raiz, sae, sad
    printf("<");
    if(a){
        printf("%d ", a->valor);
        imprime_arv_prefix(a->esq);
        imprime_arv_prefix(a->dir);
    }
    printf(">");
}

void imprime_arv_posfix(Arv *a){       // versão posfix: sae, sad, raiz
    printf("<");
    if(a){
        imprime_arv_posfix(a->esq);
        imprime_arv_posfix(a->dir);
        printf("%d ", a->valor);
    }
    printf(">");
}


int altura_arv(Arv *a){
    if(!a)
        return 0;

    int aesq = altura_arv(a->esq);
    int adir = altura_arv(a->dir);
    
    if(aesq < adir)
        return 1 + aesq;
    else 
        return 1 + adir;
}

int esta_na_arvore(Arv *a, int n){
    if(a){
        if(a->valor > n)
            return esta_na_arvore(a->esq, n);
        else if(a->valor < n)
            return esta_na_arvore(a->dir, n);
        else
            return 1;
    }
    return 0;
}

int nivel_no(Arv *a, int n){
    if(a){
        if(a->valor > n)
            return nivel_no(a->esq, n) + 1;
        else if(a->valor < n)
            return nivel_no(a->dir, n) + 1;
        else
            return 0;
    }
    return -1;
}






Arv *insere_arv(Arv *a, int n){
    if(!a){
        a = (Arv *) malloc(sizeof(Arv));
        if (!a) return;
        a->valor = n;
        a->esq = a->dir = NULL;
    }

    else if (n < a->valor)
        a->esq = insere_arv(a->esq, n);
    else
        a->dir = insere_arv(a->dir, n);
    
    return a;
}

Arv *remove_arv(Arv *a, int n){

    // procurando o nó de valor n

    if(!a)
        return NULL;

    else if (a->valor > n)
        a->esq = remove_arv(a->esq, n);

    else if (a->valor < n)
        a->dir = remove_arv(a->dir, n);

    else{    // achou o nó a ser removido

        if (!(a->esq) && !(a->dir)){        // se o nó não tem filhos
            free(a);
            a = NULL;
        }

        else if (!(a->esq)){                // se o nó só tem filho à direita
            Arv *temp = a;
            a = a->dir;
            free(temp);
        }

        else if (!(a->dir)){                // se o nó só tem filho à esquerda
            Arv *temp = a;
            a = a->esq;
            free(temp);
        }

        else{                               // se o nó tem dois filhos
            Arv *temp = a->esq;             // temp aponta para o filho mais à direita da subárvore esquerda
            while (temp->dir)
                temp = temp->dir;   
            a->valor = temp->valor;                 // temp e a trocam de valores
            temp->valor = n;
            a->esq = remove_arv(a->esq, n);         // remove o nó que foi trocado de lugar
        }
    }
    return a;
}

Arv *limpa_arv(Arv *a){
    if(a){
        a->esq = limpa_arv(a->esq);
        a->dir = limpa_arv(a->dir);
        free(a);
        return 0;
    }
    return 0;
}




void menu(Arv *a){
    int opcao, n;
    do{
        puts("\n------- ARVORE BINARIA -------");
        puts("1: Inserir");
        puts("2: Remover");
        puts("3: Imprimir");
        puts("4: Limpar");
        puts("0: Sair");

        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            puts("Digite o valor a ser inserido: ");
            scanf("%d", &n);
            a = insere_arv(a, n);
            break;
        
        case 2:
            puts("Digite o valor a ser removido: ");
            scanf("%d", &n);
            a = remove_arv(a, n);
            break;

        case 3:
            puts("\nInfix: ");
            imprime_arv_infix(a);
            puts("\nPrefix: ");
            imprime_arv_prefix(a);
            puts("\nPosfix: ");
            imprime_arv_posfix(a);
            puts("");
            break;

        case 4:
            a = limpa_arv(a);
            break;

        case 0:
            puts("Saindo...");
            break;

        default:
            puts("Opção inválida!");
            break;
        }

    }while(opcao != 0);
}