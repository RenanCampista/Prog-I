#ifndef _VALIDACAO_H
#define _VALIDACAO_H
#include "leitura.h"
#include <string.h>
#include <math.h>


void validaCandidato (tCandidato candidatos[], unsigned short int totalCandidatos, tPartido partidos[], unsigned short int totalPartidos);

int validaID (tEleitor eleitores[], unsigned short int totalEleitores);


#endif