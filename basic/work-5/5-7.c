#include <stdio.h>

#define N 5   // number of elements

// prototypes
void sortAsc(int a[], int n);
void show(int a[], int n);

int main(void) {
    int x[N];
    int backup[N];

    // input
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &x[i]);
        backup[i] = x[i];   // keep original
    }

    // sort ascending
    sortAsc(x, N);

    // report
    printf("\n=== SORT REPORT ===\n");

    printf("Original: ");
    show(backup, N);

    printf("Ascending: ");
    show(x, N);

    return 0;
}

// simple ascending sort
void sortAsc(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

// print array
void show(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
