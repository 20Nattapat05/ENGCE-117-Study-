#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    // read count
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    // allocate array
    int *data = malloc((size_t)n * sizeof *data);
    if (!data) {
        return 1;
    }

    // read values
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data[i]) != 1) {
            free(data);
            return 1;
        }
    }

    // print in reverse
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", data[i]);
    }

    free(data);
    return 0;
}
