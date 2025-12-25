#include <stdio.h>

// data struct
typedef struct {
    char name[50];
    float target;
    float actual;
} SalesRecord;

// one commission
static float commission(float target, float actual) {
    float c = actual * 0.10f;     // base 10%

    if (actual >= target * 1.20f) // >=120%
        c += 200.0f;              // big bonus
    else if (actual >= target)    // >=100%
        c += 50.0f;               // bonus
    else if (actual < target * 0.90f) // <90%
        c -= 100.0f;              // penalty

    return c; // result
}

int main(void) {
    int n = 0;
    float total = 0.0f; // grand sum
    SalesRecord r;      // temp rec

    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    for (int i = 0; i < n; ++i) {
        // read one
        if (scanf("%f %f %49s",
                  &r.target,
                  &r.actual,
                  r.name) != 3)
            return 1;

        total += commission(r.target, r.actual); // add
    }

    printf("Grand Total Commission: %.2f\n", total); // print

    return 0; // ok
}
