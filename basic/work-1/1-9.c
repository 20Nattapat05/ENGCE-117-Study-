#include <stdio.h>

int main(void) {

    int zone;
    float weight, cost = 0.0f;

    if (scanf("%d %f", &zone, &weight) != 2) {
        return 1;
    }

    switch (zone) {
        case 1:
            cost = (weight <= 5.0f) ? 50.0f : 80.0f;
            break;

        case 2:
            cost = (weight <= 10.0f) ? 150.0f : 250.0f;
            break;

        case 3:
            cost = 500.0f;
            break;

        default:
            printf("Invalid Zone Code\n");
            return 0;
    }

    printf("%.2f\n", cost);

    return 0;
}
