#include <stdio.h>

#define N 11

struct lista
{
    int n;
    int v[N];
}l;


int main(){

    struct lista l = {9, {3,5,8,9,15,17,21,34,60,99}};

    int i=0;

    for ( ; (l.v[i] < 18) && (i <= l.n); i++){
        continue;
    }

    for (int j=l.n; j>= i; j--){
        l.v[j+1] = l.v[j];
    }

    l.v[i] = 18;
    l.n++;

    return 0;

}

