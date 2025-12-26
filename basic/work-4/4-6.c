#include <stdio.h>

#define NSTD 5   // number of students

int main(void) {
    int score[NSTD];
    int sum = 0;
    float mean = 0.0f;
    int above = 0;

    // read all scores
    for (int i = 0; i < NSTD; i++) {
        scanf("%d", &score[i]);
        sum += score[i];
    }

    // compute average
    mean = (float)sum / NSTD;

    // count above average
    for (int i = 0; i < NSTD; i++) {
        if (score[i] > mean)
            above++;
    }

    // output report
    printf("=== RESULT REPORT ===\n");
    printf("List: ");
    for (int i = 0; i < NSTD; i++) {
        printf("%d ", score[i]);
    }
    printf("\n");

    printf("Total: %d\n", sum);
    printf("Average: %.2f\n", mean);
    printf("Above average: %d\n", above);

    return 0;
}
