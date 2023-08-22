#ifndef _RELATORIOS_H
#define _RELATORIOS_H
#include "apuracao.h"
#include "leitura.h"


int totalVotosValidos (char cargo, tCandidato candidatos[], unsigned short int totalCandidatos);

void canditadosPorPartido (tPartido partidos[], int totalPartidos, tCandidato candidatos[], int totalCandidatos);

int eleitoresPresentes (tEleitor eleitores[], unsigned short int totalEleitores);

void mediaIdPartido (tPartido partidos[], unsigned short int totalPartidos, tCandidato candidatos[], unsigned short int totalCandidatos);

void generoLegislativo (tNomeados eleitos[], int generoM[], int generoF[], int generoO[]);

void mediaIdadeCargos (tNomeados eleitos[], float mediaP[], float mediaG[], float mediaDF[], float mediaDE[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE);


#endif