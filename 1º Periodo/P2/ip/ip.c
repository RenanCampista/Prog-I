#include <stdio.h>

int Regra1 (char ip[]) {
    int i = 0;

    do {
        if (ip[i] != '.') {
            if (ip[i] < '0' || ip[i] > '9') {
                return 1;
            }
        }
        i++;
    } while (ip[i] != '\0');

    return 0;
}

int Regra2 (char ip[]) {
    int i = 0, num = 0;

    if (Regra1(ip) == 0){
        do {    
            if (ip[i] == '.' || ip[i] == '\0') {
                if (num > 255) {
                    return 1;
                }
                if (ip[i] == '\0') break;
                num = 0;
            } else {
                num = num * 10 + (ip[i] - '0');
            }

            i++;
        } while (1);
    }
    return 0;
}

int regra3 (char ip[]) {
    if (ip[0] == '0') return 1;
    return 0;
}

void TestaIp (char ip[]) {
    if (Regra1(ip) == 0 && Regra2(ip) == 0 &&regra3(ip) == 0) {
        printf("valido\n");
    } else printf("invalido\n");
}

int main() {
    int i = 0, qtd = 0;
    char ip[51];

    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++) {
        scanf("%s", ip);
        TestaIp(ip);
    }
    return 0;
}
