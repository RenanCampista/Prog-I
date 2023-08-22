#include <stdio.h>

int main(){
    int n, interesse;
    scanf("%d%d", &n, &interesse);
    if(interesse == 1){
        if((n % 10) % 2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }else if(interesse == 2){
        if(((n % 100) / 10) % 2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }else{
        if((n / 100) % 2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }
    return 0;
}