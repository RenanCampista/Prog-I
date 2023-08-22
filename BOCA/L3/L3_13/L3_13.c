#include <stdio.h>

int CalculaValorPalavra (int text) {
    if (text >= 97 && text <= 122) {
        return text - 96;
    } else if (text >= 65 && text <= 90) {
        return text - 38;
    }
}

int EhPrimo (int n) {
    int primo = 0, i = 0;

    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            primo++;
        }
    }
    if (primo == 2) {
        return 1;
    }else {
        return 0;
    }
}

int ProximoPrimo (int n) {
    int i = 0, primo = 0;

    while (1) {
        n++;
        for (i = 1; i <= n; i++) {
            if (n % i == 0) {
                primo++;
            }
        }
        if (primo == 2) {
            return n;
            break;
        } else {
            primo = 0;
        }
    }
}


int main() {
    int soma = 0;
    char palavra;

    do {
        while (scanf("%c", &palavra) == 1 && palavra!='\n') {
            soma = soma + CalculaValorPalavra(palavra);
        }

        if (soma == 0) {
            break;
        }
             
        if (EhPrimo(soma) == 1) {
            printf("E primo\n");
            soma = 0;
        } else {
            printf("Nao e primo %d\n", ProximoPrimo(soma));
            soma = 0;
        }
            
        
    } while (!feof(stdin));

    return 0;
}