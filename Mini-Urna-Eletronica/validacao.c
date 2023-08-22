#include "validacao.h"


void validaCandidato (tCandidato candidatos[], unsigned short int totalCandidatos, tPartido partidos[], unsigned short int totalPartidos) {
    unsigned short int i = 0, j = 0, aux = 0;

    for (i = 0; i <= totalCandidatos; i++) {
        aux = 0;

        //VERIFICAR SE O CARGO EXISTE
        if (candidatos[i].cargo == 'P' || candidatos[i].cargo == 'G' || candidatos[i].cargo == 'F' || candidatos[i].cargo == 'E') {
            aux++;
        }

        for (j = 0; j <= totalPartidos; j++) {
            //VERIFICAR SE O PARTIDO DO CANDIDATO EXISTE
            if (strcmp(candidatos[i].partido, partidos[j].sigla) == 0) {
                aux++;
                
                switch (candidatos[i].cargo) {
                    case 'P':
                        if (strcmp(candidatos[i].numero, partidos[j].numero) == 0){
                            aux++;
                        }
                        if (atoi(candidatos[i].numero) >= 10 && atoi(candidatos[i].numero) <= 99) {
                            aux++;
                        }
                        break;
                    case 'G':
                        if (strcmp(candidatos[i].numero, partidos[j].numero) == 0){
                            aux++;
                        }
                        if (atoi(candidatos[i].numero) >= 10 && atoi(candidatos[i].numero) <= 99) {
                            aux++;
                        }
                        break;
                    case 'F':
                        if (atoi(candidatos[i].numero) >= 1000 && atoi(candidatos[i].numero) <= 9999) {
                            aux++;
                        }

                        if (atoi(candidatos[i].numero) / 100 == atoi(partidos[j].numero)) {
                            aux++;
                        }
                        break;
                    case 'E':
                        if (atoi(candidatos[i].numero) >= 10000 && atoi(candidatos[i].numero) <= 99999) {
                            aux++;
                        }

                        if (atoi(candidatos[i].numero) / 1000 == atoi(partidos[j].numero)) {
                            aux++;
                        }                       
                        break;
                    default:
                        break;
                }
            }
        }


        //SERA APTO SE PASSAR NOS 4 TESTES
        if (aux == 4) {
            candidatos[i].apto = 1;
        } else candidatos[i].apto = 0;
    }
}

int validaID (tEleitor eleitores[], unsigned short int totalEleitores) {
    char busca_id[7];
    short int indice = -1, i = 0;

    scanf("%7[^\n]", busca_id);
    limpaBuffer();

    //VERIFICAR SE O ID ESTA NA STRUCT E SE JA VOTOU
    for (i = 0; i < totalEleitores; i++) {
        if (strcmp(busca_id, eleitores[i].id) == 0) {
            indice = i;
        }
    }
    if (indice != -1 && eleitores[indice].votou == 0) {
        return indice;
    } else return -1;
}
