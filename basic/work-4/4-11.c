#include <stdio.h>

#define R 2   // rows
#define C 4   // columns

int main(void) {
    int a[R][C];
    int total = 0;

    // read matrix
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // print matrix and accumulate sum
    printf("\n=== MATRIX DATA ===\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%4d", a[i][j]);
            total += a[i][j];
        }
        printf("\n");
    }

    // final sum
    printf("\nTotal sum: %d\n", total);

    return 0;
}
