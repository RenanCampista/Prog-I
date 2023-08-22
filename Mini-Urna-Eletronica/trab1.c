#include <stdio.h>
#include "leitura.h"
#include "apuracao.h"
#include "votacao.h"
#include "validacao.h"
#include "ordenacao.h"
#include "relatorios.h"
#include "layout.h"
#include "impressao.h"
#include "constantes.h"

int main(int argc, char *argv[]) {
    tPartido partidos[PARTIDOS];
    tCandidato candidatos[CANDIDATOS];
    tEleitor eleitores[ELEITORES];
    tNomeados eleitos[ELEITOS];
    FILE *file;
    unsigned short int i = 0, j = 0, k = 0, totalCandidatos = 0, totalPartidos = 0, totalEleitores = 0;
    unsigned short int votosInvalidosDE = 0, votosInvalidosDF = 0, votosInvalidosGov = 0, votosInvalidosPres = 0, armazenaVotosInvalidos[4];
    unsigned short int totalEleitosDE = 0, totalEleitosDF = 0;
    char caminho[200];

    if (argc < 3) {
        printf("NECESSARIO INFORMAR O CAMINHO DE ENTRADA E SAIDA EXISTENTES ATRAVES DA LINHA DE COMANDO\n");
        return 1;
    }

    //LEITURA DOS ARQUIVOS
    sprintf(caminho, "%s/partidos.csv", argv[1]);
    file = fopen(caminho, "r");
    totalPartidos = lePartido(file, partidos);
    
    sprintf(caminho, "%s/candidatos.csv", argv[1]);
    file = fopen(caminho, "r");
    totalCandidatos = leCandidato(file, candidatos);
    
    sprintf(caminho, "%s/eleitores.csv", argv[1]);
    file = fopen(caminho, "r");
    totalEleitores = leEleitor(file, eleitores);

    //VALIDAR OS CANDIDATOS
    validaCandidato(candidatos, totalCandidatos, partidos, totalPartidos);

    //CALCULANDO QUANTIDADE DE NAO HOMENS DE CADA PARTIDO NOS CARGOS DE E DF
    qtdNaoHomens(partidos, totalPartidos, candidatos, totalCandidatos);

    //CALCULAR TOTAL DE CANDIDADOS DE CADA PARTIDO PARA CALCULAR A MEIDA EM SEGUIDA (REFERENTE A DF E DE)
    canditadosPorPartido(partidos, totalPartidos, candidatos, totalCandidatos);
    mediaIdPartido(partidos, totalPartidos, candidatos, totalCandidatos);

    //NOME DOS CANDIDATOS e PARTIDOS PARA MAIUSCULO
    upperCandidato(candidatos, totalCandidatos);
    upperPartido(partidos, totalPartidos);
    
    //PROCESSO DE VOTACAO 
    char decisao;
    short int indice = -1;
    unsigned short int votosValidosPres = 0, votosValidosGov = 0, votosValidosDF = 0, votosValidosDE = 0;
    while (1) {
        telaInicial();
        while (1) {
            indice = validaID(eleitores, totalEleitores);
            if (indice != -1) {
                break;
            } 
            printf("- Por favor, digite um ID valido: ");
        }

        //DEPUTADO ESTADUAL
        votosInvalidosDE = votacao('E', candidatos, totalCandidatos, partidos, totalPartidos, votosInvalidosDE);

        //DEPUTADO FEDERAL
        votosInvalidosDF = votacao('F', candidatos, totalCandidatos, partidos, totalPartidos, votosInvalidosDF);

        //GOVERNADOR
        votosInvalidosGov = votacao('G', candidatos, totalCandidatos, partidos, totalPartidos, votosInvalidosGov);

        //PRESIDENTE
        votosInvalidosPres = votacao('P', candidatos, totalCandidatos, partidos, totalPartidos, votosInvalidosPres);
        
        eleitores[indice].votou = 1;
        telaFinal();
        decisao = decisaoEleitor('f', 'F', 'N', 'n');
        if (decisao == 'f' || decisao == 'F') {
            printf("\n- VOTACAO ENCERRADA\n");
            break;
        }
        system("clear||cls");
    }

    //ARMAZENAR OS VOTOS INVALIDOS EM UM VETOR PARA PASSAR MENOS PARAMETROS NA FUNCAO IMPRIME BOLETIM
    armazenaVotosInvalidos[0] = votosInvalidosDE;
    armazenaVotosInvalidos[1] = votosInvalidosDF;
    armazenaVotosInvalidos[2] = votosInvalidosGov;
    armazenaVotosInvalidos[3] = votosInvalidosPres;


    //CALCULANDO A QUANTIDADE DE VOTOS VALIDOS DE CADA CARGO
    votosValidosDE = totalVotosValidos('E', candidatos, totalCandidatos);
    votosValidosDF = totalVotosValidos('F', candidatos, totalCandidatos);
    votosValidosGov = totalVotosValidos('G', candidatos, totalCandidatos);
    votosValidosPres = totalVotosValidos('P', candidatos, totalCandidatos);

    //BOLETIM
    sprintf(caminho, "%s/boletim.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeBoletim(file, candidatos, totalCandidatos, eleitores, totalEleitores, armazenaVotosInvalidos);

    //ORDENANDO CANDIDATOS PARA OS RANKINGS
    ordenaCandidatos(candidatos, totalCandidatos);

    //RANKING PRESIDENTE
    sprintf(caminho, "%s/ranking_presidente.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeRankPres(file, candidatos, totalCandidatos, votosValidosPres);

    //RANKING GOVERNADOR
    sprintf(caminho, "%s/ranking_governador.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeRankGov(file, candidatos, totalCandidatos, votosValidosGov);

    //RANKING DEP FED
    sprintf(caminho, "%s/ranking_deputado_federal.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeRankDF(file, candidatos, totalCandidatos, votosValidosDF);

    //RANKING DEP EST
    sprintf(caminho, "%s/ranking_deputado_estadual.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeRankDE(file, candidatos, totalCandidatos, votosValidosDE);

    //DEFININDO QUEM SERA O PRESIDENTE e GOVERNADOR
    eLegePresidente(candidatos, totalCandidatos, eleitos);
    elegeGovernador(candidatos, totalCandidatos, eleitos);

    //CONTABILIZANDO A QUANTIDADE QUE CADA PARTIDO RECEBEU DE VOTOS 
    votosPorPartido(partidos, totalPartidos, candidatos, totalCandidatos);

    //CALCULAR A PORCETAGEM DE VOTOS DE CADA PARTIDO REFERENTE A DE E DF
    porcentagemVotosPartido(partidos, totalPartidos, votosValidosDF, votosValidosDE);
    
    //DESCOBRIR A QUANTIDADE DE DEPUTADOS F e E
    unsigned short int totalDE = 0, totalDF = 0;
    totalDE = totalCandDE(candidatos, totalCandidatos);
    totalDF = totalCadDF(candidatos, totalCandidatos);

    //ARMAZENAR OS DEPUTADOS COM VOTOS EM UMA STRUCT
    tCandidato depEst[totalDE], depFed[totalDF];
    j = 0, k = 0;
    for (i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].cargo == 'F' && candidatos[i].qtdVoto > 0 && candidatos[i].apto == 1) {
            depFed[j] = candidatos[i];
            j++;
        }else if (candidatos[i].cargo == 'E' && candidatos[i].qtdVoto > 0 && candidatos[i].apto == 1) {
            depEst[k] = candidatos[i];
            k++;
        }
    }

    //ORDENAR AS DUAS STRUCTS POR QUANTIDADE DE VOTOS
    ordenaCandidatos(depEst, totalDE);
    ordenaCandidatos(depFed, totalDF);

    //DISTRIBUICAO DE VAGAS DO LEGISLATIVO
    //ORGANIZAR OS PARTIDOS POR ORDEM DE MAIS VOTADOS DF
    ordenaPartidos(partidos, totalPartidos, 'F');

    //DEFININDO AS VAGAS DF    
    int distrVagasDF[totalPartidos]; 
    defineVagasDF(partidos, totalPartidos, distrVagasDF);
    totalEleitosDF = calculaTotalEleitosLegislativo(totalPartidos, distrVagasDF);

    //BANCADA DF
    sprintf(caminho, "%s/bancada_deputado_federal.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeBancada(file, partidos, totalPartidos, distrVagasDF);

    //REGISTRANDO DF ELEITOS
    elegeDepFederal(partidos, totalPartidos, depFed, totalDF, distrVagasDF, eleitos);
    
    //ORGANIZAR OS PARTIDOS POR ORDEM DE MAIS VOTADOS DE
    ordenaPartidos(partidos, totalPartidos, 'E');
    
    //DEFININDO AS VAGAS DE
    int distrVagasDE[totalPartidos];
    defineVagasDE(partidos, totalPartidos, distrVagasDE);
    totalEleitosDE = calculaTotalEleitosLegislativo(totalPartidos, distrVagasDE);

    //BANCADA DE
    sprintf(caminho, "%s/bancada_deputado_estadual.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeBancada(file, partidos, totalPartidos, distrVagasDE);

    //REGISTRANDO DE ELEITOS
    //--- NESSE CASO EH PRECISO SABER O TOTAL DE ELEITOS DF PARA QUE NA HORA DE GERAR O RELATORIO NAO TENHA LINHAS EM BRANCO
    elegeDepEstadual(partidos, totalPartidos, depEst, totalDE, distrVagasDE, eleitos, totalEleitosDF);

    //ORDENANDO ELEITOS
    ordenaEleitos(eleitos, totalEleitosDF, totalEleitosDE);

    //GERANDO ARQUIVO ELEITOS
    sprintf(caminho, "%s/eleitos.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeEleitos(file, eleitos, totalEleitosDF, totalEleitosDE);

    //MEDIA DE IDADE POR CARGO
    sprintf(caminho, "%s/media_idade.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeMediaIdade(file, eleitos, totalEleitosDF, totalEleitosDE);

    //GENERO LEGISLATIVO
    sprintf(caminho, "%s/genero_legislativo.csv", argv[2]);
    file = fopen(caminho, "w");
    imprimeGenerLeg(file, eleitos,totalEleitosDF, totalEleitosDE);

    return 0;
}
