#include <stdio.h>
#include <stdlib.h>

int conta_char(char* str, char c);

int main(){
    char* string = "estrutura de dados";
    char letra = 'd';

    printf("a letra %c aparece %d vezes\n", letra, conta_char(string, letra));
    
    return 0;
}

int conta_char(char* str, char c){
    int contc = 0;

    for (int i=0; str[i]!='\0'; i++)
        if (str[i]==c)
            contc++;
    return contc;
}