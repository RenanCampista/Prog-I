#include <stdio.h>

int main() {
   int num[100], soma = 0, i = 0, qtd = 0, j = 0;
   char caracter;

    while (1) {
        scanf("%c", &caracter);
        if (caracter == ']') break;
        scanf("%d", &num[i]);
        i++;
    }
    scanf(", %d", &soma);
    qtd = i;

    printf("[");
    for (i = 0; i < qtd - 1; i++) {
        for (j = i + 1; j < qtd; j++) {
            if (num[i] + num[j] == soma) {
                printf("%d, %d", i, j);
            }
        }
    }
    printf("]");

    return 0;
}