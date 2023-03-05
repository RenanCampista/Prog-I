#include <stdio.h>

int main(){
    int pessoas, itens;
    scanf("%d%d", &pessoas, &itens);
    if(itens % pessoas == 0){
        printf("RESP:%d", pessoas);
    }else{
        printf("RESP:%d", itens % pessoas);
    }
    return 0;
}