#include <stdio.h>

typedef struct pontos {
    int x, y;
} tPonto;

int identQuadrante (tPonto ponto) {
    if (ponto.x > 0 && ponto.y > 0) {
        return 1;
    } else if (ponto.x < 0 && ponto.y > 0) {
        return 2;
    } else if (ponto.x < 0 && ponto.y < 0) {
        return 3;
    } else if (ponto.x > 0 && ponto.y < 0) {
        return 4;
    } else return 0;
}

tPonto simetrico (tPonto ponto) {
    ponto.x = (-1) * ponto.x;
    ponto.y = (-1) * ponto.y;
    return ponto;
}

int main() {
    int quant_pontos = 0, i = 1;
    tPonto ponto, simetric;

    scanf("%d", &quant_pontos);

    while (i <= quant_pontos) {
        scanf("%d %d", &ponto.x, &ponto.y);

        simetric = simetrico(ponto);
        printf("(%d,%d) %d (%d,%d) %d\n", ponto.x, ponto.y, identQuadrante(ponto), simetric.x, simetric.y, identQuadrante(simetric));
        i++;
    }
    return 0;
}