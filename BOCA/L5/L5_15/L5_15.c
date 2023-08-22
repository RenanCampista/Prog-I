#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato(){
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

void ImprimeCandidato(tCandidato candidato){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
    candidato.codigo, candidato.nome,
    candidato.sobrenome, candidato.nota, candidato.idade);
}

void OrdenaCrescente (tCandidato * vet, int qtd) {
    int i = 0, j = 0;
    tCandidato aux;

    for (i = 0; i < qtd - 1; i++) {
        aux = vet[i];
        for (j = i + 1; j < qtd; j++) {
            if (strcmp(vet[i].nome, vet[j].nome) > 0) {
                vet[i] = vet[j];
                vet[j] = aux;
                aux = vet[i];
            } else if (strcmp(vet[i].nome, vet[j].nome) == 0) {
                if (strcmp(vet[i].sobrenome, vet[j].sobrenome) > 0) {
                    vet[i] = vet[j];
                    vet[j] = aux;
                    aux = vet[i];
                }
            }
        }
    }
}

int main(){
    int qtdCand, i = 0, j;

    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand], *teste[qtdCand];

    for(i = 0; i < qtdCand; i++){
        candidatos[i] = LeCandidato();
    }

    OrdenaCrescente(candidatos, qtdCand);
    for(i = 0; i < qtdCand; i++){
        ImprimeCandidato(candidatos[i]);
    }
    return 0;
}
