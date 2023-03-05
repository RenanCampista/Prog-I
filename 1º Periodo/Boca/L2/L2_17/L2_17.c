#include <stdio.h>

int main() {
    int opcao = 0, codigo = 0;
    char texto;
    //1 codifica e 2 decodifica. Apenas letra minusculas
    scanf("%d %d ", &opcao, &codigo);
    
    codigo = codigo % 26;

    while (1) {
        scanf("%c", &texto);
        if (opcao == 1) {
            if (texto >= 'a' && texto <= 'z') {
                texto = texto + codigo;
                if (texto > 'z') {
                    texto = texto - 26;
                }
                printf("%c", texto);
            }else {
                printf("%c", texto);
                if (texto == '.') {
                    break;
                }
            }
        }else if (opcao == 2) {
            if (texto >= 'a' && texto <= 'z') {
                texto = texto - codigo;
                if (texto < 'a') {
                    texto = texto + 26;
                }
                printf("%c", texto);
            }else {
                printf("%c", texto);
                if (texto == '.') {
                    break;
                }
            }
        } else {
            printf("Operacao invalida.");
            break;
        }        
    }
    return 0;
}