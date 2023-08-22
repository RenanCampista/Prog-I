#include "votacao.h"


char decisaoEleitor(char c1, char c2, char c3, char c4) {
    char decisao;
    scanf("%c", &decisao);
    limpaBuffer();
    while (1) {
        if (decisao == c1 || decisao == c2 || decisao == c3 || decisao == c4) {
            break;
        }
        printf("Por favor, digite uma opcao valida: ");
        scanf("%c", &decisao);
        limpaBuffer();
    }
    return decisao;
}

int votoBranco (char voto[]) {
    if (strcmp(voto, "b") == 0 || strcmp(voto, "B") == 0) {
        return 1;
    } return 0;
}

int buscaCandidato (char voto[], tCandidato candidatos[], unsigned short int totalCandidatos, char cargo) {
    unsigned short int i = 0;

    for (i = 0; i < totalCandidatos; i++) {
        if (strcmp(voto, candidatos[i].numero) == 0 && candidatos[i].cargo == cargo && candidatos[i].apto == 1) {
            return i;
        }
    } return -1;
}

int votacao (char cargo, tCandidato candidatos[], unsigned short int totalCandidatos, tPartido partidos[], unsigned short int totalPartidos, unsigned short int votosInvalidos) {
    char voto[6], decisao;
    int indice_candidato = 0;
    
   
    while (1) {
        telaUrna();
        if (cargo == 'E') {
            printf("- VOTE PARA DEPUTADO ESTADUAL: ");
        } else if (cargo == 'F') {
            printf("- VOTE PARA DEPUTADO FEDERAL: ");
        } else if (cargo == 'G') {
            printf("- VOTE PARA GOVERNADOR: ");
        } else if (cargo == 'P') {
            printf("- VOTE PARA PRESIDENTE: ");
        }
        scanf("%6[^\n]", voto);
        limpaBuffer();

        if (votoBranco(voto)) {
            telaVotoBranco();
            decisao = decisaoEleitor('c', 'C', 'R', 'r');
            if (decisao == 'C' || decisao == 'c') {
                votosInvalidos += 1;
                return votosInvalidos;
                break;
            } else continue; 
        } else {
            indice_candidato = buscaCandidato(voto, candidatos, totalCandidatos, cargo);
            if (indice_candidato != -1) {
                telaCandidato(candidatos[indice_candidato], totalPartidos, partidos);
                decisao = decisaoEleitor('c', 'C', 'R', 'r');
                if (decisao == 'c' || decisao == 'C') {
                    candidatos[indice_candidato].qtdVoto++;
                    return votosInvalidos;
                    break;
                } else continue;
            } else {
                telaVotoNulo();
                decisao = decisaoEleitor('c', 'C', 'R', 'r');
                if (decisao == 'c' || decisao == 'C') {
                    votosInvalidos += 1;
                    return votosInvalidos;
                    break;
                } else continue;
            }
        }
    }   
}
