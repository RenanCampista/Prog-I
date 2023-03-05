#include <stdio.h>

int main() {
    int num[12], tam = 0, i = 0, cont = 0, n = 0;
    char texto;

    scanf("%d ", &tam);

    for (i = 1; i <= tam; i++) {
        scanf("%d ", &num[i]);
    }

    do {
        scanf("%c", &texto);
        if (texto == '"') {
            cont++;
        }
        else if (texto == '%') {
            scanf("%d", &n);
            if (n < 1 || n > tam) {
                printf("ERRO");
            } else {
                printf("%d", num[n]);
            }
        }
        else if (texto != '"') {
            printf("%c", texto);
        }
    } while (cont < 2);
    
    return 0;
}