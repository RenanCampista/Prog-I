#include <stdio.h>

typedef struct ponto {
    int x, y;
} tPonto;

int quadrante (tPonto ponto) {
    if (ponto.x > 0 && ponto.y > 0) {
        return 1;
    } else if (ponto.x < 0 && ponto.y > 0) {
        return 2;
    } else if (ponto.x < 0 && ponto.y < 0) {
        return 3;
    } else if (ponto.x > 0 && ponto.y < 0) {
        return 4;
    } else if (ponto.x == 0 && ponto.y > 0) {
        return 5;
    } else if (ponto.x == 0 && ponto.y < 0) {
        return 6;
    } else if (ponto.x < 0 && ponto.y == 0) {
        return 7;
    } else if (ponto.x > 0 && ponto.y == 0) {
        return 8;
    } else {
        return 0;
    }
}

void idQuandrante(tPonto ponto1, tPonto ponto2) {
    if (quadrante(ponto1) == quadrante(ponto2)) {
        printf("MESMO\n");
    } else {
        printf("DIFERENTE\n");
    }
}

int main() {
    int quant_ponto = 0, cont = 1;
    tPonto ponto1, ponto2;

    scanf("%d", &quant_ponto);

    while (cont <= quant_ponto) {
        scanf("%d %d %d %d", &ponto1.x, &ponto1.y, &ponto2.x, &ponto2.y);
        
        idQuandrante(ponto1, ponto2);
        
        cont++;
    }
    return 0;
}
