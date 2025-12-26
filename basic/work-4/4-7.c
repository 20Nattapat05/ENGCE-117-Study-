#include <stdio.h>

#define LIMIT 10   // maximum allowed size

int main(void) {
    int arr[LIMIT];
    int n;
    int target;
    int count = 0;

    // read logical size
    scanf("%d", &n);

    // clamp size into range
    if (n < 1 || n > LIMIT)
        n = LIMIT;

    // read data
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // value to search
    scanf("%d", &target);

    // count matches
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            count++;
    }

    // output
    printf("=== RESULT ===\n");
    printf("n = %d\n", n);

    printf("Items: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Find: %d\n", target);
    printf("Count: %d\n", count);

    return 0;
}
