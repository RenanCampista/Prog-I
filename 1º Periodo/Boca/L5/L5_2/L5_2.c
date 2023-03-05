#include <stdio.h>

void ordem (int pes, int notas[pes]) {
    int i = 0, cont_cresc = 0, cont_desc = 0, cont_igual = 0;
    if (pes == 1) {
        printf("CRESCENTE&DECRESCENTE");
    } else {
        for (i = 1; i <= pes ; i++) {
            if (i < pes) {
                if (notas[i + 1] > notas[i]) {
                    cont_cresc++;
                } if (notas[i + 1] < notas[i]) {
                    cont_desc++;
                } if (notas[i] == notas [i + 1]) {
                    cont_igual++;
                }
            } else if (i == pes ) {
                if (notas [i] > notas [i - 1]) {
                    cont_cresc++;
                }
                if (notas[i] < notas [i - 1]) {
                    cont_desc++;
                }
                if (notas[i] == notas [i-1]) {
                    cont_igual++;
                }
            }
        }

        if (cont_desc == pes) {
            printf("DECRESCENTE");
        } else if (cont_cresc == pes) {
            printf("CRESCENTE");
        } else if (cont_igual == pes) {
            printf("CRESCENTE&DECRESCENTE");
        } else if (cont_igual != 0 && cont_cresc != 0 && cont_desc == 0) {
            printf("CRESCENTE");
        } else if (cont_igual != 0 && cont_cresc == 0 && cont_desc != 0) {
            printf("DECRESCENTE");
        } else {
            printf("DESORDENADO");
        }
    }
}

int main() {
    int pes = 0, i = 0;

    scanf("%d", &pes);
    int notas[pes];

    for (i = 1; i <= pes; i++) {
        scanf(" %d", &notas[i]);
    }

    ordem(pes, notas);

    return 0;
}