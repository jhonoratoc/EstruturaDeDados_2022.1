#include <stdio.h>
#include <stdlib.h>


int main(){
    int **p;
    int q[10][10];  // letra b
    
    p = (int**) malloc(10*sizeof(int*));

    for (int i=0; i<10; i++){
        p[i] = (int*) malloc(10*sizeof(int));
        if (!p[i]){
            for (int j = 0; j < i; j++)
                free(p[j]);
            free(p);
            return 0;
        }
    }

    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            p[i][j] = (i+1)*(j+1);
        }
    }

    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    int i, j;

    puts("Digite dois valores entre 1 e 9: ");
    scanf("%d %d", &i, &j);
    printf("%d x %d = %d\n", i, j, p[i-1][j-1]);

    for (int i = 0; i<10; i++)
        free(p[j]);
    free(p);
    
    return 0;
}