#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    int valor;
    struct arv *dir;
    struct arv *esq;
} Arv;


int altura_arv(Arv *a);
Arv *balanceamento(Arv *a);
int esta_na_arvore(Arv *a, int n);
void imprime_arv_infix(Arv *a);
void imprime_arv_prefix(Arv *a);
void imprime_arv_posfix(Arv *a);
Arv *insere_arv(Arv *a, int n);
void menu(Arv *a);
Arv *limpa_arv(Arv *a);
int nivel_no(Arv *a, int n);
Arv *remove_arv(Arv *a, int n);

Arv *rotacao_dir(Arv *a);
Arv *rotacao_esq(Arv *a);




int main(){
    Arv *raiz = 0;      // criando árvore vazia

    menu(raiz);

    return 0;


}


void imprime_arv_infix(Arv *a){
    printf("<");
    if(a){
        imprime_arv_infix(a->esq);
        printf("%d ", a->valor);
        imprime_arv_infix(a->dir);
    }
    printf(">");
}

void imprime_arv_prefix(Arv *a){
    printf("<");
    if(a){
        printf("%d ", a->valor);
        imprime_arv_prefix(a->esq);
        imprime_arv_prefix(a->dir);
    }
    printf(">");

}

void imprime_arv_posfix(Arv *a){
    printf("<");
    if(a){
        imprime_arv_posfix(a->esq);
        imprime_arv_posfix(a->dir);
        printf("%d ", a->valor);
    }
    printf(">");
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



int altura_arv(Arv *a){
    if (!a)
        return 0;
    
    int hesq = altura_arv(a->esq);
    int hdir = altura_arv(a->dir);

    if(hesq > hdir)
        return 1 + hesq;
    else
        return 1 + hdir;
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



Arv *rotacao_dir(Arv *a){
    Arv *no = a->esq;
    a->esq = no->dir;
    no->dir = a;
    a = no;

    return a;
}

Arv *rotacao_esq(Arv *a){
    Arv *no = a->dir;
    a->dir = no->esq;
    no->esq = a;
    a = no;

    return a;
}

Arv *balanceamento(Arv *a){

    int fator_balanceamento = altura_arv(a->esq) - altura_arv(a->dir);

    if(fator_balanceamento == -2){
        fator_balanceamento = altura_arv(a->dir->esq) - altura_arv(a->dir->dir);
        if(fator_balanceamento == 1)
            a->dir = rotacao_dir(a->dir);
        a = rotacao_esq(a);
    }

    else if (fator_balanceamento == 2){
        fator_balanceamento = altura_arv(a->esq->esq) - altura_arv(a->esq->dir);
        if(fator_balanceamento == -1)
            a->esq = rotacao_esq(a->esq);
        a = rotacao_dir(a);
    }

    return a;
}



Arv *insere_arv(Arv *a, int n){ 
    if(!a){
        Arv *novo = (Arv *) malloc(sizeof(Arv));
        if (!novo) return;
        novo->valor = n;
        novo->dir = novo->esq = NULL;
        a = novo;
    }

    else if(a->valor > n)
        a->esq = insere_arv(a->esq, n);

    else
        a->dir = insere_arv(a->dir, n);

    return balanceamento(a);

}

Arv *remove_arv(Arv *a, int n){
    if(a){
        if(a->valor > n)
            a->esq = remove_arv(a->esq, n);
        else if(a->valor < n)
            a->dir = remove_arv(a->dir, n);
        
        else{
            if(!(a->dir) && !(a->esq)){
                free(a);
                a = NULL;
            }

            else if(!(a->dir)){
                Arv *temp = a;
                a = a->esq;
                free(a);
            }

            else if(!(a->esq)){
                Arv *temp = a;
                a = a->dir;
                free(a);
            }

            else{
                Arv *temp = a->esq;
                while(temp->dir)
                    temp = temp->dir;

                a->valor = temp->valor;
                temp->valor = n;

                a->esq = remove_arv(a->esq, n);

            }
        }
    } else return NULL;

    return balanceamento(a);
}


void menu(Arv *a){
    int opcao, valor;

    do{
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Limpar\n");
        printf("5 - Altura\n");
        printf("6 - Esta na arvore\n");
        printf("7 - Nivel do no\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                a = insere_arv(a, valor);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                a = remove_arv(a, valor);
                break;
            case 3:
                printf("\nprefix: \n");
                imprime_arv_prefix(a);
                printf("\ninfix: \n");
                imprime_arv_infix(a);
                printf("\nposfix: \n");
                imprime_arv_posfix(a);
                printf("\n");
                break;
            case 4:
                a = limpa_arv(a);
                break;
            case 5:
                printf("Altura: %d\n", altura_arv(a));
                break;
            case 6:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                if(esta_na_arvore(a, valor))
                    printf("Esta na arvore\n");
                else
                    printf("Nao esta na arvore\n");
                break;
            case 7:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                if(nivel_no(a, valor) == -1)
                    printf("\nNao esta na arvore\n");
                else
                    printf("\nNivel: %d\n", nivel_no(a, valor));
                break;
            case 0:
                puts("Saindo...");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(opcao != 0);
}