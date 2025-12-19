#include <stdio.h>

int main(void) {
    int plan;
    float usage, bill;

    if (scanf("%d %f", &plan, &usage) != 2) {
        return 1;
    }

    bill = 0.0f;

    switch (plan) {
        case 1:     // Basic Plan
            bill = 299.0f;
            if (usage > 10.0f) {
                bill += (usage - 10.0f) * 10.0f;
            }
            break;

        case 2:     // Premium Plan
            bill = 599.0f;
            if (usage > 20.0f) {
                bill += 50.0f + (usage - 20.0f) * 5.0f;
            }
            break;

        default:
            printf("Invalid Plan Code\n");
            return 0;
    }

    printf("%.2f\n", bill);
    return 0;
}
