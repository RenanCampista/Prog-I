#include <stdio.h>
#define TRUE 1;
#define FALSE 0;

int EhPrimo(int num) {
    int primo = 0, i = 0;

    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            primo++;
        }
    }
    if (primo == 2) {
        return TRUE;
    }else {
        return FALSE;
    }
}

int main() {
    int n = 0, m = 0, i = 0;
    scanf("%d %d", &n, &m);
    for (i = n + 1; i < m; i++) {
        if (EhPrimo(i) == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}