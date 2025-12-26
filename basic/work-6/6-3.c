#include <stdio.h>

#define N 3   // array size

int main(void) {
    int a[N];
    int *p;

    // input values
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Index %d -> ", i);
        scanf("%d", &a[i]);
    }

    // point to first element
    p = a;

    printf("\n=== POINTER VIEW ===\n");
    printf("Idx | Value | *p val | Address\n");
    printf("-------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("%3d | %5d | %7d | %p\n",
               i,
               a[i],
               *p,
               (void *)p);
        p++;   // move to next element
    }

    return 0;
}
