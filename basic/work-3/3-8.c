#include <stdio.h>

// data struct
typedef struct {
    char name[50];
    float price;
    int sales;
    float adCost;
} Campaign;

// get rate
static float rate_for(int sales) {
    if (sales >= 20) return 0.20f; // top
    else if (sales >= 10) return 0.15f; // mid
    else return 0.10f; // base
}

int main(void) {
    int n = 0;
    Campaign c; // temp rec

    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    for (int i = 1; i <= n; ++i) {
        float revenue; // gross
        float rate;    // percent
        float net;     // result

        // read one
        if (scanf("%49s %f %d %f",
                  c.name, &c.price, &c.sales, &c.adCost) != 4)
            return 1;

        revenue = c.price * c.sales; // rev
        rate = rate_for(c.sales);    // get
        net = (revenue * rate) - c.adCost; // net

        printf("--- Campaign: %s ---\n", c.name);
        printf("Sales: %d, Ad Spend: %.2f\n", c.sales, c.adCost);
        printf("Rate Used: %.0f%%\n", rate * 100.0f);
        printf("Calculation: (%.2f * %.0f%%) - %.2f = %.2f\n",
               revenue, rate * 100.0f, c.adCost, net);
        printf("Net Result: %.2f\n", net);
    }

    return 0; // ok
}
