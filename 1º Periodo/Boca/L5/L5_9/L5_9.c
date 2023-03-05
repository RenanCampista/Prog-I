#include <stdio.h>

void InverteVetor (int tam, int vet[tam]) {
    int i = 0;

    printf("{");
    for (i = tam - 1; i >= 0; i--) {
        printf("%d", vet[i]);
        if (i > 0 ) {
            printf(", ");
        }
    }
    printf("}");
}

int main() {
    int tam = 0, i = 0;

    scanf("%d", &tam);
    int vet[tam];

    for(i = 0; i < tam; i++) {
        scanf(" %d", &vet[i]);
    }

    InverteVetor(tam, vet);
    return 0;
}