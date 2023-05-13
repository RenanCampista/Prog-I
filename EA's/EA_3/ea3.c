#include <stdio.h>
#include <string.h>

typedef struct presidente {
    char nome[30];
    char partido[60];
    int num;
    int votos;
} tPresidente;

typedef struct ministro {
    char nome[30];
    char partido[60];
    int num;
    int votos;
} tMinistro;

typedef struct eleitor {
    char id_eleitor;
    int num_presidente, num_ministro;
} tEleitor;

int VerificaIdRepetido (tEleitor eleitores[], int qtd_eleitores) {
    int i = 0, j = 0, cont = 0;

    for (i = 0; i < qtd_eleitores - 1; i++) {
        for (j = i + 1; j < qtd_eleitores; j++) {
            if (eleitores[i].id_eleitor == eleitores[j].id_eleitor) {
                cont++;
            }
        }
    }

    if (cont > 0) return 1;
    else return 0;
}

float Comparecimento (int i, int qtd_eleitores) {
    return (float) (100 * i) / qtd_eleitores;
}

int VerificaEmpatePres (tPresidente eleito, tPresidente presidentes[]) {
    int i = 0, cont = 0;

    for (i = 0; i < 3; i++) {
        if (eleito.votos == presidentes[i].votos) {
            cont++;
        }
    }
    if (cont > 1) return 1;
    else return 0;
}

int VerificaEmpateMin (tMinistro eleito, tMinistro ministros[]) {
    int i = 0, cont = 0;

    for (i = 0; i < 3; i++) {
        if (eleito.votos == ministros[i].votos) {
            cont++;
        }
    }
    if (cont > 1) return 1;
    else return 0;
}

int VerificaVotacaoInconclusiva (int votos, int votos_invalidos) {
    if (votos_invalidos > votos) return 1;
    else return 0;
}

float PorcentagemVotosPres (tPresidente eleito, tPresidente presidentes[], int votos_invalidos) {
    int total_votos = 0, i = 0;
    total_votos = votos_invalidos;

    for (i = 0; i < 3; i++) {
        total_votos += presidentes[i].votos;
    }

    return (float) (100 * eleito.votos) / total_votos;
}

float PorcentagemVotosMin (tMinistro eleito, tMinistro ministros[], int votos_invalidos) {
    int total_votos = 0, i = 0;
    total_votos = votos_invalidos;

    for (i = 0; i < 3; i++) {
        total_votos += ministros[i].votos;
    }

    return (float) (100 * eleito.votos) / total_votos;
}

int main() {
    int qtd_eleitores = 0, i = 0, j = 0, votos_nulos_pres = 0, votos_nulos_min = 0, votos_brancos_pres = 0, votos_brancos_min = 0;
    tPresidente presidente[3];
    tMinistro ministro[3];

    //REGISTRO DE CANDIDATOS
    strcpy(presidente[0].nome, "EDSGER DIJKSTRA");
    presidente[0].num = 10;
    strcpy(presidente[0].partido, "PARTIDO DO MELHOR CAMINHO (PMC)");
    presidente[0].votos = 0;

    strcpy(presidente[1].nome, "ALAN TURING");
    presidente[1].num = 42;
    strcpy(presidente[1].partido, "PARTIDO DOS AVANCO INTELECTUAL (PAI)");
    presidente[1].votos = 0;

    strcpy(presidente[2].nome, "CAROL SHAW");
    presidente[2].num = 26;
    strcpy(presidente[2].partido, "MULHERES PROGRAMADORAS UNIDAS (MPU)");
    presidente[2].votos = 0;

    strcpy(ministro[0].nome, "TIM BERNERS-LEE");
    ministro[0].num = 36;
    strcpy(ministro[0].partido, "WORLD WIDE WEB (WWW)");
    ministro[0].votos = 0;

    strcpy(ministro[1].nome, "LINUS TORVALDS");
    ministro[1].num = 64;
    strcpy(ministro[1].partido, "LINUX (LINUX)");
    ministro[1].votos = 0;

    strcpy(ministro[2].nome, "ADA LOVELACE");
    ministro[2].num = 18;
    strcpy(ministro[2].partido, "GAMERS UNIDOS (GU)");
    ministro[2].votos = 0;


    char c;
    scanf("%d", &qtd_eleitores);
    scanf("%c", &c);
    tEleitor eleitores[qtd_eleitores];

    //RECEBENDO OS VOTOS
    i = 0;
    while (1) {
        scanf("%c", &eleitores[i].id_eleitor);
        if (eleitores[i].id_eleitor == 'P') {
            break;
        }
        scanf(" %d %d\n", &eleitores[i].num_presidente, &eleitores[i].num_ministro);
        i++;
    }

    int eleitor_presente = 0;
    eleitor_presente = i;

    //VERIFICANDO SE A VOTACAO FOI REGULAR
    if (eleitor_presente > qtd_eleitores || VerificaIdRepetido(eleitores, eleitor_presente) == 1) {
        printf("ELEICAO ANULADA\n");
    } else {
        float comparecimento = 0;
        comparecimento = Comparecimento(eleitor_presente, qtd_eleitores);

        //APURACAO DOS VOTOS
        int pres_encontrado = 0, min_encontrado = 0;
        for (i = 0; i < eleitor_presente; i++) {
            pres_encontrado = 0;
            min_encontrado = 0;

            if (eleitores[i].num_presidente == 0) {
                votos_brancos_pres++;
            } else {
                for (j = 0; j < 3; j++) {
                    if (eleitores[i].num_presidente == presidente[j].num) {
                        presidente[j].votos++;
                        pres_encontrado = 1;
                    }
                }

                if (pres_encontrado == 0) {
                    votos_nulos_pres++;
                }
            }


            if (eleitores[i].num_ministro == 0) {
                votos_brancos_min++;
            } else {
                for (j = 0; j < 3; j++) {
                    if (eleitores[i].num_ministro == ministro[j].num) {
                        ministro[j].votos++;
                        min_encontrado = 1;
                    }
                }

                if (min_encontrado == 0) {
                    votos_nulos_min++;
                }
            }            
        }

        //RESULTADO
        tPresidente pres_eleito;
        tMinistro min_eleito;

        printf("FIM DA ELEICAO\n");

        //PRESIDENTE ELEITO
        printf("- PRESIDENTE ELEITO: ");
        pres_eleito = presidente[0];
        for (i = 1; i < 3; i++) {
            if (presidente[i].votos > pres_eleito.votos) {
                pres_eleito = presidente[i];
            }
        }

        //VERIFICAR SE HOUVE EMPATE
        if (VerificaEmpatePres(pres_eleito, presidente) == 1) {
            printf("EMPATE\n");
        } else if (VerificaVotacaoInconclusiva(pres_eleito.votos, votos_brancos_pres + votos_nulos_pres) == 1) {
            //VERIFICAR SE O ELEITO TEM MAIS VOTOS QUE INVALIDOS
            printf("SEM DECISAO\n");
        } else {
            printf("%s (%s), %d, %.2f%%\n", pres_eleito.nome, pres_eleito.partido, pres_eleito.votos, PorcentagemVotosPres(pres_eleito, presidente, votos_brancos_pres + votos_nulos_pres));
        } 


        //MINISTRO ELEITO
        printf("- PRIMEIRO MINISTRO ELEITO: ");
        min_eleito = ministro[0];
        for (i = 1; i < 3; i++) {
            if (ministro[i].votos > min_eleito.votos) {
                min_eleito = ministro[i];
            }
        }

        //VERIFICAR SE HOUVE EMPATE
        if (VerificaEmpateMin(min_eleito, ministro) == 1) {
            printf("EMPATE\n");
        } else if (VerificaVotacaoInconclusiva(min_eleito.votos, votos_brancos_min + votos_nulos_min) == 1) {
            //VERIFICAR SE O ELEITO TEM MAIS VOTOS QUE INVALIDOS
            printf("SEM DECISAO\n");
        } else {
            printf("%s (%s), %d, %.2f%%\n", min_eleito.nome, min_eleito.partido, min_eleito.votos, PorcentagemVotosMin(min_eleito, ministro, votos_brancos_min + votos_nulos_min));
        }

        //COMPARECIMENTO
        printf("- COMPARECIMENTO: %.2f%%\n", comparecimento);

        //NULOS E BRANCOS
        printf("- NULOS E BRANCOS: %d, %d\n", votos_nulos_pres + votos_brancos_pres, votos_nulos_min + votos_brancos_min);
    }

    return 0;
}