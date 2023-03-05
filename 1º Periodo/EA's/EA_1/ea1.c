#include <stdio.h>

void OrdenaVetor (int vetor[], int cont) {
    int i = 0, j = 0, aux = 0;

    for (i = 0; i < cont - 1; i++) {
        aux  = vetor[i];
        for (j = i + 1; j < cont; j++) {
            if (vetor[i] > vetor[j]) {
                vetor[i] = vetor[j];
                vetor[j] = aux;
                aux = vetor[i];
            }
        }
    }
}

int main() {
    int num = 0, id = 0, copia = 0, i = 0, cont = 0;

    scanf("%d %d", &num, &id);
    copia = num;

    while (copia > 0) {
        cont++;
        copia = copia / 10;
    }


    if (id == 0 && cont == 1) {

    } else {
        int vetor[cont];

        while (num > 0) {
            vetor[i] = num % 10;
            i++;
            num = num / 10;
        }
        if (id > cont - 1) {
            OrdenaVetor(vetor, cont);
            for (i = 0; i < cont; i++) {
                printf("%d", vetor[i]);
                if (i < cont - 1) {
                    printf(", ");
                }
            }
        } else {
            vetor[cont - id - 1] = -1;
            OrdenaVetor(vetor, cont);

            for (i = 0; i < cont; i++) {
                if (vetor[i] != -1) {
                    printf("%d", vetor[i]);
                    if (i < cont - 1) {
                        printf(", ");
                    } 
                }
            }
        }

    }

    


    return 0;
}