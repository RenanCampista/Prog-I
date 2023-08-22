#include <stdio.h>

int main(){
    int m, n;
    scanf("%d%d", &n, &m);
    while (m > n){
        n++;
        if (n < m){
        if (n % 3 == 0 || n % 4 == 0 || n % 7 == 0){
            printf("%d ", n);
        }
        }
    }
    return 0;
}