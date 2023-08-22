#include <stdio.h>

void ordenacao (int tam1, int vet1[tam1], int tam2, int vet2[tam2]) {
    int i = 0, j = 0, k = 0, aux = 0, vet3[tam1+tam2], cont1 = 0, cont2 = 0;

    for (i = 0; i <= tam1; i++) {
        if (i < tam1) {
            vet3[i] = vet1[i];
            
        } else {
            for (j = 0; j < tam2; j++) {
                vet3[i] = vet2[j];
                i++;
            }
        }
    }

    for (i = 0; i < tam1 + tam2; i++) {
        aux = vet3[i];
        for (j = i; j < tam1 + tam2; j++) {
            if (aux > vet3[j]) {
                vet3[i] = vet3[j];
                vet3[j] = aux;
                aux = vet3[i];
            }
        }
    }

    for (i = 0; i < tam1 + tam2; i++) {

        for (j = 0; j < tam1; j++) {
            if (vet1[j] == vet3[i] && vet3[i] != vet3[i - 1]) {
                printf("A");
            }
        }

        for (k = 0; k < tam2; k++) {
            if (vet2[k] == vet3[i] && vet3[i] != vet3[i - 1]) {
                printf("B");
            }
        }
    }
}

int main() {
    int i = 0, tam1 = 0, tam2 = 0;

    scanf("%d", &tam1);
    int vet1[tam1];

    for (i = 0; i < tam1; i++) {
        scanf(" %d", &vet1[i]);
    }

    scanf("%d", &tam2);
    int vet2[tam2];
    
    for (i = 0; i < tam2; i++) {
        scanf(" %d", &vet2[i]);
    }

    ordenacao(tam1, vet1, tam2, vet2);
    return 0;
}