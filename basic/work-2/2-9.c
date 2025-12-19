#include <stdio.h>
#include <string.h>

int main() {
    int initialStock, N;
    int cmdCode, quantity;
    int currentStock;
    float PENALTY_FEE;
    float totalPenalties = 0.0;

    char outputs[5000] = "";  // Store all messages here

    /* Read initial values */
    if (scanf("%d %f %d", &initialStock, &PENALTY_FEE, &N) != 3) {
        return 1;
    }

    currentStock = initialStock;

    /* Process commands and record outputs */
    for (int i = 0; i < N; i++) {
        if (scanf("%d %d", &cmdCode, &quantity) != 2) {
            return 1;
        }

        char buffer[256];  // temporary message

        switch (cmdCode) {
            case 1:  /* Receive stock */
                currentStock += quantity;
                sprintf(buffer, "Received %d units.\n", quantity);
                strcat(outputs, buffer);
                break;

            case 2:  /* Ship stock */
                if (quantity <= 0) {
                    sprintf(buffer, "Error: Quantity must be positive.\n");
                } else if (quantity <= currentStock) {
                    currentStock -= quantity;
                    sprintf(buffer, "Shipped %d units.\n", quantity);
                } else {
                    totalPenalties += PENALTY_FEE;
                    sprintf(buffer, "FAILURE: Insufficient stock. PENALTY %.2f added.\n", PENALTY_FEE);
                }
                strcat(outputs, buffer);
                break;

            case 3:  /* Check status */
                sprintf(buffer, "Current Stock: %d\nTotal Penalties: %.2f\n", currentStock, totalPenalties);
                strcat(outputs, buffer);
                break;

            default: /* Invalid command */
                sprintf(buffer, "Error: Invalid Command.\n");
                strcat(outputs, buffer);
                break;
        }
    }

    /* Print all results at once */
    printf("%s", outputs);
    printf("\n--- Final Summary ---\n");
    printf("Final Stock: %d\n", currentStock);
    printf("Total Penalties: %.2f\n", totalPenalties);

    return 0;
}
