#ifndef _ORDENACAO_H
#define _ORDENACAO_H
#include "leitura.h"
#include "apuracao.h"
#include "constantes.h"
#include <string.h>


void ordenaEleitos (tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE);

void ordenaCandidatos (tCandidato candidatos[], unsigned short int totalCandidatos);

void ordenaPartidos (tPartido partidos[], unsigned short int totalPartidos, char cargo);

void qtdNaoHomens (tPartido partidos[], unsigned short int totalPartidos, tCandidato candidatos[], unsigned short int totalCandidatos);


#endif