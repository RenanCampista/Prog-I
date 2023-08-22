#ifndef _IMPRESSAO_H
#define _IMPRESSAO_H
#include "leitura.h"
#include "apuracao.h"
#include "votacao.h"
#include "relatorios.h"
#include "constantes.h"


void imprimeBoletim (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, tEleitor eleitores[], unsigned short int totalEleitores, unsigned short int votosInvalidos[]);

void imprimeBancada (FILE *file, tPartido partidos[], unsigned short int totalPartidos, int distrVagas[]);

void imprimeEleitos (FILE *file, tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE);

void imprimeRankPres (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos);

void imprimeRankGov (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos);

void imprimeRankDF (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos);

void imprimeRankDE (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos);

void imprimeGenerLeg (FILE *file, tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE);

void imprimeMediaIdade (FILE *file, tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE);


#endif