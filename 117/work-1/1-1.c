#include <stdio.h>

int main() {
    int n = 0;
    int i = 0;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        printf("[%d] Hello World\n", i);
    }

    return 0;
}
