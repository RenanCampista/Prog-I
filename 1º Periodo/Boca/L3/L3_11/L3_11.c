#include <stdio.h>

int EhPar (int x) {
    if (x % 2 == 0) {
        return 1;
    } else return 0;
}

void PrintaPares (int N) {
    printf("%d ", N);
}

void PrintaImpares (int N) {
    printf("%d ", N);
}

int main() {
    int tipo = 0, n = 0, i = 0;

    scanf("%d %d", &tipo, &n);

    for(i = 1; i <= n * 2; i++) {
        if (tipo == 0) {
            if (EhPar(i) == 1) {
                PrintaPares(i);
            }
        }
        else if (tipo == 1) {
            if (EhPar(i) == 0) {
                PrintaImpares(i);
            }
        }
    }
    return 0;
}