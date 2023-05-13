#include <stdio.h>
#include <stdlib.h>

int main() {
    char string[10];
    int num;

    scanf("%d", &num);
    itoa(num, string, 2);

    printf("%s\n", string);
    return 0;
}