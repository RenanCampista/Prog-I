#include <stdio.h>

void OrdemCrescente (int tam, int vet[tam]) {
    int i = 0, j = 0, aux = 0;

    for (i = 0; i < tam; i++) {
        aux = vet[i];
        for (j = i; j < tam; j++) {
            if (aux > vet[j]) {
                vet[i] = vet[j];
                vet[j] = aux;
                aux = vet[i];
            }
        }
    }

    printf("{");
    for (i = 0; i < tam; i++) {
        printf("%d", vet[i]);
        if (i < tam - 1) {
            printf(", ");
        }
    }
    printf("}");
}

int main() {
    int tam = 0, i = 0;

    scanf("%d", &tam);
    int vet[tam];

    for (i = 0; i < tam; i++) {
        scanf(" %d", &vet[i]);
    }

    OrdemCrescente(tam, vet);
    return 0;
}