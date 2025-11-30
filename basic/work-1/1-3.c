#include <stdio.h>

int main() {
    int num1, num2, operationCode;

    scanf("%d %d %d", &num1, &num2, &operationCode);

    if (operationCode == 1) {
        printf("%d\n", num1 + num2);
    }
    else if (operationCode == 2) {
        printf("%d\n", num1 - num2);
    }
    else if (operationCode == 3) {
        printf("%d\n", num1 * num2);
    }
    else if (operationCode == 4) {
        if (num2 != 0) {
            printf("%d\n", num1 / num2);
        } else {
            printf("Error\n");
        }
    }
    else {
        printf("Invalid Operation\n");
    }

    return 0;
}
