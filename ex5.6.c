#include <stdio.h>
#include <stdlib.h>

void roda_string(char *str);

int main(){
    char nome[] = "caso";

    roda_string(nome);
    puts(nome);

    return 0;
}

void roda_string(char *str){
    char temp=str[0], temp2;
    for (int i=1; str[i]!='\0'; i++){
        temp2=str[i];
        str[i]=temp;
        temp=temp2;
    }
    str[0]=temp;
}