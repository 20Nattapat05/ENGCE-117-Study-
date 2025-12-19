#include <stdio.h>

int main(void) {
    int term;
    float amount, interest = 0.0f, rate = 0.0f;

    if (scanf("%d %f", &term, &amount) != 2) {
        return 1;
    }

    switch (term) {
        case 1:
            rate = (amount < 5000.0f) ? 0.03f : 0.04f;
            break;

        case 2:
            rate = (amount < 10000.0f) ? 0.05f : 0.065f;
            break;

        case 3:
            rate = 0.08f;
            break;

        default:
            printf("Invalid Term Code\n");
            return 0;
    }

    interest = amount * rate;
    printf("%.2f\n", interest);

    return 0;
}
