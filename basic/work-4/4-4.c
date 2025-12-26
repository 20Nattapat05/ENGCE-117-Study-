#include <stdio.h>

#define N 5   // number of inputs

int main(void) {
    int a[N];
    int cnt_even = 0, cnt_odd = 0;

    // read input
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // simple classification
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 0)
            cnt_even++;
        else
            cnt_odd++;
    }

    // output
    printf("=== RESULT ===\n");
    printf("List: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Even: %d\n", cnt_even);
    printf("Odd: %d\n", cnt_odd);

    return 0;
}
