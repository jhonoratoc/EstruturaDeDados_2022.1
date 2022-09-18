#include <stdio.h>
#include <stdlib.h>

char* minusculo(char* str);
char* shift_string(char* str);
char* string_oposta(char* str);
char* roda_string(char *str);


int main(){
    char string1[] = "testANdo sE FUNCIOna";
    char string2[] = "zzzz ZZZ";
    char string3[] = "AaBbCcMm - NnXxYyZz";
    char string4[] = "caso";

    puts(minusculo(string1));
    puts(shift_string(string2));
    puts(string_oposta(string3));
    puts(roda_string(string4));

    return 0;
}


char* minusculo(char* str){
    char* str_nova;
    str_nova = (char*)malloc(sizeof(str));

    int i = 0;
    for (; str[i]!='\0'; i++)
        if (str[i]>='A' && str[i]<='Z')
            str_nova[i] = str[i] + 32;
        else
            str_nova[i] = str[i];
    str_nova[i] = '\0';

    return str_nova;
}


char* shift_string(char* str){
    int i = 0;
    char* str_nova;
    str_nova = (char*)malloc(sizeof(str));

    for (; str[i]!='\0'; i++){

        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
            if (str[i] == 'Z' || str[i] == 'z'){
                str_nova[i] = str[i]-25;
            } else {
                str_nova[i] = str[i]+1;
            }
        }
        else str_nova[i] = str[i];
    }
    str_nova[i] = '\0';

    return str_nova;
}


char* string_oposta(char* str){
    int i = 0;
    char* str_nova;
    str_nova = (char*)malloc(sizeof(str));

    for (; str[i]!='\0'; i++){
        if (str[i] <= 'M' && str[i] >= 'A')
            str_nova[i] = 'Z' - (str[i] - 'A');

        else if (str[i] >= 'N' && str[i] <= 'Z')
            str_nova[i] = 'A' + ('Z' - str[i]);

        else if (str[i] <= 'm' && str[i] >= 'a')
            str_nova[i] = 'z' - (str[i] - 'a');

        else if (str[i] >= 'n' && str[i] <= 'z')
            str_nova[i] = 'a' + ('z' - str[i]);
        
        else str_nova[i] = str[i];
    }
    str_nova[i] = '\0';

    return str_nova;
}


char* roda_string(char *str){
    int i = 1;
    char* str_nova;
    str_nova = (char*)malloc(sizeof(str));

    char temp=str[0], temp2;
    for (; str[i]!='\0'; i++){
        temp2=str[i];
        str_nova[i]=temp;
        temp=temp2;
    }
    str_nova[0]=temp;
    str_nova[i]='\0';

    return str_nova;
}