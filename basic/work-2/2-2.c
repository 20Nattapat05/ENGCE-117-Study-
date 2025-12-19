#include <stdio.h>

int main(void) {
    int items;
    float price, total = 0.0f;

    if (scanf("%d", &items) != 1) {
        return 1;
    }

    while (items-- > 0) {
        int qty;
        float cost;

        scanf("%f %d", &price, &qty);

        cost = price * qty;

        if (price >= 1000.0f) {
            cost *= 0.9f;   // apply 10% discount
        }

        total += cost;
    }

    printf("Grand Total: %.2f\n", total);
    return 0;
}
