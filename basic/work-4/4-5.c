#include <stdio.h>

#define COUNT 6   // how many numbers

int main(void) {
    int arr[COUNT];
    int sum = 0;

    // read inputs
    for (int i = 0; i < COUNT; i++) {
        printf("Input #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // print and add
    printf("\n=== SUMMARY ===\n");
    printf("Values: ");

    for (int i = 0; i < COUNT; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }

    printf("\nTotal: %d\n", sum);

    return 0;
}
