#include <stdio.h>
#include <math.h>

void verifcadist (int tam, int postes[tam]) {
    int i = 1, maior_dif = -32000, difer = 0;

    if (tam == 1) {
        printf("IMPOSSIVEL");
    } else {
        while (1) {
            if (i == tam) {
                break;
            }
            difer = fabs(postes[i] - postes[i - 1]);
            if (difer > maior_dif) {
                maior_dif = difer;
            }
            i++;
        }

        i = 1;

        while (1) {
            if (i == tam) {
                break;
            }
            if (fabs(postes[i] - postes[i - 1]) == maior_dif) {
                printf(" (%d %d)", i -1, i );
            }
            i++;
        }
    }
}

int main() {
    int tam = 0, i = 1;

    scanf(" %d", &tam);
    int postes[tam];

    for (i = 0; i < tam; i++) {
        scanf(" %d", &postes[i]);
    }

    verifcadist(tam, postes);

    return 0;
}