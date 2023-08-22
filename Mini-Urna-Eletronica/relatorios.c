#include "relatorios.h"


int totalVotosValidos (char cargo, tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int i = 0, aux = 0;
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == cargo && candidatos[i].qtdVoto > 0 && candidatos[i].apto == 1) {
            aux += candidatos[i].qtdVoto;
        }
    } return aux;
}

void canditadosPorPartido (tPartido partidos[], int totalPartidos, tCandidato candidatos[], int totalCandidatos) {
    unsigned short int i = 0, j = 0;

    for (i = 0; i < totalCandidatos; i++) {
        for (j = 0; j < totalPartidos; j++) {
            if (candidatos[i].cargo == 'E') {
                if (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].apto == 1) {
                    partidos[j].totalCandidatosDE++;
                }
            } else if (candidatos[i].cargo == 'F') {
                if (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].apto == 1) {
                    partidos[j].totalCandidatosDF++;
                }
            }
        }
    }
}

int eleitoresPresentes (tEleitor eleitores[], unsigned short int totalEleitores) {
    unsigned short int i = 0, aux = 0;
    for (i = 0; i < totalEleitores; i++) {
        if (eleitores[i].votou == 1) {
            aux++;
        }
    } return aux;
}

void mediaIdPartido (tPartido partidos[], unsigned short int totalPartidos, tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int i = 0, j = 0;

    for (i = 0; i < totalCandidatos; i++) {
        for (j = 0; j < totalPartidos; j++) {
            if (candidatos[i].cargo == 'E') {
                if (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].apto == 1) {
                    partidos[j].mediaIdadeDE += candidatos[i].idade;
                }

            } else if (candidatos[i].cargo == 'F') {
                if (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].apto == 1) {
                    partidos[j].mediaIdadeDF += candidatos[i].idade;
                }
            }
        }
    }

    //AJUSTANDO A MEDIA
    for (i = 0; i < totalPartidos; i++) {
        partidos[i].mediaIdadeDE = partidos[i].mediaIdadeDE / (float)partidos[i].totalCandidatosDE;
        partidos[i].mediaIdadeDF = partidos[i].mediaIdadeDF / (float)partidos[i].totalCandidatosDF;
    }
}

void generoLegislativo (tNomeados eleitos[], int generoM[], int generoF[], int generoO[]){
    unsigned short int i = 0;
    for (i = 2; i < 17; i++) {
        if (eleitos[i].genero == 'M') {
            generoM[0]++;
        }else if (eleitos[i].genero == 'F') {
            generoF[0]++;
        }else if (eleitos[i].genero == 'O') {
            generoO[0]++;
        }
    } 
}

void mediaIdadeCargos (tNomeados eleitos[], float mediaP[], float mediaG[], float mediaDF[], float mediaDE[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE) {
    unsigned short int i = 0;
    mediaP[0] = eleitos[0].idade;
    mediaG[0] = eleitos[1].idade;

    for (i = 2; i < 7; i++) {
        mediaDF[0] += eleitos[i].idade;
    }
    mediaDF[0] = mediaDF[0] / totalEleitosDF;

    for (i = 7; i < 17; i++) {
        mediaDE[0] += eleitos[i].idade;
    }
    mediaDE[0] = mediaDE[0] / totalEleitosDE;
}
