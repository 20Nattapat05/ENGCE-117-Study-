#include <stdio.h>

#define LIM 10   // max size

int main(void) {
    int a[LIM];
    int n;
    int i, j;

    // read size
    scanf("%d", &n);

    // clamp
    if (n < 1 || n > LIM)
        n = LIM;

    // read values
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // simple sort (ascending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    // header
    printf("\n=== FREQUENCY REPORT ===\n");
    printf("N = %d\n", n);

    printf("\nValue | Count\n");
    printf("------|------\n");

    // count frequency of each distinct value
    for (i = 0; i < n; i++) {
        int c = 1;

        while (i < n - 1 && a[i] == a[i + 1]) {
            c++;
            i++;
        }

        printf("  %d   |  %d\n", a[i], c);
    }

    return 0;
}
