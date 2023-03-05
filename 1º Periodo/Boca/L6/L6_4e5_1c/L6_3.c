#include <stdio.h>

typedef struct pacote {
    int id_mensagem, id_pacote, cod_erro;
    char tam, mensagem[30]; 
} tPacote;

tPacote LePacote () {
    tPacote pacote;
    scanf("%d %d %c%9[^\n]", &pacote.id_mensagem, &pacote.id_pacote, &pacote.tam, pacote.mensagem);
    scanf("%d", &pacote.cod_erro);
    return pacote;
}

int VerificaFalha (tPacote pacote) {
    int i = 0, num = 0, soma = 0;
    num = pacote.tam - '0';
    soma = pacote.id_mensagem + pacote.id_pacote + num;
    for (i = 0; i < num; i++) {
        soma = soma + pacote.mensagem[i];
    }

    if (soma == pacote.cod_erro) {
        return 0;
    } else return 1;
}

void OrdenaMensagem (tPacote pacote[], int qtd) {
    int i = 0, j = 0, aux = 0;
    tPacote copia;

    for (i = 0; i < qtd - 1; i++) {
        copia = pacote[i];
        for (j = i + 1; j < qtd; j++) {
            if (pacote[i].id_mensagem > pacote[j].id_mensagem) {
                pacote[i] = pacote[j];
                pacote[j] = copia;
                copia = pacote[i];
            } else if (pacote[i].id_mensagem == pacote[j].id_mensagem) {
                if (pacote[i].id_pacote > pacote[j].id_pacote) {
                    pacote[i] = pacote[j];
                    pacote[j] = copia;
                    copia = pacote[i];
                }
            }
        }
    }
}

void ImprimePacote (tPacote pacote[], int qtd) {
    int i = 0, j = 0, aux = 0, k = 0, num = 0;
    
    for (i = 0; i < qtd; i++) {
        aux = 0;
        if (VerificaFalha(pacote[i]) == 1) {
            printf("##FALHA##");
        } else {
            num = pacote[i].tam - '0';
            for (k = 0; k < num; k++) {
                printf("%c", pacote[i].mensagem[k]);
            }
        }
        for (j = i + 1; j < qtd; j++) {
            if (pacote[j].id_mensagem == pacote[i].id_mensagem) {
                num = pacote[j].tam - '0';
                aux++;
                if (VerificaFalha(pacote[j]) == 1) {
                    printf("##FALHA##");
                } else {
                    for (k = 0; k < num; k++) {
                        printf("%c", pacote[j].mensagem[k]);
                    }
                }
            }
        }
        i = i + aux;
        if (i < qtd - 1) {
            printf("\n");
        }         
    }
}

int main() {
    int qtd = 0, i = 0;
    

    scanf("%d", &qtd);
    tPacote pacote[qtd];

    for (i = 0; i < qtd; i++) {
        pacote[i] = LePacote();
    }

    
    OrdenaMensagem(pacote, qtd);
    ImprimePacote(pacote, qtd);
    return 0;
}