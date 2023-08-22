#include <stdio.h>
#include <math.h>

int verificapH (float pH) {
    if (pH == 7.00) {
        return 0;
    } else if (pH < 7.00) {
        return 1;
    } else if (pH > 7.00) {
        return 2;
    }

}

int verificaGotaChuvaAcida (float pH) {
    if (pH < 5.7) {
        return 1;
    } else {
        return 0;
    }
}

float porcentagem (float total, float valor) {
    return (valor * 100) / total;
}

void imprimeResultadosAnalise (float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) {
    if(porcentagemGotasChuvaAcida > 75.00) {
        //chuva acida
        printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }else if(porcentagemGotasChuvaNormal > 75.00) {
        //chuva normal
        printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }else {
        printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
        
    }
}

int main() {
    int area = 0, dens = 0, temp = 0, quant_gotas = 0, i = 0, cont_acd = 0, cont_neut = 0, cont_bas = 0;
    float ph = 0, difer_ph = 0, mais_acd = 14.00, mais_bas = 0.00, mais_neut = 0, chuva_total = 0, chuva_acd = 0, chuva_norm = 0;
    //mais neutro menor valor de 7 - ph
    scanf("%d %d %d", &area, &dens, &temp);
    if ((area >= 0 && area<=50) && (dens >= 0 && dens <= 50) && (temp >= 0 && temp <= 12)) {
        quant_gotas = area * dens * temp;
        for (i = 1; i <= quant_gotas; i++){
            scanf("%f", &ph);

            if (ph >= 0.00 && ph <= 14.00) {
                difer_ph = fabs(ph - 7);
                if(ph > 6 && ph < 8 && difer_ph < ph - mais_neut) {
                    mais_neut = ph;
                }

                switch (verificapH(ph)) {
                case 0:
                    cont_neut += 1;
                    break;
                case 1:
                    cont_acd += 1;
                    break;
                case 2:
                    cont_bas += 1;
                default:
                    break;
                }

                switch (verificaGotaChuvaAcida(ph)) {
                case 0:
                    chuva_norm += 1;
                    break;
                case 1:
                    chuva_acd += 1;
                    break;
                default:
                    break;
                    }

                if (ph > mais_bas) {
                    mais_bas = ph;
                }
                if (ph < mais_acd) {
                    mais_acd = ph;
                }
            }
        }
        chuva_total = cont_acd + cont_bas + cont_neut;    
    }    
    if (chuva_total == 0) {
        printf("Nenhuma gota foi avaliada");
    } else {
        printf("%d %d %d %.2f %.2f %.2f\n", cont_acd, cont_bas, cont_neut, mais_acd, mais_bas, mais_neut);
        imprimeResultadosAnalise(porcentagem(chuva_total, chuva_acd), porcentagem(chuva_total, chuva_norm));
    }
    return 0;
}