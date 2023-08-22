#include <stdio.h>

void verificaPA(int tam, int vet[tam]) {
    int i = 0, razao = 0, aux = 0;
    
    if (tam == 1) {
        printf("NAO");
    } else if (tam == 2) {
        razao = vet[1] - vet[0];
        printf("RESP:%d", razao);
    } else {
        razao = vet[1] - vet[0];
        for (i = 1; i < tam; i++) {
            if (vet[i] - vet[i - 1] == razao) {
                aux++;
            }
        }
        if (aux + 1 == tam) {
            printf("RESP:%d", razao);
        } else {
            printf("NAO");
        }
    }
}

int main() {
    int tam = 0, i = 0;

    scanf("%d", &tam);
    int vet[tam];

    for (i = 0; i < tam; i++) {
        scanf(" %d", &vet[i]);
    }

    verificaPA(tam, vet);

    return 0;
}