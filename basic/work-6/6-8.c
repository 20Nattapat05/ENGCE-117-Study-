#include <stdio.h>

#define N 5

enum Flag {
    NOHIT = 0,
    HIT   = 1
};

// replace first occurrence
void replaceFirst(int a[], int n, int key, int repl, int *pflag);
void printArr(int a[], int n);

int main(void) {
    int a[N];
    int key, repl;
    int flag = NOHIT;

    // input
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nValue to find : ");
    scanf("%d", &key);

    printf("Value to put  : ");
    scanf("%d", &repl);

    printf("\n=== UPDATE REPORT ===\n");
    printf("Before: ");
    printArr(a, N);

    // do update
    replaceFirst(a, N, key, repl, &flag);

    printf("After : ");
    printArr(a, N);

    printf("Status: %s\n", (flag == HIT) ? "UPDATED" : "NOT FOUND");

    return 0;
}

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void replaceFirst(int a[], int n, int key, int repl, int *pflag) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            a[i] = repl;     // perform replacement
            *pflag = HIT;    // set status
            return;          // stop after first match
        }
    }
}
