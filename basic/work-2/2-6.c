#include <stdio.h>

int main(void) {
    int months, month;
    int success = 0;

    if (scanf("%d", &months) != 1)
        return 1;

    for (month = 1; month <= months; ++month) {
        float total = 0.0f;
        float x;

        // read deposits until 0
        while (1) {
            if (scanf("%f", &x) != 1)
                return 1;

            if (x == 0.0f)       // sentinel
                break;

            if (x > 0.0f)        // add only positive
                total += x;
        }

        printf("Month %d Total: %.2f\n", month, total);

        if (total >= 500.0f)     // success threshold
            success++;
    }

    printf("Success Count: %d\n", success);
    return 0;
}
