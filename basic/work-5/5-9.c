#include <stdio.h>

typedef struct {
    int id;
    float cost;
    float price;
    int qty;
} Product;

// prototypes
float totalProfit(float cost, float price, int q);
float percentProfit(float cost, float price);

int main(void) {
    Product p;
    float tp;
    float pct;

    // input info
    printf("Product ID: ");
    scanf("%d", &p.id);

    printf("Unit cost: ");
    scanf("%f", &p.cost);

    printf("Unit price: ");
    scanf("%f", &p.price);

    printf("Quantity in stock: ");
    scanf("%d", &p.qty);

    // calculations
    tp = totalProfit(p.cost, p.price, p.qty);
    pct = percentProfit(p.cost, p.price);

    // report
    printf("\n=== PROFIT REPORT ===\n");
    printf("ID: %d\n", p.id);
    printf("Cost: %.2f  Price: %.2f  Qty: %d\n", p.cost, p.price, p.qty);
    printf("Total profit: %.2f\n", tp);
    printf("Profit %%: %.2f%%\n", pct);

    // status
    if (tp > 0)
        printf("Status: PROFIT\n");
    else if (tp < 0)
        printf("Status: LOSS\n");
    else
        printf("Status: BREAK-EVEN\n");

    return 0;
}

// total profit on inventory
float totalProfit(float cost, float price, int q) {
    return (price - cost) * q;
}

// unit profit percentage
float percentProfit(float cost, float price) {
    return ((price - cost) / cost) * 100.0f;
}
