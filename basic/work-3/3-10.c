#include <stdio.h>

#define VAT_RATE 0.07f // VAT %

typedef struct {
    char name[50];
    float price;
    int qty;
} Item;

// item total
static float item_total(float price, int qty) {
    return price * qty; // mul
}

int main(void) {
    int n = 0;              // item count
    float subtotal = 0.0f;  // sum before VAT
    Item it;                // temp item

    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    printf("\n--- RECEIPT ---\n"); // header

    for (int i = 1; i <= n; ++i) {
        float one = 0.0f; // line total

        // read one
        if (scanf("%49s %f %d",
                  it.name, &it.price, &it.qty) != 3)
            return 1;

        one = item_total(it.price, it.qty); // compute
        subtotal += one;                    // add

        printf("%s x %d = %.2f\n", it.name, it.qty, one); // line
    }

    float vat = subtotal * VAT_RATE;      // VAT
    float grand = subtotal + vat;         // final

    printf("------------------\n");
    printf("Subtotal: %.2f\n", subtotal); // sub
    printf("VAT (7%%): %.2f\n", vat);     // vat
    printf("Grand Total: %.2f\n", grand); // total

    return 0; // ok
}
