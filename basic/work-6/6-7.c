#include <stdio.h>

enum ChanceFlag {
    LOW = 0,
    HIGH = 1
};

// estimate win chance
void eval(int outs, float *pcent, int *flag);

int main(void) {
    int outs = 10;
    float pct = 0.0f;
    int flag;

    // compute probability
    eval(outs, &pct, &flag);

    printf("\n=== ODDS ESTIMATE (2 cards left) ===\n");
    printf("Outs : %d\n", outs);
    printf("Chance: %.2f%%\n", pct);
    printf("Result: %s\n",
           (flag == HIGH) ? "HIGH probability" : "LOW probability");

    return 0;
}

void eval(int outs, float *pcent, int *flag) {
    *pcent = outs * 4.0f;          // simple “rule of 4”
    *flag = (*pcent >= 30.0f) ? HIGH : LOW;
}
