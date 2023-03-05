#include <stdio.h>

int main(){
    char frase = 'a';

    do{
        scanf("%c", &frase);
        if (frase >= 97 && frase <= 122){
            frase = frase - 32;
        }
        printf("%c", frase);
        if(frase == '.' || frase == '?' || frase == '!'){
            break;
        }
    } while (1);

    return 0;
}