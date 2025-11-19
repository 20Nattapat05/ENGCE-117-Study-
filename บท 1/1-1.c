#include <stdio.h>

int main() {
    int N;

    printf("Enter a number: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Error: Please enter a positive integer greater than 0.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Hello Loop!\n");
    }

    return 0;
}
