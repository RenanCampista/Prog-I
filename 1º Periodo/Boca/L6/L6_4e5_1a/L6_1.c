#include <stdio.h>

typedef struct pacote {
    int id_mensagem, id_pacote, cod_erro;
    char tam, mensagem[30]; 
} tPacote;

tPacote LePacote() {
    tPacote pacote;
    scanf("%d %d %c%9[^\n]", &pacote.id_mensagem, &pacote.id_pacote, &pacote.tam, pacote.mensagem);
    scanf("%d", &pacote.cod_erro);
    return pacote;
}

void ImprimePacote(tPacote pacote) {
    int i = 0, num;
    num = pacote.tam - '0'; //Transforma char em inteiro
    printf("PCT: %d,%d,%d,", pacote.id_mensagem, pacote.id_pacote, num);
    for (i = 0; i < num; i++) {
        printf("%c", pacote.mensagem[i]);
    }
    printf(",%d\n", pacote.cod_erro);
}

int main() {
    int qtd = 0, i = 0;
    tPacote pacote;
    
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++) {
        pacote = LePacote();
        ImprimePacote(pacote);
    }

    return 0;
}