#include "leitura.h"

int lePartido (FILE *file, tPartido partidos[]) {
    unsigned short int i = 0;
    fscanf(file, "Partido,Sigla,Numero\n");

    while(!feof(file)) {
        fscanf (file, "%60[^,],%5[^,],%3[^\n]\n",
        partidos[i].nome, partidos[i].sigla, partidos[i].numero); 
        partidos[i].votosDF = 0;
        partidos[i].votosDE = 0;
        partidos[i].mediaIdadeDE = 0;
        partidos[i].mediaIdadeDF = 0;
        partidos[i].naoHomensDE = 0;
        partidos[i].naoHomensDF = 0;
        partidos[i].votosDE = 0;
        partidos[i].votosDF = 0;
        partidos[i].porcentagemVotosDE = 0;
        partidos[i].porcentagemVotosDF = 0;
        partidos[i].totalCandidatosDE = 0;
        partidos[i].totalCandidatosDF = 0;
       i++;
    }
    fclose(file);
    return i;
}

int leCandidato (FILE *file, tCandidato candidatos[]) {
    unsigned short int i = 0;
    fscanf(file, "Nome,Genero,Idade,Cargo,Numero,Partido\n");

    while (!feof(file)) {
        fscanf(file, "%60[^,],%c,%hd,%c,%6[^,],%5[^\n]\n", candidatos[i].nome, 
        &candidatos[i].genero, &candidatos[i].idade, &candidatos[i].cargo, 
        candidatos[i].numero, candidatos[i].partido);
        candidatos[i].qtdVoto = 0;    
        candidatos[i].apto = 0;   
        i++;
    }
    fclose(file);
    return i;
}

int leEleitor (FILE *file, tEleitor eleitores[]) {
    unsigned short int i = 0;
    fscanf(file, "Nome,Identificador\n");
    
    while(!feof(file)) {
        fscanf(file, "%60[^,],%6[^\n]\n", eleitores[i].nomeCompleto, eleitores[i].id);
        eleitores[i].votou = 0;
        i++;
    }
    fclose(file);
    return i;
}

void limpaBuffer() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}