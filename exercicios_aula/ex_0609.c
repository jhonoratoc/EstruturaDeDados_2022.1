/*
Guardar dez nomes simples em um vetor de ponteiros alocado dinamicamente

Regras:
alocar tudo dinamicamente
usar uma função para guardar os nomes
usar uma função para mostrar os nomes
lembrar de liberar a memória
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int guarda_nome(int, char**);
void mostra_nome(char **pont);


int main(){

    // declaração do ponteiro de ponteiro de char
    char **p;
    // p apontará para um array de ponteiros de char
    // cada elemento do array de ponteiros apontará para um array de char
     

    // malloc de p (que é um char**)
    p = (char**)malloc(10*sizeof(char*));

    // verificando a alocação
    if (!p)
        return 0;

    // liberando a memória 
    for (int i=0; i<10; i++){
        if (guarda_nome(i,p) == 0){         // aplicando a função guarda_nome
            for (int j=0; j<i; j++)
                free(p[j]);                 // liberando a memória
            free(p);
            return 0;
        }
    }

    mostra_nome(p);

    for(int i=0; i<10; i++)
        free(p[i]);

    free(p);

    return 0;
}



int guarda_nome(int indice, char **pont){
    char nome[50];
    int tamanho;

    printf("Digite o nome %d: ", (indice+1));
    scanf("%s", &nome);

    tamanho = strlen(nome);
    pont[indice] = (char*)malloc((tamanho+1)*sizeof(char));

    if (!pont[indice])
        return 0;
    else {
    strcpy(pont[indice], nome);
    return 1;
    }
}

void mostra_nome(char **pont){
    puts("");
    for (int i=0; i<10; i++)
        printf("%do nome: %s\n", i+1, pont[i]);
}