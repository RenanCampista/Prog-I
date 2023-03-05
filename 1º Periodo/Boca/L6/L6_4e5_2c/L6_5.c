#include <stdio.h>

typedef struct cartela {
    int id, tam, num[7][7], marcou;

} tCartela;

typedef struct partida {
    tCartela cartela[20];
    int qtdCartelas;

} tPartida;

tPartida MarcaCartela (tPartida partida, int num);
int VenceuCartela (tCartela cartela);

void ImprimeCartela (tCartela cartela) {
    int i = 0, j = 0, aux = 0;

    printf("ID:%d\n", cartela.id);
    for (i = 0; i < cartela.tam; i++) {
        for (j = 0; j < cartela.tam; j++) {
            if (cartela.num[i][j] < 10) {
                printf("00%d", cartela.num[i][j]);
            } else if (cartela.num[i][j] < 100 && cartela.num[i][j] > 10) {
                printf("0%d", cartela.num[i][j]);
            } else printf("%d", cartela.num[i][j]);
            if (j < cartela.tam - 1) {
                printf("|");
            }
        }
        printf("\n");
    }
}

tPartida LeCartelasPartida () {
    tPartida partida;
    int i = 0, j = 0, k = 0;

    scanf("%d", &partida.qtdCartelas);
   

    for (k = 0; k < partida.qtdCartelas; k++) {
        scanf("%d %d", &partida.cartela[k].id, &partida.cartela[k].tam);
        for (i = 0; i < partida.cartela[k].tam; i++) {
            for (j = 0; j < partida.cartela[k].tam; j++) {
                scanf("%d ", &partida.cartela[k].num[j][i]);
            }
        }      
    }
    return partida;
}

tPartida ResetaPartida(tPartida partida) {
    int i = 0;

    for (i = 0; i < partida.qtdCartelas; i++) {
        partida.cartela[i].marcou = 0;
    }

    return partida;
}

void JogaPartida (tPartida partida) {
    int num = 0, i = 0, j = 0, k = 0, aux = 0, ganhador = 0;

    while (1) {
        scanf("%d ", &num);
        if (num == -1) break;
        for (i = 0; i < partida.qtdCartelas; i++) {
            if (partida.cartela[i].marcou == partida.cartela[i].tam * partida.cartela[i].tam) {
                ganhador = 1;
            }
        }
        for (i = 0; i < partida.qtdCartelas; i++) {
            for (j = 0; j < partida.cartela[i].tam; j++) {
                for (k = 0; k < partida.cartela[i].tam; k++) {
                    if (num == partida.cartela[i].num[j][k] && ganhador == 0) {
                        partida.cartela[i].marcou += 1;
                    }
                }
            }
        }
    }

    aux = 0;
    for (i = 0; i < partida.qtdCartelas; i++) {
        if (partida.cartela[i].marcou == partida.cartela[i].tam * partida.cartela[i].tam) {
            if (aux == 0) {
                printf("COM VENCEDOR\n");
            }

            ImprimeCartela(partida.cartela[i]);
            aux++;
        }
    }
    if (aux == 0) {
        printf("SEM VENCEDOR\n");
    }
}

int main(){
    tPartida partida;
    int qtdPartidas, i;

    partida = LeCartelasPartida();
    
    scanf ("%d", &qtdPartidas);
    for (i = 0; i < qtdPartidas; i++){
        if ( i!=0 ) printf("\n");
        printf("PARTIDA %d\n", i+1);
        
        partida = ResetaPartida(partida);
        
        JogaPartida(partida);
    }

    return 0;
}