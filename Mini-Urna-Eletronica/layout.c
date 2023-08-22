#include "layout.h"

void telaConfirmacao () {
    printf("- Confirmar (c ou C) ou Corrigir (r ou R)? ");
}

void telaInicial () {
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tBEM-VINDO A MINI URNA ELETRONICA\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("- Instrucoes para votar:\n");
    printf("-- Digite o numero do candidato para votar\n");
    printf("-- Aperte b ou B para votar em BRANCO\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("- Digite seu ID para iniciar: ");
}

void telaUrna () {
    system("clear||cls");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("=-=-=-=-=-=-=-=-= URNA ELETRONICA =-=-=-=-=-=-=-=-=\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void telaVotoBranco () {
    printf("- Voce esta votando em BRANCO\n");
    telaConfirmacao();
}

void telaVotoNulo () {
    printf("- Voce esta ANULANDO seu voto\n");
    telaConfirmacao();
}

void telaFinal () {
    printf("- VOTO REGISTRADO COM SUCESSO\n");
    printf("- Deseja registrar um novo voto (n ou N) ou finalizar (f ou F) a votacao? ");
}

void telaCandidato (tCandidato candidato, unsigned short int totalPartidos, tPartido partidos[]) {
    unsigned short int i = 0;
    printf("- Voce esta votando em:\n");
    printf("- Nome: %s\n", candidato.nome);
    for (i = 0; i < totalPartidos; i++) {
        if (strcmp(partidos[i].sigla, candidato.partido) == 0) {
            printf("- PARTIDO: %s (%s)\n", partidos[i].nome, candidato.partido);
            break;
        } 
    }
    telaConfirmacao();
}

void upperCandidato (tCandidato candidatos[], unsigned short int totalCandidatos) {
    unsigned short int i = 0, j = 0;

    for (i = 0; i < totalCandidatos; i++) {
        j = 0;
        while(candidatos[i].nome[j] != '\0') {
            if (candidatos[i].nome[j] >= 'a' && candidatos[i].nome[j] <= 'z') {
                candidatos[i].nome[j]-= 32;
            }
            j++;
        }
    }
}

void upperPartido (tPartido partidos[], unsigned short int totalPartidos) {
    unsigned short int i = 0, j = 0;

    for (i = 0; i < totalPartidos; i++) {
        j = 0;
        while(partidos[i].nome[j] != '\0') {
            if (partidos[i].nome[j] >= 'a' && partidos[i].nome[j] <= 'z') {
                partidos[i].nome[j]-= 32;
            }
            j++;
        }
    }
}
