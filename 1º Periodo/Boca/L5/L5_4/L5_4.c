#include <stdio.h>

void verificaIntervalo (int quant, int num[quant], int a, int b) {
    int i = 0, cont_dentro = 0, cont_fora = 0;

    for (i = 0; i < quant; i++) {
        if (num[i] >= a && num[i] <= b) {
            cont_dentro++;
        } else cont_fora++;
    }
    printf("%d %d", cont_dentro, cont_fora);
}

int main() {
    int quant = 0, i = 0, a = 0, b = 0;

    scanf("%d", &quant);
    int num[quant];

    for (i = 0; i < quant; i++) {
        scanf(" %d", &num[i]);
    }
    scanf(" %d %d", &a, &b);

    if (a < b) {
        verificaIntervalo(quant, num, a, b);
    }
    
    return 0;
}