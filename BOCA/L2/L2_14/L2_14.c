#include <stdio.h>

int main(){
    char frase[100];
    int i;
    fgets(frase, 100, stdin);
    printf("RESP:");
    for (i = 0; i <= 100; i++){
        if (frase[i] != ' '){
            printf("%c", frase[i]);
        }
        if (frase[i] == '.' || frase[i] == '?' || frase[i] == '!'){
            break;
        } 
    }
    return 0;
}