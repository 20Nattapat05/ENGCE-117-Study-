#include <stdio.h>

#define N 3   // matrix size

int main(void) {
    int a[N][N];

    // read elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // print matrix
    printf("\n=== MATRIX OUTPUT ===\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
