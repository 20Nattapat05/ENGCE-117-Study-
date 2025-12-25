#include <stdio.h>

int main(void) {
    int choice = 0;        // menu
    float total = 0.0f;    // sum
    float money = 0.0f;    // paid

    // price table
    float price[] = {0.0f, 15.0f, 10.0f, 25.0f};

    for (;;) { // loop forever
        // menu UI
        printf("\n--- Vending Machine ---\n");
        printf("1. Coke (15.00)\n");
        printf("2. Water (10.00)\n");
        printf("3. Snack (25.00)\n");
        printf("4. Exit and Pay\n");
        printf("Current Total: %.2f\n", total);

        if (scanf("%d", &choice) != 1) return 1; // bad input

        if (choice == 4) break; // exit

        if (choice >= 1 && choice <= 3) {
            total += price[choice]; // add item
            printf("Item added.\n");
        } else {
            printf("Invalid selection.\n"); // bad choice
        }
    }

    if (total <= 0.0f) { // nothing
        printf("No items purchased. Goodbye!\n");
        return 0;
    }

    printf("\nTotal due: %.2f\n", total); // due
    printf("Enter paid amount: ");

    if (scanf("%f", &money) != 1) return 1; // bad input

    if (money >= total)
        printf("Change: %.2f\n", money - total); // change
    else
        printf("Not enough money.\n"); // insufficient

    return 0; // ok
}
