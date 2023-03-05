#include <stdio.h>
#include <math.h>

int main() {
    int a = 0, b = 0, n = 0, i = 0;
    float x = 0, distancia = 0, integral = 0, bMenor = 0, bMaior = 0;

    scanf("%d %d %d", &a, &b, &n);

    distancia = (b - a) / (float)(n);
    x = a;

    for (i = 0; i < n; i++) {
        bMenor = sin(x + 1) + sqrt(x + pow(x, 3));
        x += distancia;
        bMaior = sin(x + 1) + sqrt(x + pow(x, 3));
        integral += (((bMaior + bMenor) * distancia) / 2);
    }

    printf("%.2f", integral);

    return 0;
}