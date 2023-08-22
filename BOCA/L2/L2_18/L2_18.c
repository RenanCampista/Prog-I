#include <stdio.h>

int main(){
    int linha, i, j, coluna, pos_i, pos_j, maior = -3276, matriz;

    scanf("%d %d", &linha, &coluna);

    if(( linha >= 1 && linha <= 100)&&(coluna >= 1 && coluna <= 100)){
        for(i = 1; i <= linha; ++i){
            for(j = 1; j <= coluna; ++j){
                scanf("%d", &matriz);
                if(matriz >= -32767 && matriz <= 32767){
                    if(matriz > maior){
                        maior = matriz;
                        pos_i = i;
                        pos_j = j;
                    }
                }
            }
        }
    }
    printf("%d (%d, %d)", maior, pos_i, pos_j);
    return 0;
}