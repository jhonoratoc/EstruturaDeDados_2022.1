#include <stdio.h>

typedef struct {
  float x, y, z;
} Vetor;

float dot(Vetor *v1, Vetor *v2);

int main(){
  Vetor v1 = {1, 3, 2.2};
  Vetor v2 = {8, 0.4, 3.3};

  printf("produto interno = %.2f\n", dot(&v1, &v2));
  
  return 0;
}

float dot(Vetor *v1, Vetor *v2){
  return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}