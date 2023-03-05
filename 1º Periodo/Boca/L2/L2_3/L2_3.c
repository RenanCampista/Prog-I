#include <stdio.h>

int main(){
    int quantidade, n, i, par = 0, impar = 0, maior = 0, menor = 9999;
    float media;
    scanf("%d", &quantidade);
    for (i = 1; i <= quantidade; i++){
        scanf("%d", &n);
        if (n % 2 == 0){
            par += 1;
        }else{
            impar += 1;
        }
        media += n;
        if(n > maior){
            maior = n;
        } if(n < menor){
            menor = n;
        }
    }
    media = media / quantidade;
    printf("%d %d %d %d %.6f", maior, menor, par, impar, media);
    return 0;
}