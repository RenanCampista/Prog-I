#include <stdio.h>

int main(){
    int m, n;
    scanf("%d%d", &n, &m);
    printf("RESP:");
    while (m > n){
        n++;
        if (n < m && n % 2 == 0){
            printf("%d ", n);
        }
    }
    return 0;
}