#include <stdio.h>

int main() {
    int N;
    int sum = 0;
    int i;

    scanf("%d", &N);

    if (N <= 0) {
        printf("0");
        return 0;
    }

    for (i = 1; i <= N; i++) {
        sum = sum + i;
    }

    printf("%d", sum);

    return 0;
}
