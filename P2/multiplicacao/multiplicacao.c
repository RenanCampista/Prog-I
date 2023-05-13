#include <stdio.h>
#include <stdlib.h>

void LeVetor (int vetor[], int linha) {
    int i = 0;

    for (i = 0; i < linha; i++) {
        scanf("%d ", &vetor[i]);
    }
}

void GeraMatriz (int linha, int coluna, int matriz[linha][coluna], int semente) {
    int i = 0, j = 0;
    
    srand(semente);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            matriz[i][j] = rand() % 101;
        }
    }
}

void MultiplicaMatriz (int linha, int coluna, int matriz[linha][coluna], int vetor[linha]) {
    int i = 0, j = 0, soma = 0;

    //int resultado[coluna];

    for (i = 0; i < coluna; i++) {
        for (j = 0; j < linha; j++) {
            soma = soma + (vetor[j] * matriz[j][i]);
        }
        printf("%d ", soma);
        soma = 0;
    }
}
int main () {
    int i = 0, j = 0, linha = 0, coluna = 0, semente = 0;

    scanf("%d %d %d", &linha, &coluna, &semente);
    int vetor[linha], matriz[linha][coluna];

    LeVetor(vetor, linha);
    GeraMatriz(linha, coluna, matriz, semente);
    MultiplicaMatriz(linha, coluna, matriz, vetor);

    return 0;
}