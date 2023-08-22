#ifndef _APURACAO_H
#define _APURACAO_H
#include <string.h>
#include "leitura.h"
#include "constantes.h"


typedef struct nomeados {
    char nome[61];
    char cargo[20];
    char partido[6];
    char genero;
    unsigned short int idade;
    unsigned short int votos;
} tNomeados;


float arredonda (float num);

float calculaPorcentagem (unsigned short int parte, unsigned short int total);

int calculaVagas (float porcetagem, unsigned short int total);

void defineVagasDF (tPartido partidos[], unsigned short int totalPartidos, int distrVagas[]);

void defineVagasDE (tPartido partidos[], unsigned short int totalPartidos, int distrVagas[]);

void elegeDepFederal (tPartido partidos[], unsigned short int totalPartidos, tCandidato depFed[], unsigned short int totalDF, int distrVagas[], tNomeados eleitos[]);

void elegeDepEstadual (tPartido partidos[], unsigned short int totalPartidos, tCandidato depEst[], unsigned short int totalDE, int distrVagas[], tNomeados eleitos[], unsigned short int totalEleitosDF);

void eLegePresidente (tCandidato candidatos[], unsigned short int totalCandidatos, tNomeados eleitos[]);

void elegeGovernador (tCandidato candidatos[], unsigned short int totalCandidatos, tNomeados eleitos[]);

void votosPorPartido (tPartido partidos[], unsigned short int totalPartidos, tCandidato candidatos[], unsigned short int totalCandidatos);

void porcentagemVotosPartido (tPartido partidos[], unsigned short int totalPartidos, unsigned short int votosValDF, unsigned short int votosValDE);

int totalCandDE (tCandidato candidatos[], unsigned short int totalCandidatos);

int totalCadDF (tCandidato candidatos[], unsigned short int totalCandidatos);

int calculaTotalEleitosLegislativo (unsigned short int totalPartidos, int distrVagas[]);


#endif