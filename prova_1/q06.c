
int main(){

    int p[10][10];

    int a, b;
    puts("Digite dois números, separados por espaço, para receber o produto entre eles");
    scanf("%d %d", &a, &b);

    printf("%d x %d = %d\n", a, b, p[a-1][b-1]);
    return 0;
}