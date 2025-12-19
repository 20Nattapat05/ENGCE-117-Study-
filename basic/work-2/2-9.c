#include <stdio.h>

int main() {
    int initialStock, N;
    int cmdCode, quantity;
    int currentStock;
    float PENALTY_FEE;
    float totalPenalties = 0.0;

    /* Read initial values */
    if (scanf("%d %f %d", &initialStock, &PENALTY_FEE, &N) != 3) {
        return 1;
    }

    currentStock = initialStock;

    /* Process commands */
    for (int i = 0; i < N; i++) {
        if (scanf("%d %d", &cmdCode, &quantity) != 2) {
            return 1;
        }

        switch (cmdCode) {
            case 1:  /* Receive stock */
                currentStock += quantity;
                printf("Received %d units.\n", quantity);
                break;

            case 2:  /* Ship stock */
                if (quantity <= 0) {
                    printf("Error: Quantity must be positive.\n");
                } else if (quantity <= currentStock) {
                    currentStock -= quantity;
                    printf("Shipped %d units.\n", quantity);
                } else {
                    totalPenalties += PENALTY_FEE;
                    printf("FAILURE: Insufficient stock. PENALTY %.2f added.\n", PENALTY_FEE);
                }
                break;

            case 3:  /* Check status */
                printf("Current Stock: %d\n", currentStock);
                printf("Total Penalties: %.2f\n", totalPenalties);
                break;

            default: /* Invalid command */
                printf("Error: Invalid Command.\n");
                break;
        }
    }

    return 0;
}
