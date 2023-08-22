#ifndef _LEITURA_H
#define _LEITURA_H
#include <stdio.h>
#include <stdlib.h>


typedef struct partido {
    char nome[61];
    char sigla[6];
    char numero[3];
    unsigned short int votosDF;
    unsigned short int votosDE;
    float mediaIdadeDF;
    float mediaIdadeDE;
    unsigned short int naoHomensDF;
    unsigned short int naoHomensDE;
    unsigned short int totalCandidatosDF;
    unsigned short int totalCandidatosDE;
    float porcentagemVotosDF;
    float porcentagemVotosDE;
} tPartido;

typedef struct candidato {
    char nome[61];
    char genero;
    unsigned short int idade;
    char cargo;
    char numero[6];
    char partido[6];
    unsigned short int apto;
    unsigned short int qtdVoto;
} tCandidato;

typedef struct eleitor {
    char nomeCompleto[61];
    char id[7];
    unsigned short int votou; 
} tEleitor;


int lePartido (FILE *file, tPartido partidos[]);

int leCandidato (FILE *file, tCandidato candidatos[]);

int leEleitor (FILE *file, tEleitor eleitores[]);

void limpaBuffer();


#endif