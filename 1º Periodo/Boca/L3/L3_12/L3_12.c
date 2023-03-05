#include <stdio.h>

int somadosdigitos (int n) {
    int soma = 0;
    while (n > 0) {
        soma = soma + (n % 10);
        n = n / 10;
    }
    return soma; 
}

void parImpar (int n) {
    if (n % 2 == 0) {
        printf("Par ");
    }else if (n % 2 != 0){
        printf("Impar ");
    }
}

void valorPrimo (int n) {
    int i = 0, primo = 0;

    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            primo++;
        }
    }
    if (primo == 2) {
        printf("Primo\n");
    } else {
        printf("Nao e primo\n");
    } 
}

int main() {
    int num = 0;

    scanf("%d", &num);

    if (num > 0) {
        do {
            printf("%d ", somadosdigitos(num));
            parImpar(somadosdigitos(num));
            valorPrimo(somadosdigitos(num));
            num = somadosdigitos(num);
        } while (num / 10 != 0);        
    }
    return 0;
}