#ifndef _VOTACAO_H
#define _VOTACAO_H
#include "leitura.h"
#include "layout.h"


char decisaoEleitor(char c1, char c2, char c3, char c4);

int votoBranco (char voto[]);

int buscaCandidato (char voto[], tCandidato candidatos[], unsigned short int totalCandidatos, char cargo);

int votacao (char cargo, tCandidato candidatos[], unsigned short int totalCandidatos, tPartido partidos[], unsigned short int totalPartidos, unsigned short int votosInvalidos);


#endif