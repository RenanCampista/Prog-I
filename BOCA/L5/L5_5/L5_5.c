#include <stdio.h>

int ProcuraNum(int tam, int vet[], int num) {
    int i = 0, aux = 0;

    for (i = 0; i < tam; i++) {
        if (num == vet[i]) {
            aux++;
            return i;
            break;
        }
    }
    if (aux == 0) {
        return tam;
    }
}

int main() {
    int num = 0, tam = 0, i = 0;

    scanf("%d %d", &num, &tam);
    int vet[tam];

    for (i = 0; i < tam; i++) {
        scanf(" %d", &vet[i]);
    }
    
    printf("RESP:%d", ProcuraNum(tam, vet, num));
    return 0;
}