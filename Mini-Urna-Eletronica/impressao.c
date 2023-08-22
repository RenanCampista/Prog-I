#include "impressao.h"


void imprimeBoletim (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, tEleitor eleitores[], unsigned short int totalEleitores, unsigned short int votosInvalidos[]) {
    unsigned short int i = 0, eleitPresentes = 0;
    eleitPresentes = eleitoresPresentes(eleitores, totalEleitores);
    fprintf(file, "CANDIDATO,PARTIDO,VOTOS\n");
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'P' && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d (%.2f%%)\n", candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, 
                calculaPorcentagem(candidatos[i].qtdVoto, totalVotosValidos('P', candidatos, totalCandidatos) + 
                votosInvalidos[3]));
        }
    }
    fprintf(file, "BRANCOS E NULOS,-,%d (%.2f%%)\n", votosInvalidos[3], 
        calculaPorcentagem(votosInvalidos[3], totalVotosValidos('P', candidatos, totalCandidatos) + 
        votosInvalidos[3]));
    fprintf(file, "-,-,-\n");

    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'G' && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d (%.2f%%)\n", candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, 
                calculaPorcentagem(candidatos[i].qtdVoto, totalVotosValidos('G', candidatos, totalCandidatos) + 
                votosInvalidos[2]));
        }
    }
    fprintf(file, "BRANCOS E NULOS,-,%d (%.2f%%)\n", votosInvalidos[2], 
        calculaPorcentagem(votosInvalidos[2], totalVotosValidos('G', candidatos, totalCandidatos) + 
        votosInvalidos[2]));
    fprintf(file, "-,-,-\n");

    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'F' && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d (%.2f%%)\n", candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, 
            calculaPorcentagem(candidatos[i].qtdVoto, totalVotosValidos('F', candidatos, totalCandidatos) + 
            votosInvalidos[1]));
        }
    }
    fprintf(file, "BRANCOS E NULOS,-,%d (%.2f%%)\n",  votosInvalidos[1], 
        calculaPorcentagem(votosInvalidos[1], totalVotosValidos('F', candidatos, totalCandidatos) + 
        votosInvalidos[1]));
    fprintf(file, "-,-,-\n");

    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'E' && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d (%.2f%%)\n", candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, 
                calculaPorcentagem(candidatos[i].qtdVoto, totalVotosValidos('E', candidatos, totalCandidatos) + 
                votosInvalidos[0]));
        }
    }
    fprintf(file, "BRANCOS E NULOS,-,%d (%.2f%%)\n", votosInvalidos[0], 
        calculaPorcentagem(votosInvalidos[0], totalVotosValidos('E', candidatos, totalCandidatos) + 
        votosInvalidos[0]));
    fprintf(file, "-,-,-\n");

    fprintf(file, "TOTAL DE ELEITORES,-,%d (100.0%%)\n", totalEleitores);
    fprintf(file, "ELEITORES PRESENTES,-,%d (%.2f%%)\n", eleitPresentes, 
        calculaPorcentagem(eleitPresentes, totalEleitores));
    fprintf(file, "ELEITORES AUSENTES,-,%d (%.2f%%)\n", totalEleitores - eleitPresentes, 
        calculaPorcentagem(totalEleitores -  eleitPresentes, totalEleitores));
    fclose(file);
}

void imprimeBancada (FILE *file, tPartido partidos[], unsigned short int totalPartidos, int distrVagas[]) {
    unsigned short int i = 0;

    fprintf(file, "Partido,Eleitos\n");
    for (i = 0; i < totalPartidos; i++) {
        fprintf(file, "%s,%d\n", partidos[i].sigla, distrVagas[i]);
    }
    fclose(file);
}

void imprimeEleitos (FILE *file, tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE) {
    unsigned int i = 0, total = 0;
    total = totalEleitosDF + totalEleitosDE + VAGASEXECUTIVO;
    fprintf(file, "CARGO,NOME,PARTIDO\n");
    for (i = 0; i < total; i++) {
        fprintf(file, "%s,%s,%s\n", eleitos[i].cargo, eleitos[i].nome, eleitos[i].partido);
    }
    fclose(file);
}

void imprimeRankPres (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos) {
    unsigned short int i = 0;
    fprintf(file, "NOME,PARTIDO,VOTOS,PERCENTUAL\n");
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'P' && candidatos[i].qtdVoto > 0 && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d,%.2f%%\n",candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, calculaPorcentagem(candidatos[i].qtdVoto, votosValidos));
        }
    }
    fclose(file);
}

void imprimeRankGov (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos) {
    unsigned short int i = 0;
    fprintf(file, "NOME,PARTIDO,VOTOS,PERCENTUAL\n");
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'G' && candidatos[i].qtdVoto > 0 && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d,%.2f%%\n",candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, calculaPorcentagem(candidatos[i].qtdVoto, votosValidos));
        }
    }
    fclose(file);
}

void imprimeRankDF (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos) {
    unsigned short int i = 0;
    fprintf(file, "NOME,PARTIDO,VOTOS,PERCENTUAL\n");
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'F' && candidatos[i].qtdVoto > 0 && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d,%.2f%%\n",candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, calculaPorcentagem(candidatos[i].qtdVoto, votosValidos));
        }
    }
    fclose(file);
}

void imprimeRankDE (FILE *file, tCandidato candidatos[], unsigned short int totalCandidatos, unsigned short int votosValidos) {
    unsigned short int i = 0;
    fprintf(file, "NOME,PARTIDO,VOTOS,PERCENTUAL\n");
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'E' && candidatos[i].qtdVoto > 0 && candidatos[i].apto == 1) {
            fprintf(file, "%s,%s,%d,%.2f%%\n",candidatos[i].nome, candidatos[i].partido, candidatos[i].qtdVoto, calculaPorcentagem(candidatos[i].qtdVoto, votosValidos));
        }
    }
    fclose(file);
}

void imprimeGenerLeg (FILE *file, tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE) {
    int genero_M[0], genero_F[0], genero_O[0];
    genero_M[0] = genero_F[0] = genero_O[0] = 0;
    generoLegislativo(eleitos, genero_M, genero_F, genero_O);
    
    fprintf(file, "GENERO,PERCENTUAL\n");
    fprintf(file, "M,%.f%%\n", calculaPorcentagem(genero_M[0], totalEleitosDE + totalEleitosDF));
    fprintf(file, "F,%.f%%\n", calculaPorcentagem(genero_F[0], totalEleitosDE + totalEleitosDF));
    fprintf(file, "O,%.f%%\n", calculaPorcentagem(genero_O[0], totalEleitosDE + totalEleitosDF));
    fclose(file);
}

void imprimeMediaIdade (FILE *file, tNomeados eleitos[], unsigned short int totalEleitosDF, unsigned short int totalEleitosDE) {
    float media_DF[0], media_DE[0], media_G[0], media_P[0];
    media_DF[0] = media_DE[0] = media_G[0] = media_P[0] = 0;
    mediaIdadeCargos(eleitos, media_P, media_G, media_DF, media_DE, totalEleitosDF, totalEleitosDE);

    fprintf(file, "CARGO,MEDIA\n");
    fprintf(file, "DEPUTADO ESTADUAL,%.2f\n", media_DE[0]);
    fprintf(file, "DEPUTADO FEDERAL,%.2f\n", media_DF[0]);
    fprintf(file, "GOVERNADOR,%.2f\n", media_G[0]);
    fprintf(file, "PRESIDENTE,%.2f\n", media_P[0]);
    fclose(file);
}
