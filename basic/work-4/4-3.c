#include <stdio.h>

#define NDAY 7   // number of days

int main(void) {
    int t[NDAY];
    int maxTemp;
    int i;

    // read inputs and track max
    for (i = 0; i < NDAY; i++) {
        scanf("%d", &t[i]);

        // init or update max
        if (i == 0 || t[i] > maxTemp) {
            maxTemp = t[i];
        }
    }

    // summary
    printf("=== WEEK REPORT ===\n");
    printf("Temps: ");

    for (i = 0; i < NDAY; i++) {
        printf("%d ", t[i]);
    }

    printf("\nMax temp: %d C\n", maxTemp);

    // simple classification
    if (maxTemp >= 35)
        printf("Status: HOT\n");
    else
        printf("Status: NORMAL\n");

    return 0;
}
