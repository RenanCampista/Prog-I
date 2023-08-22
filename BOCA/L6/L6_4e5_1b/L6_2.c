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

void ImprimePacote (tPacote pacote) {
    int i = 0, num;
    num = pacote.tam - '0'; //Transforma char em inteiro
    printf("PCT: %d,%d,%d,", pacote.id_mensagem, pacote.id_pacote, num);
    for (i = 0; i < num; i++) {
        printf("%c", pacote.mensagem[i]);
    }
    printf(",%d\n", pacote.cod_erro);
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

int main() {
    int qtd = 0, i = 0;
    tPacote pacote;

    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++) {
        pacote = LePacote();
        if (VerificaFalha(pacote) == 1) {
            printf("FALHA!\n");
        } else ImprimePacote(pacote);
    }

    return 0;
}