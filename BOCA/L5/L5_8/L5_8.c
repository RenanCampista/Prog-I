#include <stdio.h>

void TrocaParImpar ( int tam, int vet[tam]) {
    int i = 0, aux = 0;

    if (tam == 0) {
        printf("{}");
    } else {
        for (i = 1; i <= tam; i++) {
            if (i % 2 != 0) {
                if (i + 1 <= tam) {
                    aux = vet[i];
                    vet[i] = vet[i + 1];
                    vet[i + 1] = aux;
                }
            }
        }
        printf("{");
        for (i = 1; i <= tam; i++) {
            printf("%d", vet[i]);
            if (i < tam) {
                printf(", ");
            }
        }
        printf("}");
    }
}

int main() {
    int tam = 0, i = 0;

    scanf("%d", &tam);
    int vet[tam];

    for (i = 1; i <= tam; i++) {
        scanf(" %d", &vet[i]);
    }

    TrocaParImpar(tam, vet);

    return 0;
}