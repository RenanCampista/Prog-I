#include <stdio.h>
#define TRUE 1;
#define FALSE 0;

int EhPalindromo(int num) {
    int resto = 0, reverso = 0, copia = 0;
    copia = num;
    while (num > 0) {
        resto = num % 10;
        reverso = reverso * 10 + resto;
        num = num / 10;
    }
    if (reverso == copia) {
        return TRUE;
    }else {
        return FALSE;
    }
}

int main() {
    int num = 0;

    while ( scanf("%d", &num) == 1) {
        if (EhPalindromo(num) == 1) {
            printf("S\n");
        }else if (EhPalindromo(num) == 0){
            printf("N\n");
        }
    }

    return 0;
}