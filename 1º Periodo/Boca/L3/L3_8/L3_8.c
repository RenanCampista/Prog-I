#include <stdio.h>

int verificaPrimo (int n) {
    int primo = 0, i = 0;

    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            primo++;
        }
    }
    if (primo == 2) {
        return 1;
    }else {
        return 0;
    }
}

int transformaPrimo (int n) {
    int i = 0, primo = 0;

    while (1) {
        n++;
        for (i = 1; i <= n; i++) {
            if (n % i == 0) {
                primo++;
            }
        }
        if (primo == 2) {
            return n;
            break;
        } else {
            primo = 0;
        }
    }
}

int verificaNegativo (int n) {
    if (n > 0){
        return 0;
    }else if (n < 0) {
        return 1;
    }
}

int main() {
    int i = 0, j = 0, l = 0, c = 0, matriz = 0;

    scanf("%d %d", &i, &j);

    if(i >= 1 && i <= 100 && j >= 1 && j <= 100) {
        for(l = 1; l <= i; l++){
            printf("\t");
            for(c = 1; c <= j; c++){
                scanf("%d", &matriz);
                if (matriz >= -32000 && matriz <= 32000) {
                    if (verificaPrimo(matriz) == 0) {
                        if (verificaNegativo(matriz) == 1) {
                            if ((-1) * transformaPrimo((-1) * matriz) >= -32000){
                                matriz = (-1) * transformaPrimo((-1) * matriz);
                            }
                        }else {
                            if (transformaPrimo(matriz) <= 32000){
                                matriz = transformaPrimo(matriz);
                            }
                        }
                    }
                }
            printf("%d ", matriz);
            }
        printf("\n");
        }
    }
    return 0;
}