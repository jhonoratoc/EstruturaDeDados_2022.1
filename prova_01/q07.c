#include <stdio.h>

typedef struct{
    char rua[100];
    char bairro[50];
    int numero;
} Endereco;

typedef struct{
    char nome[50];
    char professor[50];
    float periodo;
    int codigo;
} Disciplina;

typedef struct{
    Disciplina disciplina;
    float nota_aluno;
    char situacao_aluno[50];
} SituacaoDisciplina;

typedef struct{
    char nome[50];
    int matricula, telefone;
    Endereco endereco;
    SituacaoDisciplina situacao[10];
} Aluno;


int main(){

    return 0;
}