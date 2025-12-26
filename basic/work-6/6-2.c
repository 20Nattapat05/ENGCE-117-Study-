#include <stdio.h>

// swap two integers by pointer
void swap(int *p, int *q);

int main(void) {
    int a, b;

    printf("Enter first value : ");
    scanf("%d", &a);

    printf("Enter second value: ");
    scanf("%d", &b);

    printf("\n=== SWAP DEMO ===\n");
    printf("Before : a = %d , b = %d\n", a, b);

    // call swap with addresses
    swap(&a, &b);

    printf("After  : a = %d , b = %d\n", a, b);

    return 0;
}

void swap(int *p, int *q) {
    int t = *p;   // temp
    *p = *q;
    *q = t;
}
