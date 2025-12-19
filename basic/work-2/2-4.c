#include <stdio.h>

int main() {
    double principal, monthlyPayment;
    int month = 0;

    // Input
    if (scanf("%lf %lf", &principal, &monthlyPayment) != 2) return 1;

    while (principal > 0) {
        month++;

        principal += principal * 0.01;          // interest
        if (monthlyPayment < principal * 0.01)  // penalty
            principal += 10.0;

        principal -= monthlyPayment;             // payment
        principal = (int)(principal * 100 + (principal >= 0 ? 0.5 : -0.5)) / 100.0; // round

        printf("Month %d: Remaining %.2f\n", month, principal);
    }

    printf("Loan settled in %d months.\n", month);
    return 0;
}
