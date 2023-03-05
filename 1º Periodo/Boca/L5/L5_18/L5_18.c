#include <stdio.h>

int main() {
    int pares = 0, i1 = 0, j1 = 0, i2 = 0, j2 = 0, k = 0;
    int l1 = 0, c1 = 0, l2 = 0, c2 = 0, temp = 0;

    scanf("%d", &pares);
    for (k = 0; k < pares; k++) {
        scanf("%d %d", &c1, &l1);
        int mat1[l1][c1];
        for (i1 = 0; i1 < l1; i1++) {
            for (j1 = 0; j1 < c1; j1++) {
                scanf("%d ", &mat1[i1][j1]);
            }
        }

        scanf("%d %d", &c2, &l2);
        int mat2[l2][c2];
        for (i2 = 0; i2 < l2; i2++) {
            for (j2 = 0; j2 < c2; j2++) {
                scanf("%d ", &mat2[i2][j2]);
            }
        }

        if (c1 == l2) {
            int mat3[l1][c2];
            for (i1 = 0; i1 < l1; i1++) {
                for (j1 = 0; j1 < c2; j1++) {
                    temp = 0;
                    for (i2 = 0; i2 < c1; i2++) {
                        temp = temp + mat1[i1][i2] * mat2[i2][j1];
                    }
                    mat3[i1][j1] = temp;
                    printf("%d", mat3[i1][j1]);
                    if (j1 != c2 - 1) printf(" ");
                }
                printf("\n");
            }
        } else printf("IMPOSSIVEL\n");
        printf("\n");

    }


    return 0;
}