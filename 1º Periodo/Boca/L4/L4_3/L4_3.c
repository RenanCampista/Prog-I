#include <stdio.h>

typedef struct Data {
    int dia, mes, ano;
} tData;

int EhBissexto (tData data) {
    if (data.ano % 4 == 0) {
        return 1;
    } else return 0;
}

int corrigeDia(tData data) {
    int dat = data.mes, dia = data.dia;
    if (dat == 4 || dat == 6 || dat == 9 || dat == 11) {
        //MESES COM 30 DIAS
        if (data.dia > 30) {
            dia = 30;
        }
    }else if ((dat == 1 || dat == 3 || dat == 5 || dat == 7 || dat == 8 || dat == 10 || dat == 12)) {
        //MESES COM 31 DIAS
        if (data.dia > 31) {
            dia = 31;
        }   
    } else if (dat == 2) {
        //FEVEREIRO
        if (EhBissexto(data) == 1) {
            if (data.dia > 29) {
                dia = 29;
            }
        } else if (EhBissexto(data) == 0) {
            if (data.dia > 28) {
                dia = 28;
            }
        }
    } 
    return dia;
}

int corrigeMes(tData data) {
    int mes = data.mes;
    if (mes > 12) {
        mes = 12; 
    } else if (mes < 1) {
        mes = 1;
    }
    return mes;
}

int main() {
    tData data;
    int mes = 0, dia = 0, ano = 0, quant_data = 0, i = 1;

    scanf("%d", &quant_data);

    while (i <= quant_data) {
        scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
        mes = corrigeMes(data);
        dia = corrigeDia(data);
        ano = data.ano;
        if (EhBissexto(data) == 1) {
            if (mes < 10 && dia > 10) {
                printf("'%d/0%d/%d':Bisexto\n", dia, mes, ano);
            } else if (mes > 10 && dia < 10) {
                printf("'0%d/%d/%d':Bisexto\n", dia, mes, ano);
            } else if (mes < 10 && dia < 10) {
                printf("'0%d/0%d/%d':Bisexto\n", dia, mes, ano);
            } else {
                printf("'%d/%d/%d':Bisexto\n", dia, mes, ano);
            }
        } else {
            if (mes < 10 && dia > 10) {
                printf("'%d/0%d/%d':Normal\n", dia, mes, ano);
            } else if (mes > 10 && dia < 10) {
                printf("'0%d/%d/%d':Normal\n", dia, mes, ano);
            } else if (mes < 10 && dia < 10) {
                printf("'0%d/0%d/%d':Normal\n", dia, mes, ano);
            } else {
                printf("'%d/%d/%d':Normal\n", dia, mes, ano);
            } 
        }
        i++;
    }
    return 0;
}