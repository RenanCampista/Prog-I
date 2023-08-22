#include <stdio.h>

int main(){
    int n, cont = 0, maior = 0;
    float media;
    while (n > 0){
        scanf("%d", &n);
        cont += 1;  
        media += n;
        if (n > maior){
            maior = n;
        }
        if (n == 0){
            break;
        }
        printf("%d %.6f\n", maior, media/cont);
    }
    return 0;
}