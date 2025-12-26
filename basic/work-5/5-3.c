#include <stdio.h>

#define N 5   // number of elements

// sum elements of array
int sumArray(int a[], int n);

int main(void) {
    int x[N];
    int s = 0;
    float avg = 0.0f;

    // input values
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("#%d: ", i + 1);
        scanf("%d", &x[i]);
    }

    // compute sum
    s = sumArray(x, N);

    // compute average
    avg = (float)s / N;

    // output result
    printf("\n=== SUMMARY ===\n");
    printf("Data: { ");
    for (int i = 0; i < N; i++) {
        printf("%d", x[i]);
        if (i < N - 1) printf(", ");
    }
    printf(" }\n");

    printf("Sum: %d\n", s);
    printf("Average: %.2f\n", avg);

    return 0;
}

int sumArray(int a[], int n) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += a[i];
    }
    return t;
}
