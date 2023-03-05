#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato() {
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void ImprimeCandidato (tCandidato candidato) {
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}

int TamanhoString (char * str) {
    int tam = 0;
    
    while (*str != '\0') {
        tam++;
        str++;
    }
    str -= tam;
    return tam;
}

int ComparaString(char * str1, char * str2) {
    int aux = 0, tam = 0;

    if (TamanhoString(str1) == TamanhoString(str2)) {
        while (*str1 != '\0') {
            tam++;
            if (*str1 == *str2) {
                aux++;
            }
            str1++;
            str2++;
        }
        if (tam == aux) {
            return 1;
        } else return 0;
    } else return 0;
}

int main(){
    int qtdCand, i = 0, j = 0, aux = 0, k = 0, l = 0;

    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand], cand_lidos[qtdCand];

    for(i = 0; i < qtdCand; i++){
        candidatos[i] = LeCandidato();
    }

    for (i = 0; i < qtdCand - 1; i++) {
        for (j = i + 1; j < qtdCand; j++) {
            if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome)){
                for (k = 0; k < l; k++) {
                    if (candidatos[i].codigo == cand_lidos[k].codigo) {
                        aux = 1;
                    }
                }

                if (aux == 0) {
                    ImprimeCandidato(candidatos[i]);
                }

                aux = 0;
                for (k = 0; k < l; k++) {
                    if (candidatos[j].codigo == cand_lidos[k].codigo) {
                        aux = 1;
                    }
                }

                if (aux == 0) {
                    ImprimeCandidato(candidatos[j]);
                }
                aux = 0;
                cand_lidos[l] = candidatos[j];
                l++;
                cand_lidos[l] = candidatos[i];
                l++;
            }  
        }
    }
    return 0;
}
