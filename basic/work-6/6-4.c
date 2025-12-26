#include <stdio.h>

// compute sum and product via pointers
void compute(int x, int y, int *ps, int *pp);
void printResult(int x, int y, int s, int p);

int main(void) {
    int a, b;
    int s, p;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // call function (pass results by pointer)
    compute(a, b, &s, &p);

    // output
    printResult(a, b, s, p);

    return 0;
}

void compute(int x, int y, int *ps, int *pp) {
    *ps = x + y;   // sum
    *pp = x * y;   // product
}

void printResult(int x, int y, int s, int p) {
    printf("\n=== RESULT ===\n");
    printf("A = %d\n", x);
    printf("B = %d\n", y);
    printf("Sum = %d\n", s);
    printf("Product = %d\n", p);
}
