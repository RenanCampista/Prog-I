#include "ordenacao.h"


void ordenaEleitos (tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE) {
    unsigned short int i = 0, j = 0, k = 0, l = 0;
    tNomeados auxi;
    for (i = VAGASEXECUTIVO; i < totalEleitosDF + 1; i++) {
        auxi = eleitos[i];
        for (j = i + 1; j < totalEleitosDF + 2; j++) {
            if (eleitos[j].votos > eleitos[i].votos) {
                eleitos[i] = eleitos[j];
                eleitos[j] = auxi;
                auxi = eleitos[i];
            } else if (eleitos[i].votos == eleitos[j].votos) {
                if (strcmp(eleitos[j].nome, eleitos[i].nome) < 0) {
                    eleitos[i] = eleitos[j];
                    eleitos[j] = auxi;
                    auxi = eleitos[i];
                }
            }
        }
    }

    //ENCONTRAR O INDICE QUE COMECA OS DEPUTADOS ESTADUAIS
    for (i = 0; i < 17; i++) {
        if (strcmp(eleitos[i].cargo, "DEPUTADO ESTADUAL") == 0) {
            k = i;
            break;
        }
    }

    //DESCOBRIR A PARTE DA STRUCT QUE FOI UTILIZADA
    for (i = 0; i < 17; i++) {
        if ((strcmp(eleitos[i].cargo, "PRESIDENTE") == 0) || (strcmp(eleitos[i].cargo, "GOVERNADOR") == 0) || (strcmp(eleitos[i].cargo, "DEPUTADO ESTADUAL") == 0) || (strcmp(eleitos[i].cargo, "DEPUTADO FEDERAL") == 0)) {
            l++;
        }
    }

    for (i = k; i < l - 1; i++) {
        auxi = eleitos[i];
        for (j = i + 1; j < l; j++) {
            if (eleitos[j].votos > eleitos[i].votos) {
                eleitos[i] = eleitos[j];
                eleitos[j] = auxi;
                auxi = eleitos[i];
            } else if (eleitos[i].votos == eleitos[j].votos) {
                if (strcmp(eleitos[j].nome, eleitos[i].nome) < 0) {
                    eleitos[i] = eleitos[j];
                    eleitos[j] = auxi;
                    auxi = eleitos[i];
                }
            }
        }
    }
}

void ordenaCandidatos (tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int i = 0, j = 0;
    tCandidato aux;

    for (i = 0; i < totalCandidatos - 1; i++) {
        aux = candidatos[i];
        for (j = i + 1; j < totalCandidatos; j++) {
            if (candidatos[j].qtdVoto > candidatos[i].qtdVoto) {
                candidatos[i] = candidatos[j];
                candidatos[j] = aux;
                aux = candidatos[i];
            } else if (candidatos[i].qtdVoto == candidatos[j].qtdVoto) {
                if (strcmp(candidatos[j].nome, candidatos[i].nome) < 0) {
                    candidatos[i] = candidatos[j];
                    candidatos[j] = aux;
                    aux = candidatos[i];
                }
            }
        }
    }
}

void ordenaPartidos (tPartido partidos[], unsigned short int totalPartidos, char cargo) {
    unsigned short int i = 0, j = 0;
    tPartido copia;

    if (cargo == 'F') {
        for (i = 0; i < totalPartidos - 1; i++) {
            copia = partidos[i];
            for (j = i + 1; j < totalPartidos; j++) {
                if (partidos[j].porcentagemVotosDF > partidos[i].porcentagemVotosDF) {
                    partidos[i] = partidos[j];
                    partidos[j] = copia;
                    copia = partidos[i];
                } else if (partidos[j].porcentagemVotosDF == partidos[i].porcentagemVotosDF) {
                    if (partidos[j].mediaIdadeDF > partidos[i].mediaIdadeDF) {
                        partidos[i] = partidos[j];
                        partidos[j] = copia;
                        copia = partidos[i];
                    } else if (partidos[j].mediaIdadeDF == partidos[i].mediaIdadeDF) {
                        if (partidos[j].naoHomensDF > partidos[i].naoHomensDF) {
                            partidos[i] = partidos[j];
                            partidos[j] = copia;
                            copia = partidos[i];
                        }
                    }
                }
            }
        }
    } else if (cargo == 'E') {
        for (i = 0; i < totalPartidos - 1; i++) {
            copia = partidos[i];
            for (j = i + 1; j < totalPartidos; j++) {
                if (partidos[j].porcentagemVotosDE > partidos[i].porcentagemVotosDE) {
                    partidos[i] = partidos[j];
                    partidos[j] = copia;
                    copia = partidos[i];
                } else if (partidos[j].porcentagemVotosDE == partidos[i].porcentagemVotosDE) {
                    if (partidos[j].mediaIdadeDE > partidos[i].mediaIdadeDE) {
                        partidos[i] = partidos[j];
                        partidos[j] = copia;
                        copia = partidos[i];
                    } else if (partidos[j].mediaIdadeDE == partidos[i].mediaIdadeDE) {
                        if (partidos[j].naoHomensDE > partidos[i].naoHomensDE) {
                            partidos[i] = partidos[j];
                            partidos[j] = copia;
                            copia = partidos[i];
                        }
                    }
                }
            }
        }
    }
}

void qtdNaoHomens (tPartido partidos[], unsigned short int totalPartidos, tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int i = 0, j = 0;

    for (i = 0; i < totalCandidatos; i++) {
        for (j = 0; j < totalPartidos; j++) {
            if (candidatos[i].cargo == 'E') {
                if ((strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].genero == 'F' && candidatos[i].apto == 1) || 
                    (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].genero == 'O' && candidatos[i].apto == 1)) {
                    partidos[j].naoHomensDE++;
                }
            } else if (candidatos[i].cargo == 'F') {
                if ((strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].genero == 'F' && candidatos[i].apto == 1) || 
                    (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].genero == 'O' && candidatos[i].apto == 1)) {
                    partidos[j].naoHomensDF++;
                }
            }
        }
    }
}
