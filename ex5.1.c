#include <stdio.h>
#include <stdlib.h>

int conta_vogais(char* str);

int main(){
    char nome[] = "aspas duplas e qualquer coisa";

    printf("%d\n", conta_vogais(nome));
    
    return 0;
}

int conta_vogais(char* str){
    char vogais[] = "aeiouAEIOU";
    int somaVogais=0;

    for (int i=0; str[i]!='\0'; i++)
        for (int j=0; vogais[j]!='\0'; j++)
            if(str[i] == vogais[j])
                somaVogais++;
    return somaVogais;
}