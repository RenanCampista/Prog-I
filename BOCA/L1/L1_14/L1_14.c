#include <stdio.h>

int main(){
    int x1, x2, x3, y1, y2, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    if(x3 > x1 && x3 > x2 || x3 < x1 && x3 < x2){
        printf("Fora");
    }else if(y3 > y1 && y3 > y2 || y3 < y1 && y3 < y2){
        printf("Fora");
    }else{
        printf("Dentro");
    }
    return 0;
}