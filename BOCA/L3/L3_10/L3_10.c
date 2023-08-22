#include <stdio.h>

int EhLetra (unsigned char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
        return 1;
    } else return 0;
}

int EhLetraMaiuscula (unsigned char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else return 0;
}

int EhLetraMinuscula (unsigned char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else return 0;
}

unsigned char Codifica(unsigned char letra, int n) {
    if (EhLetraMaiuscula(letra) == 1) {
        letra = letra + (2 * n);
        if (letra > 'Z') {
            while (letra > 'Z') {
                letra = letra - 26;
            }
        }
        return letra;
    }
    else if (EhLetraMinuscula(letra) == 1) {
        letra = letra + n;
        if (letra > 'z') {
            while (letra > 'z') {
                letra = letra - 26;
            }
        }
        return letra;
    }
}

unsigned char Decodifica (unsigned char letra, int n) {
    if (EhLetraMaiuscula(letra) == 1) {
        letra = letra - (2 * n);
        if (letra < 'A') {
            while (letra < 'A') {
                letra = letra + 26;
            }
        }
        return letra;
    }
    else if (EhLetraMinuscula(letra) == 1) {
        letra = letra - n;
        if (letra < 'a') {
            while (letra < 'a') {
                letra = letra + 26;
            }
        }
        return letra;
    }

}

int main() {
    int modo = 0, chave = 0;
    char letra;

    scanf("%d %d ", &modo, &chave);
    
    while (chave >= 26) {
        chave = chave % 26;
    }

    do {
        scanf("%c", &letra);
        if (modo == 1) {
            if (EhLetra(letra) == 1) {
                letra = Codifica(letra, chave);
            }
            printf("%c", letra);
        } else if (modo == 2) {
            if (EhLetra(letra) == 1) {
                letra = Decodifica(letra, chave);
            }
            printf("%c", letra);
        } else {
            printf("Operacao invalida.");
            break;
        }
    } while (letra != '.');
    
    return 0;
}