#include <stdio.h>
#include <math.h>

typedef struct ponto {
    int x, y;
} tPonto;

int CalculaDistanciaInicio(tPonto ponto, tPonto ponto1){
    return sqrt( pow((ponto.x - ponto1.x), 2) + pow((ponto.y - ponto1.y), 2)  );
}

int CalculaDistanciaFim(tPonto ponto, tPonto ponto2){
    return sqrt( pow((ponto.x - ponto2.x), 2) + pow((ponto.y - ponto2.y), 2)  );
}

void localizaponto(tPonto ponto, tPonto ponto1, tPonto ponto2) {
    if (CalculaDistanciaFim(ponto, ponto2) == CalculaDistanciaInicio(ponto, ponto1)) {
        printf("EQUIDISTANTE\n");
    } else if (CalculaDistanciaFim(ponto, ponto2) > CalculaDistanciaInicio(ponto, ponto1)) {
        printf("INICIO\n");
    } else {
        printf("FIM\n");
    }
}

int main () {
    tPonto ponto, ponto1, ponto2;
    int quant_ponto = 0, cont = 1;

    scanf("%d", &quant_ponto);

    while (cont <= quant_ponto) {
        scanf("%d %d %d %d %d %d", &ponto.x, &ponto.y, &ponto1.x, &ponto1.y, &ponto2.x, &ponto2.y);

        localizaponto(ponto, ponto1, ponto2);

        cont++;
    }
    return 0;
}