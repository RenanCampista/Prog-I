#include <stdio.h>
#include <math.h>

int main(){
    int n, k = 1;
    float pi;
    scanf("%d", &n);
    for (k = 1; k <= n; k++){
       pi += 6/pow(k, 2);  
    }
    pi = sqrt(pi);
    printf("%.6f", pi);
    return 0;
}