#include <stdio.h>

int main(void) {
    int n = 0;
    int x;
    int pass_sum = 0;
    int fail_num = 0;

    // read amount
    if (scanf("%d", &n) != 1)
        return 1;

    // process as streaming input
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &x) != 1)
            return 1;

        if (x >= 50)          // pass case
            pass_sum += x;
        else                  // fail case
            fail_num++;
    }

    // output result
    printf("Sum of passes: %d\n", pass_sum);
    printf("Number of fails: %d\n", fail_num);

    return 0;
}
