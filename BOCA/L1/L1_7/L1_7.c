#include <stdio.h>

int main(){
    float t;
    char u;
    scanf("%f %c", &t, &u);
    if(u == 'c' || u == 'C'){
        printf("%.2f (F)", (t * 9/5) + 32);
    }else if (u == 'f' || u == 'F'){
        printf("%.2f (C)", (t - 32) * 5/9);
    }
    return 0;
}