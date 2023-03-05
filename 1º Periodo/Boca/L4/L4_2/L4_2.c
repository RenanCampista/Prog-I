#include <stdio.h>

typedef struct Data {
    int dat, mes, ano;    
} tData;

tData data1 = {0, 0, 0}, data2 = {0, 0, 0};

int verificaMes (int dat) {
    if (dat == 4 || dat == 6 || dat == 9 || dat == 11) {
        //MESES COM 30 DIAS
        return 2;
    }else if ((dat == 1 || dat == 3 || dat == 5 || dat == 7 || dat == 8 || dat == 10 || dat == 12)) {
        //MESES COM 31 DIAS
        return 1;
    } else if (dat == 2) {
        return 0;
    } //FEVEREIRO
}

int totalDias (tData data) {
    int i = 1, total_dias = 0;

    while (1) {
        if (i == data.mes) {
            total_dias = total_dias + data.dat;
            return total_dias;
            break;
        }
        if (verificaMes(i) == 1) {
            total_dias = total_dias + 31;
        } else  if (verificaMes(i) == 2) {
            total_dias = total_dias +  30;
        } else if ((verificaMes(i) == 0)){
            if (data.ano % 4 == 0) {
                //ANO BISSEXTO
                total_dias = total_dias + 29;
            } else {
                total_dias = total_dias + 28;
            }
        }
        i++;
    }     
}

int corrigeDia (tData data) {
    int mes = 0, dia = 0;
    mes = data.mes;
    dia = data.dat;

    if (verificaMes(mes) == 1) {
        if (data.dat > 31) {
            return 31;
        } else {
            return dia;
        }
    } else if (verificaMes(mes) == 2) {
        if (data.dat > 30) {
            return 30;
        } else {
            return dia;
        }
    } else if (verificaMes(mes) == 0) {
        if (data.ano % 4 == 0)  {
            if (data.dat > 29) {
                return 29;
            } else {
            return dia;
            }
        } else {
            if (data.dat > 28) {
                return 28;
            } else {
            return dia;
            }
        }
    }
}

int corrigeMes (tData data) {
    int mes = 0;
    mes = data.mes;
    if (mes > 12) {
        return 12;
    } else {
        return mes;
    }
}

void imprimeData (tData data_inicial, tData data_final) {
    int quant_dia1 = 0, quant_dia2 = 0, loop = 0, i = 1, mes1 = 0, mes2 = 0;
    quant_dia1 = totalDias(data_inicial);
    quant_dia2 = totalDias(data_final);

    mes1 = data_inicial.mes;
    mes2 = data_final.mes;

    if (quant_dia1 > quant_dia2) {
        if (data_inicial.ano % 4 == 0 || data_final.ano % 4 == 0) {
            loop = (quant_dia2 + 366) - quant_dia1;
        } else {
            loop = (quant_dia2 + 365) - quant_dia1;
        }
    } else {
        loop = quant_dia2 - quant_dia1;
    }

    for (i = 1; i <= loop; i++) {
        if (verificaMes(mes1) == 1) {
            if (data_inicial.dat > 31) {
                if (data_inicial.mes == 12) {
                    data_inicial.mes = 1;
                    mes1 = data_inicial.mes;
                    data_inicial.ano++;
                } else {
                    data_inicial.mes++;
                    mes1 = data_inicial.mes;
                }
                data_inicial.dat = 1;
            }
        } else if (verificaMes(mes1) == 2) {
            if (data_inicial.dat > 30) {
                data_inicial.dat = 1;
                data_inicial.mes++;
                mes1 = data_inicial.mes;
            }
        } else if (verificaMes(mes1) == 0) {
            if (data_inicial.dat > 28) {
                data_inicial.dat = 1;
                data_inicial.mes++;
                mes1 = data_inicial.mes;
            }
        }
        if (data_inicial.dat >= 10 && data_inicial.mes >= 10) {
            printf("'%d/%d/%d'\n", data_inicial.dat, data_inicial.mes, data_inicial.ano);
        } else if (data_inicial.dat < 10 && data_inicial.mes >= 10) {
            printf("'0%d/%d/%d'\n", data_inicial.dat, data_inicial.mes, data_inicial.ano);
        } else if (data_inicial.dat >= 10 && data_inicial.mes < 10) {
            printf("'%d/0%d/%d'\n", data_inicial.dat, data_inicial.mes, data_inicial.ano);
        } else if ((data_inicial.dat < 10 && data_inicial.mes < 10)) {
            printf("'0%d/0%d/%d'\n", data_inicial.dat, data_inicial.mes, data_inicial.ano);
        }
        data_inicial.dat++;
    }

}

int main () {
    int quant_dia1 = 0, quant_dia2 = 0, i = 1, j = 1, loop = 0, mes1 = 0, mes2 = 0;

    scanf("%d %d %d", &data1.dat, &data1.mes, &data1.ano);
    scanf("%d %d %d", &data2.dat, &data2.mes, &data2.ano);

    data1.dat = corrigeDia(data1);
    data1.mes = corrigeMes(data1);
    data2.dat = corrigeDia(data2);
    data2.mes = corrigeMes(data2);

    imprimeData(data1, data2);
    return 0;
}