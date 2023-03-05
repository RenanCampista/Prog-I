#include <stdio.h>

void GeraMatriz (int linha, int coluna, int matriz[linha][coluna]) {
    int i = 0, j = 0;

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void CalculaAlagamento (int linha, int coluna, int matriz[linha][coluna], int horas) {
    int i = 0, j = 0, k = 0, seco = 0, alagado = 0;

    for (k = 1; k <= horas; k++) {
        for (i = 0; i < linha; i++) {
            for (j = 0; j < coluna; j++) {
                if (matriz[i][j] == k) {
                    if (i - 1 >= 0 && matriz[i-1][j] == 0) {
                        matriz[i-1][j] = k + 1;
                    }
                    if (j - 1 >= 0 && matriz[i][j-1] == 0) {
                        matriz[i][j-1] = k + 1;
                    }
                    if (i + 1 < linha && matriz[i+1][j] == 0) {
                        matriz[i+1][j] = k + 1;
                    }
                    if (j + 1 < coluna && matriz[i][j+1] == 0) {
                        matriz[i][j+1] = k + 1;
                    }
                }
            }
        }
    }

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            if (matriz[i][j] != 0) {
                alagado++;
            } else seco++;
        }
    }

    printf("%d %d", seco, alagado);
}


int main() {
    int horas = 0, linhas = 0, colunas = 0;

    scanf("%d", &horas);
    scanf("%d %d", &linhas, &colunas);
    int matriz[linhas][colunas];

    GeraMatriz(linhas, colunas, matriz);
    CalculaAlagamento(linhas, colunas, matriz, horas);

    return 0;
}