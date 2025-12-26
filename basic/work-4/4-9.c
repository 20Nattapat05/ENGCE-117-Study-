#include <stdio.h>

int main(void) {
    int income;
    float tax = 0.0f;
    float netpay = 0.0f;

    // read income
    scanf("%d", &income);

    // tax brackets
    if (income < 20000)
        tax = 0.0f;
    else if (income < 50000)
        tax = income * 0.05f;
    else
        tax = income * 0.10f;

    // compute net
    netpay = income - tax;

    // output
    printf("=== PAY REPORT ===\n");
    printf("Income: %d THB\n", income);
    printf("Tax: %.2f THB\n", tax);
    printf("Net: %.2f THB\n", netpay);

    return 0;
}
