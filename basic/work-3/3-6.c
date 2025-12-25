#include <stdio.h>

// data struct
typedef struct {
    char desc[50];
    float amount;
} Transaction;

// process one
static void proc(const Transaction *t, float *inc, float *exp) {
    if (t->amount >= 0.0f)          // income?
        *inc += t->amount;          // add in
    else
        *exp += -t->amount;         // add out
}

int main(void) {
    int n = 0;
    float income = 0.0f;  // total in
    float expense = 0.0f; // total out

    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    Transaction tr; // temp item

    for (int i = 0; i < n; ++i) {
        // read one
        if (scanf("%f %49s", &tr.amount, tr.desc) != 2) return 1;
        proc(&tr, &income, &expense); // handle
    }

    printf("Total Income: %.2f\n", income);                 // print in
    printf("Total Expense: %.2f\n", expense);               // print out
    printf("Net Balance: %.2f\n", income - expense);        // net

    return 0; // ok
}
