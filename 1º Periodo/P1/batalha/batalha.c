#include <stdio.h>

int main() {
    int m = 0, n = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, pontuacaoJ1 = 0, pontuacaoJ2 = 0, tabuleiro = 0, i = 0, j = 0;

    scanf("%d %d", &m, &n);
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d ", &tabuleiro);
            if (i == x1 && j == y1) {
                pontuacaoJ1 += tabuleiro;
            }
            if (i == x2 && j == y2) {
                pontuacaoJ2 += tabuleiro;
            }
        }
    }

    if (pontuacaoJ1 > pontuacaoJ2) {
        printf("J1 %d", pontuacaoJ1);
    } else if (pontuacaoJ2 > pontuacaoJ1) {
        printf("J2 %d", pontuacaoJ2);
    } else {
        printf("EMPATE");
    }

    return 0;
}