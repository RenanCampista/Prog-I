#include <stdio.h>

int CodigoMes (int mes) {
    int cod_mes = 0;

    switch (mes) {
    case 1:
        cod_mes = 0;
        break;
    case 2:
        cod_mes = 3;
        break;
    case 3:
        cod_mes = 3;
        break;
    case 4:
        cod_mes = 6;
        break;
    case 5:
        cod_mes = 1;
        break;
    case 6:
        cod_mes = 4;
        break;
    case 7:
        cod_mes = 6;
        break;
    case 8:
        cod_mes = 2;
        break;
    case 9:
        cod_mes = 5;
        break;
    case 10:
        cod_mes = 0;
        break;
    case 11:
        cod_mes = 3;
        break;
    case 12:
        cod_mes = 5;
        break;    
    default:
        break;
    }
    return cod_mes;
}

int CodigoAno (int ano) {
    int cod_ano = 0, aa = 0;
    aa = ano % 100;
    cod_ano = aa + (aa / 4);
    cod_ano = cod_ano % 7;
    return cod_ano;
}

int CodigoSeculo (int ano) {
    int cod_sec = 0, sec = 0;
    sec = ano / 100;
    switch (sec) {
    case 17:
        cod_sec = 4;
        break;
    case 18:
        cod_sec = 2;
        break;
    case 19:
        cod_sec = 0;
        break;
    case 20:
        cod_sec = 6;
        break;
    case 21:
        cod_sec = 4;
        break;
    case 22:
        cod_sec = 2;
        break;
    case 23:
        cod_sec = 0;
        break;
    
    default:
        break;
    }
    return cod_sec;
}

int VerificaAnoBissexto (int ano) {
    if (ano % 4 == 0) {
        if (ano % 100 == 0 && ano % 400 == 0) {
            return 1;
        } else if (ano % 100 != 0 && ano % 400 == 0) {
            return 1;
        } else return 0;
    } else return 0;

}

int main() {
    int dia = 0, mes = 0, ano = 0;
    char caracter;

    int cod_mes = 0, cod_ano = 0, cod_sec = 0, dia_aux = 0, aux = 0;

    while (1) {
        scanf("%d-%d-%d", &dia, &mes, &ano);
        scanf("%c", &caracter);
        if (caracter == '!') {
            printf("\n");
            break;
        }
        if (aux > 0) {
            printf(", ");
        }
        cod_ano = CodigoAno(ano);
        cod_mes = CodigoMes(mes);
        cod_sec = CodigoSeculo(ano);

        dia_aux = cod_ano + cod_mes + cod_sec + dia;
        if (VerificaAnoBissexto(ano) == 1) {
            if (mes == 1 || mes == 2) {
                dia_aux = dia_aux - 1;
            }
        }
        dia_aux = dia_aux % 7;

        switch (dia_aux) {
        case 0:
            printf("DOMINGO");
            break;
        case 1:
            printf("SEGUNDA");
            break;
        case 2:
            printf("TERCA");
            break;
        case 3:
            printf("QUARTA");
            break;
        case 4:
            printf("QUINTA");
            break;
        case 5:
            printf("SEXTA");
            break;
        case 6:
            printf("SABADO");
            break;
        
        default:
            break;
        }

        aux++;

    }


    return 0;
}