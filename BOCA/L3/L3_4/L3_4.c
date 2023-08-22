#include <stdio.h>
#define TRUE 1;
#define FALSE 0;

int primo(int num) {
    int i = 0, contPrimo = 0;
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            contPrimo++;
        }
    }
    if (contPrimo == 2) {
        return TRUE;
    } else {
        return FALSE;
    }
}
void ImprimeMultiplos(int num, int max) {
    // max será o interv superior
    // num o primo
    int i = 0, cont = 0;
    for (i = num + 1; i < max; i++) {
        if (i % num == 0) {
            printf("%d ", i);
            cont++;
        }
    }
    if (cont == 0) {
        printf("*");
    }
    printf("\n");
}

int main() {
    int n = 0, m = 0, i = 0;
    scanf("%d %d", &n, &m);
    if (n < m) {
        for(i = n + 1; i < m; i++) {
            if (primo(i) == 1) {
                printf("%d\n", i);
                ImprimeMultiplos(i, m);
            }
        }
    }
    return 0;
}