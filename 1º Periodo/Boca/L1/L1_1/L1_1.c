#include <stdio.h>

int main(){
    int a, b;
    float soma;
    scanf("%d%d", &a, &b);
    soma = sqrt(a) + sqrt(b);
    printf("%.2f", soma);
    return 0;
}
