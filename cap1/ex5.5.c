#include <stdio.h>
#include <stdlib.h>

void string_oposta(char* str);

int main(){

    char string[] = "AaBbCcMm - NnXxYyZz";
    string_oposta(string);
    puts(string);
    return 0;
}

/*
O alfabeto da tabela ASCII foi dividida em quatro partes: A-M, N-Z, a-m e n-z
As letras em A-M e a-m retornarão seu equivalente oposto, presente em N-Z e n-z, respectivamente
Para isso, seguirão as seguintes expressões:
    letra_nova(A-M) = 'Z' - letra_antiga + 'A'
    letra_nova(N-Z) = 'A' - letra_antiga + 'Z'
    letra_nova(a-m) = 'z' - letra_antiga + 'a'
    letra_nova(n-z) = 'z' - letra_antiga + 'a'

O contrário também vale, ou seja, as letras em N-Z e n-z retornarão seu equivalente oposto, presente em A-M e a-m


*/

void string_oposta(char* str){
    for (int i=0; str[i]!='\0'; i++){
        if (str[i] <= 'M' && str[i] >= 'A')
            str[i] = 'Z' - (str[i] - 'A');

        else if (str[i] >= 'N' && str[i] <= 'Z')
            str[i] = 'A' + ('Z' - str[i]);

        else if (str[i] <= 'm' && str[i] >= 'a')
            str[i] = 'z' - (str[i] - 'a');

        else if (str[i] >= 'n' && str[i] <= 'z')
            str[i] = 'a' + ('z' - str[i]);
    }
}