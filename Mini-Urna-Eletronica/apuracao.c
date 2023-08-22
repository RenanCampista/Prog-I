#include "apuracao.h"


float arredonda (float num) {
    return (num >= 0) ? (int)(num + 0.5) : (int)(num - 0.5);
}

float calculaPorcentagem (unsigned short int parte, unsigned short int total) {
    return ((float)parte * 100) / (float)total;
}

int calculaVagas (float porcetagem, unsigned short int total) {
    return arredonda((porcetagem * (float)total) / 100);
}

void defineVagasDF (tPartido partidos[], unsigned short int totalPartidos, int distrVagas[]) {
    unsigned short int i = 0, vagas = VAGASDF;
    for (i = 0; i < totalPartidos; i++) {
        if (vagas == 0) {
            distrVagas[i] = 0;
        } else if (calculaVagas(partidos[i].porcentagemVotosDF, 5) > vagas) {
            distrVagas[i] = vagas;
            vagas = 0;
        } else if (vagas > 0) {
            distrVagas[i] = calculaVagas(partidos[i].porcentagemVotosDF, 5);
            vagas = vagas - calculaVagas(partidos[i].porcentagemVotosDF, 5);
        }      
    }
}

void defineVagasDE (tPartido partidos[], unsigned short int totalPartidos, int distrVagas[]) {
    unsigned short int i = 0, vagas = VAGASDE;
    for (i = 0; i < totalPartidos; i++) {
        if (vagas == 0) {
            distrVagas[i] = 0;
        } else if (calculaVagas(partidos[i].porcentagemVotosDE, 10) > vagas) {
            distrVagas[i] = vagas;
            vagas = 0;
        } else if (vagas > 0) {
            distrVagas[i] = calculaVagas(partidos[i].porcentagemVotosDE, 10);
            vagas = vagas - calculaVagas(partidos[i].porcentagemVotosDE, 10);
        }      
    }
}

void elegeDepFederal (tPartido partidos[], unsigned short int totalPartidos, tCandidato depFed[], unsigned short int totalDF, int distrVagas[], tNomeados eleitos[]){
    unsigned short int  l = 2, i = 0, j = 0, vagas = 0, cont = 0;

    for (i = 0; i < totalPartidos; i++) {
        vagas = distrVagas[i];
        cont = 0;
        for (j = 0; j < totalDF; j++) {
            if (strcmp(depFed[j].partido, partidos[i].sigla) == 0 && cont < vagas) {
                strcpy(eleitos[l].nome, depFed[j].nome);
                strcpy(eleitos[l].cargo, "DEPUTADO FEDERAL");
                strcpy(eleitos[l].partido, depFed[j].partido);
                eleitos[l].idade = depFed[j].idade;
                eleitos[l].genero = depFed[j].genero;
                eleitos[l].votos = depFed[j].qtdVoto;
                l++;
                cont++;
            }
        }
    }
}

void elegeDepEstadual (tPartido partidos[], unsigned short int totalPartidos, tCandidato depEst[], unsigned short int totalDE, int distrVagas[], tNomeados eleitos[], unsigned short int totalEleitosDF){
    unsigned short int  l = 0, i = 0, j = 0, vagas = 0, cont = 0;
    l = totalEleitosDF + VAGASEXECUTIVO;

    for (i = 0; i < totalPartidos; i++) {
        vagas = distrVagas[i];
        cont = 0;
        for (j = 0; j < totalDE; j++) {
            if (strcmp(depEst[j].partido, partidos[i].sigla) == 0 && cont < vagas) {
                strcpy(eleitos[l].nome, depEst[j].nome);
                strcpy(eleitos[l].cargo, "DEPUTADO ESTADUAL");
                strcpy(eleitos[l].partido, depEst[j].partido);
                eleitos[l].idade = depEst[j].idade;
                eleitos[l].genero = depEst[j].genero;
                eleitos[l].votos = depEst[j].qtdVoto;
                l++;
                cont++;
            }
        }
    }
}

void eLegePresidente (tCandidato candidatos[], unsigned short int totalCandidatos, tNomeados eleitos[]) {
    unsigned short int i = 0, maisVotos = 0;

    strcpy(eleitos[0].cargo, "PRESIDENTE");
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'P' && candidatos[i].qtdVoto > maisVotos) {
            maisVotos = candidatos[i].qtdVoto;
            strcpy(eleitos[0].nome, candidatos[i].nome);
            strcpy(eleitos[0].partido, candidatos[i].partido);
            eleitos[0].idade = candidatos[i].idade;
            eleitos[0].genero = candidatos[i].genero;
            eleitos[0].votos = candidatos[i].qtdVoto;
        }
    }

}

void elegeGovernador (tCandidato candidatos[], unsigned short int totalCandidatos, tNomeados eleitos[]) {
    unsigned short int i = 0, maisVotos = 0;

    strcpy(eleitos[1].cargo, "GOVERNADOR");
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'G' && candidatos[i].qtdVoto > maisVotos) {
            maisVotos = candidatos[i].qtdVoto;
            strcpy(eleitos[1].nome, candidatos[i].nome);
            strcpy(eleitos[1].partido, candidatos[i].partido);
            eleitos[1].idade = candidatos[i].idade;
            eleitos[1].genero = candidatos[i].genero;
            eleitos[1].votos = candidatos[i].qtdVoto;
        }
    }
}

void votosPorPartido (tPartido partidos[], unsigned short int totalPartidos, tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int i = 0, j = 0;

    for (i = 0; i < totalCandidatos; i++) {
        for (j = 0; j < totalPartidos; j++) {
            if (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].cargo == 'E') {
                partidos[j].votosDE += candidatos[i].qtdVoto;
            }
            if (strcmp(candidatos[i].partido, partidos[j].sigla) == 0 && candidatos[i].cargo == 'F') {
                partidos[j].votosDF += candidatos[i].qtdVoto;
            }
        }
    }
}

void porcentagemVotosPartido (tPartido partidos[], unsigned short int totalPartidos, unsigned short int votosValDF, unsigned short int votosValDE) {
    unsigned short int i = 0;

    for (i = 0; i < totalPartidos; i++) {
        partidos[i].porcentagemVotosDE = calculaPorcentagem(partidos[i].votosDE, votosValDE);
        partidos[i].porcentagemVotosDF = calculaPorcentagem(partidos[i].votosDF, votosValDF);
    }
}

int totalCandDE (tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int totalDE = 0, i = 0;

    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'E' && candidatos[i].apto == 1) {
            totalDE++;
        }
    } 
    return totalDE;
}

int totalCadDF (tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int totalDF = 0, i = 0;

    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'F' && candidatos[i].apto == 1) {
            totalDF++;
        }
    } 
    return totalDF;
}

int calculaTotalEleitosLegislativo (unsigned short int totalPartidos, int distrVagas[]) {
    int i = 0, totalVagas = 0;

    for (i = 0; i < totalPartidos; i++) {
        totalVagas += distrVagas[i];
    }
    return totalVagas;
}