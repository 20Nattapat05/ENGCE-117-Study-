#include <stdio.h>

// add 10 via pointer
void plusTen(int *p);

int main(void) {
    int x;

    printf("Enter an integer: ");
    if (scanf("%d", &x) != 1)
        return 1;

    printf("\n=== POINTER DEMO ===\n");
    printf("Before : %d\n", x);

    // pass address
    plusTen(&x);

    printf("After  : %d\n", x);

    return 0;
}

void plusTen(int *p) {
    *p += 10;   // modify caller variable
}
