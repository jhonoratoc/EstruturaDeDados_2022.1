#include <stdio.h>
#include <stdlib.h>

void shift_string(char* str);

int main(){
    char string[] = "zzzzZZZ";

    shift_string(string);
    printf("%s\n", string);

    return 0;
}

void shift_string(char* str){
    for (int i=0; str[i]!='\0'; i++){
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
            if (str[i] == 'Z' || str[i] == 'z'){
                str[i] -= 26;
            }
            str[i]++;
        }
    }
}