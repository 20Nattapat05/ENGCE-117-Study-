#include <stdio.h>

int main(void) {
    int count;

    if (scanf("%d", &count) != 1)
        return 1;

    for (int j = 0; j < count; j++) {
        printf("Hello Loop!\n");
    }

    return 0;
}
