#include <stdio.h>

typedef struct cartela {
    int id, tam, num[7][7];
} tCartela;

typedef struct partida {
    int qtd_cartelas;
    tCartela cartela[100], copia[100];
} tPartida;

tCartela LeCartela() {
    int i = 0, j = 0;
    tCartela cartela;

    scanf("%d %d", &cartela.id, &cartela.tam);

    for (i = 0; i < cartela.tam; i++) {
        for (j = 0; j < cartela.tam; j++) {
            scanf("%d ", &cartela.num[j][i]);   
        }
    }
    return cartela;
}

void ImprimeCartela (tCartela cartela) {
    int i = 0, j = 0;

    printf("ID:%d\n", cartela.id);
    for (i = 0; i < cartela.tam; i++) {
        for (j = 0; j < cartela.tam; j++) {
            if (cartela.num[i][j] < 10) {
                printf("00%d", cartela.num[i][j]);
            } else if (cartela.num[i][j] > 10 && cartela.num[i][j] < 100) {
                printf("0%d", cartela.num[i][j]);
            } else {
                printf("%d", cartela.num[i][j]);
            }
            if (j < cartela.tam - 1) {
                printf("|");
            }
        }
        printf("\n");
    }
}

tPartida LeCartelasPartida () {
    int i = 0;
    tPartida partida;

    scanf("%d", &partida.qtd_cartelas);

    for (i = 0; i < partida.qtd_cartelas; i++) {
        partida.cartela[i] = LeCartela();
        partida.copia[i] = partida.cartela[i];
    }

    return partida;
}

tPartida ResetaPartida (tPartida partida) {
    int i = 0;

    for (i = 0; i < partida.qtd_cartelas; i++) {
        partida.cartela[i] = partida.copia[i];
    }
    return partida;
}

tCartela MarcaCartela (tCartela cartela, int pedra) {
    int i = 0, j = 0;

    for (i = 0; i < cartela.tam; i++) {
        for (j = 0; j < cartela.tam; j++) {
            if (cartela.num[i][j] == pedra) {
                cartela.num[i][j] = -1;
            }
        }
    }
    return cartela;
}

int VenceuCartela (tCartela cartela) {
    int i = 0, j = 0, cont = 0;

    for (i = 0; i < cartela.tam; i++) {
        for (j = 0; j < cartela.tam; j++) {
            if (cartela.num[i][j] == -1) {
                cont++;
            }
        }
    }

    if (cont == cartela.tam * cartela.tam) return 1;
    else return 0;
}

void JogaPartida (tPartida partida) {
    int pedra = 0, i = 0, venceu = 0;

    while (1) {
        scanf("%d ", &pedra);
        if (pedra == -1) {
            break;
        }

        //VERIFICAR SE ALGUEM JA VENCEU
        for (i = 0; i < partida.qtd_cartelas; i++) {
            if (VenceuCartela(partida.cartela[i]) == 1) {
                venceu = 1;
            }
        }    

        //SE AINDA NINGUEM VENCEU MARCAR A CARTELA
        if (venceu == 0) {
            for (i = 0; i < partida.qtd_cartelas; i++) {
                partida.cartela[i] = MarcaCartela(partida.cartela[i], pedra);
            }
        }
    }

    //VERIFCAR NOVAMENTE
    for (i = 0; i < partida.qtd_cartelas; i++) {
        if (VenceuCartela(partida.cartela[i]) == 1) {
            venceu = 1;
        }
    }

    //RESULTADOS 
    if (venceu == 0) {
        printf("SEM VENCEDOR\n");
    } else {
        printf("COM VENCEDOR\n");
        for (i = 0; i < partida.qtd_cartelas; i++) {
            if (VenceuCartela(partida.cartela[i]) == 1) {
                ImprimeCartela(partida.copia[i]);
            }
        }
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