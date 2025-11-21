#include <stdio.h>

int main() {
    int num1, num2, operationCode;
    int sum;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &operationCode);

    if (operationCode == 1) {
        sum = num1 + num2;
        printf("%d", sum);
    } 
    else if (operationCode == 2) {
        sum = num1 - num2;
        printf("%d", sum);
    } 
    else if (operationCode == 3) {
        sum = num1 * num2;
        printf("%d", sum);
    } 
    else if (operationCode == 4) {
        if (num2 != 0) {
            sum = num1 / num2;
            printf("%d", sum);
        } else {
            printf("Error");
        }
    } 
    else {
        printf("Invalid Operation");
    }

    return 0;
}
