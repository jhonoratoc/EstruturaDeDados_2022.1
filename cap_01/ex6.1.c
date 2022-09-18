#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Ponto;

int dentroRet(Ponto *v1, Ponto *v2, Ponto *p);

int main(){
    Ponto v1= {1,2};
    Ponto v2 = {8,8};
    Ponto p = {8,8};

    printf("%d\n", dentroRet(&v1, &v2, &p));

    return 0;
}

int dentroRet(Ponto *v1, Ponto *v2, Ponto *p){
    if((v1->x <= p->x) && (v1->y <= p->y) && (v2->x >= p->x) && (v2->y >= p->y))
        return 1;
    return 0;
}