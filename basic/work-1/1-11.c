#include <stdio.h>

int main(void) {
    int category;
    float basePrice, vat = 0.0f, finalPrice = 0.0f;

    if (scanf("%f %d", &basePrice, &category) != 2) {
        return 1;
    }

    switch (category) {
        case 1:     // Standard 7%
            vat = basePrice * 0.07f;
            break;

        case 2:     // Zero Rated 0%
            vat = 0.0f;
            break;

        case 3:     // Luxury 15%
            vat = basePrice * 0.15f;
            break;

        default:
            printf("Invalid Category\n");
            printf("Total Price: 0.00\n");
            return 0;
    }

    finalPrice = basePrice + vat;

    printf("VAT Amount: %.2f\n", vat);
    printf("Total Price: %.2f\n", finalPrice);

    return 0;
}
