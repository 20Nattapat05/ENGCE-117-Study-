#include <stdio.h>

#define R1 2
#define C1 3
#define R2 2
#define C2 3

// print matrix
void printMat(int r, int c, int m[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int A[R1][C1];
    int B[R2][C2];
    int C[R1][R2];   // result 2x2
    int i, j, k;

    // input A
    for (i = 0; i < R1; i++) {
        for (j = 0; j < C1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // input B
    for (i = 0; i < R2; i++) {
        for (j = 0; j < C2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // multiply A with B^T (no explicit transpose)
    for (i = 0; i < R1; i++) {
        for (j = 0; j < R2; j++) {
            C[i][j] = 0;
            for (k = 0; k < C1; k++) {
                C[i][j] += A[i][k] * B[j][k]; // row·row (B treated as BT)
            }
        }
    }

    printf("\nMatrix A:\n");
    printMat(R1, C1, A);

    printf("\nMatrix B:\n");
    printMat(R2, C2, B);

    printf("\nMatrix C = A * B^T:\n");
    printMat(R1, R2, C);

    return 0;
}
