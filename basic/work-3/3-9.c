#include <stdio.h>

// spend rule
static float calc_spend(float budget) {
    if (budget >= 500.0f) return 100.0f;
    if (budget >= 100.0f) return 50.0f;
    if (budget > 0.0f)    return 20.0f;
    return 0.0f;
}

int main(void) {
    int days = 0;   // total days
    float budget = 0.0f; // current
    float spend = 0.0f;  // today

    // read input
    if (scanf("%f %d", &budget, &days) != 2 || days < 0)
        return 1;

    // header
    printf("Day | Spend | Remaining\n");
    printf("----------------------\n");

    for (int d = 1; d <= days; ++d) {
        spend = calc_spend(budget);   // plan

        if (spend > budget)           // cap
            spend = budget;

        budget -= spend;              // update

        printf("%d | %.2f | %.2f\n", d, spend, budget); // row
    }

    printf("----------------------\n");
    printf("Final Budget: %.2f\n", budget); // final

    return 0; // ok
}
