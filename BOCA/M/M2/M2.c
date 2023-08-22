#include <stdio.h>

int main(){
    float a;
    int b;
    scanf("%f", &a);
    b = a;
    printf("INTEIRO:%d,REAL:%.2f", b, a-b);
    return 0;
}