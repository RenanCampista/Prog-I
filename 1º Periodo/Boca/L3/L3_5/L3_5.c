#include <stdio.h>

int Propriedade(int num) {
    int ab = 0, cb = 0, ef = 0, mult = 0;
    ab = num / 100;
    cb = num % 100;
    ef = ab + cb;
    mult = ef * ef;
    if (mult == num) {
        return 1;
    }else {
        return 0;
    }
}

int main() {
    int  m = 0, n = 0, i = 0;
    scanf("%d %d", &n, &m);
    if (n < m && 1000 < n && m < 9999) {
        for(i = n + 1; i < m; i++) {
            if (Propriedade(i) == 1) {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}