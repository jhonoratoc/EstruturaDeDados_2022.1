#include <stdio.h>
#include <stdlib.h>

void minusculo(char* str);

int main(){
    char palavra[] = "testANdo sE FUNCIOna";

    minusculo(palavra);
    printf("%s\n", palavra);

    return 0;
}

void minusculo(char* str){
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]>='A' && str[i]<='Z'){
            //putchar(str[i]);
            str[i]+=32;
        }
    }
}