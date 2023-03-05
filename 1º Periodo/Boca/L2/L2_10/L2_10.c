#include <stdio.h>

int main()
{
    int inicio, fim, i, j;

    scanf("%d%d", &inicio, &fim);

    for (i = inicio; i <= fim; i++){
        for (j = 1; j <= 10; j++){
            printf("%d x %d = %d\n", i, j, j * i);
        }
    }
    return 0;
}