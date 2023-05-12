#include <stdio.h>

int main(){
    float n1, n2, media;
    scanf("%f%f", &n1, &n2);
    media = (n1 + n2) / 2;
    if(media >= 7){
        printf("%.1f - Aprovado", media);
    }else if(media >= 5 && media < 7){
        printf("%.1f - De Recuperacao", media);
    }else{
        printf("%.1f - Reprovado", media);
    }
    return 0;
}