#include <stdio.h>
#include <math.h>

typedef struct ponto {
    float x, y;
}tPonto;


int main() {
    tPonto ponto1, ponto2;
    int cont = 1, quant_ponto = 0;
    float dist = 0;

    scanf("%d", &quant_ponto);

    while (cont <= quant_ponto) {
        scanf("%f %f", &ponto1.x, &ponto1.y);

        if (cont > 1) {
            dist = sqrt(pow((ponto2.x - ponto1.x),2) + pow((ponto2.y - ponto1.y), 2));
            ponto2 = ponto1;
            printf("%.2f\n", dist);
        } else {
            ponto2 = ponto1;
            printf("-\n");
        }
        cont++;
    }
    return 0;
}