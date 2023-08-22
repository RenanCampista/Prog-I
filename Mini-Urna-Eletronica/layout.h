#ifndef _LAYOUT_H
#define _LAYOUT_H
#include "leitura.h"
#include <stdlib.h>
#include <string.h>


void telaConfirmacao ();

void telaInicial ();

void telaUrna ();

void telaVotoBranco ();

void telaVotoNulo ();

void telaFinal ();

void telaCandidato (tCandidato candidato, unsigned short int totalPartidos, tPartido partidos[]) ;

void upperCandidato (tCandidato candidatos[], unsigned short int totalCandidatos);

void upperPartido (tPartido partidos[], unsigned short int totalPartidos);


#endif