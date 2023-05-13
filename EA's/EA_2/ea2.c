#include <stdio.h>

int potencia (int num) {
    return num * num;
}

int main() {
    int num = 0, aux = 0, dist = 0;

    scanf("%d", &num);

    while (1) {
        while (num > 0) {
            aux = num % 10;
            dist += potencia(aux);
            num = num / 10;
        }
        if (dist < 10) {
            if (dist == 1 || dist == 7) {
                printf("SIM");
                break;
            } else {
                printf("NAO");
                break;
            }
        }
        num = dist;
        dist = 0;
    }



    return 0;
}