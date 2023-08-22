#include <stdio.h>
#include <stdlib.h>

int ComparaString(char * str1, char * str2) {
    int tam1 = 0, aux = 0, tam2 = 0;
    
    while (*str1 != '\0') {
        tam1++;
        str1++;
    }
    str1 -= tam1;

    while (*str2 != '\0') {
        tam2++;
        str2++;
    }
    str2 -= tam2;

    while (*str1 != '\0') {
        if (*str1 == *str2) {
            aux++;
        }
        str1++;
        str2++;
    }

    if (tam1 == aux && tam1 == tam2) {
        return 1;
    } else return 0;
}

int main() {
    char str1[1000];
    char str2[1000];

    while ( scanf("%s", &str1) == 1 && scanf("%s", &str2) == 1){
        if ( ComparaString(str1, str2) )
            printf("IGUAL\n");
        else
            printf("DIFERENTE\n");
    }
    return 0;
}