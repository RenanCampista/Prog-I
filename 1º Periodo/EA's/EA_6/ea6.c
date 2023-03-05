#include <stdio.h>
#include <string.h>

int ItemA (char texto[]) {
    if (strlen(texto) >= 8 && strlen(texto) <= 20) {
        return 1;
    } else return 0;
}

int ItemB (char texto[]) {
    int cont = 0, tam = 0, i = 0;
    tam = strlen(texto);

    for (i = 0; i < tam; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            cont++;
        }
    }
    if (cont > 0) {
        return 1;
    } else return 0;
}

int ItemC (char texto[]) {
    int cont = 0, tam = 0, i = 0;
    tam = strlen(texto);

    for (i = 0; i < tam; i++) {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            cont++;
        }
    }
    if (cont > 0) {
        return 1;
    } else return 0;
}

int ItemD (char texto[]) {
    int cont = 0, tam = 0, i = 0;
    tam = strlen(texto);

    for (i = 0; i < tam; i++) {
        if (texto[i] >= '0' && texto[i] <= '9') {
            cont++;
        }
    }
    if (cont > 0) {
        return 1;
    } else return 0;
}

int ItemE (char texto[]) {
    int i = 0, tam = 0, cont = 0;
    tam = strlen(texto);

    for (i = 0; i < tam; i++) {
        //!@#$%&
        if (texto[i] == '!' || texto[i] == '@' || texto[i] == '#' || texto[i] == '$' || texto[i] == '%' || texto[i] == '&') {
            cont++;
        }
    }
    if (cont > 0) {
        return 1;
    } else return 0;
}

int main() {
    char s1[21], s2[21];
    int chave = 0;

    scanf("%21[^,], %21[^,], ", s1, s2);
    scanf("%d", &chave);

    if ( ItemA (s1) == 1) {
        if (ItemB (s1) == 1) {
            if (ItemC (s1) == 1) {
                if (ItemD (s1) == 1) {
                    if (ItemE (s1) == 1) {
                        if (strcmp(s1, s2) == 0) {
                            int tam = 0, i = 0;
                            tam = strlen(s1);
                            for (i = 0; i < tam; i++) {
                                if (s1[i] ^ chave >= 32 && s1[i] ^ chave <= 126) printf("%c", s1[i] ^ chave);
                            }
                        } else printf("ITEN F INVALIDO\n");
                    } else printf("ITEN E INVALIDO\n");
                } else printf("ITEN D INVALIDO\n");
            } else printf("ITEN C INVALIDO\n");
        } else printf("ITEN B INVALIDO\n");
    } else printf("ITEN A INVALIDO\n");

    return 0;
}