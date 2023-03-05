#include <stdio.h>

int main() {
    int lembrete = 0, digitos = 0, maior = 0, copia = 0;
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, aux = 0;

    scanf("%d %d", &lembrete, &digitos);
    copia = lembrete;

    d1 = lembrete % 10;
    lembrete = lembrete / 10;
    d2 = lembrete % 10;
    lembrete = lembrete / 10;
    d3 = lembrete % 10;
    lembrete = lembrete / 10;
    d4 = lembrete % 10;
    lembrete = lembrete / 10;
    d5 = lembrete % 10;

    //ORDENAR OS DIGITOS
    if (d5 > d1) {
        aux = d5;
        d5 = d1;
        d1 = aux;
    }
    if (d5 > d2) {
        aux = d5;
        d5 = d2;
        d2 = aux;
    }
    if (d5 > d3) {
        aux = d5;
        d5 = d3;
        d3 = aux;
    }
    if (d5 > d4) {
        aux = d5;
        d5 = d4;
        d4 = aux;
    }
    
    if (d4 > d1) {
        aux = d4;
        d4 = d1;
        d1 = aux;
    }
    if (d4 > d2) {
        aux = d4;
        d4 = d2;
        d2 = aux;
    }
    if (d4 > d3) {
        aux = d4;
        d4 = d3;
        d3 = aux;
    }

    if (d3 > d1) {
        aux = d3;
        d3 = d1;
        d1 = aux;
    }
    if (d3 > d2) {
        aux = d3;
        d3 = d2;
        d2 = aux;
    }

    if (d2 > d1) {
        aux = d2;
        d2 = d1;
        d1 = aux;
    }
    if (d3 > d2) {
        aux = d3;
        d3 = d2;
        d2 = aux;
    }
    if (d5 > d4) {
        aux = d4;
        d4 = d5;
        d5 = aux;
    }

    maior = (d1*10000) + (d2*1000) + (d3*100) + (d4*10) + d5;
    lembrete = maior - copia;

    if (digitos == 5) {
        printf("%d", lembrete);
    } else if (digitos == 4) {
        printf("%d", lembrete / 10);
    } else if (digitos == 3) {
        printf("%d", lembrete / 100);
    } else if (digitos == 2) {
        printf("%d", lembrete / 1000);
    }
    return 0;
}