#include <stdio.h>
#include <stdlib.h>

#define SHIPPING_FEE 50.0f   // ship fee

typedef struct {
    int id;
    float price;
    int qty;
} Order;

// total per order
static float order_total(const Order *o) {
    float t = o->price * o->qty + SHIPPING_FEE; // base sum
    return (t >= 500.0f) ? t * 0.9f : t;        // 10% off
}

int main(void) {
    int n = 0;
    float grand = 0.0f; // all sum

    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    Order *list = (Order *)malloc((size_t)n * sizeof(*list));
    if (!list) return 1; // no mem

    for (int i = 0; i < n; ++i) {
        // read one
        if (scanf("%d %f %d",
                  &list[i].id,
                  &list[i].price,
                  &list[i].qty) != 3) {
            free(list);
            return 1;
        }

        grand += order_total(&list[i]); // add total
    }

    printf("Grand Total: %.2f\n", grand); // print all

    free(list); // cleanup
    return 0;   // ok
}
