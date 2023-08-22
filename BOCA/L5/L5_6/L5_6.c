#include <stdio.h>

void verificaVetores (int tam1, int vet1[tam1], int tam2, int vet2[tam2]) {
    int i = 0, j = 0, k = 0, cont = 0;

    //eliminar repeticoes
    for (i = 0; i < tam1; i ++) {
        for (j = i + 1; j < tam1; ) {
            if (vet1[j] == vet1[i]) {
                for (k = 0; k < tam1; k++) {
                    if (vet1[k] == vet1[k + 1]) {
                        tam1--;
                    } 
                }
            } else {
                j++;
            }

        }
    }

    for (i = 0; i < tam2; i ++) {
        for (j = i + 1; j < tam2;) {
            if (vet2[j] == vet2[i]) {
                for (k = 0; k < tam2; k++) {
                    if (vet2[k] == vet2[k + 1]) {
                        tam2--;
                    } 
                }
            } else {
                j++;
            }

        }
    }

    for (i = 0; i < tam1; i++) {
        for (j = 0; j < tam2; j++) {
            if (vet1[i] == vet2[j]) {
                cont++;
            }
        }
    }

    if (cont == 0) {
        printf("NENHUM");
    } else if (cont == tam1) {
        printf("TODOS");
    } else {
        printf("PARCIAL");
    }
    
}

int main() {
    int tam1 = 0, tam2 = 0, i = 0;

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

    verificaVetores(tam1, vet1, tam2, vet2);

    return 0;
}