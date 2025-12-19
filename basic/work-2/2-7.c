#include <stdio.h>

int main(void) {
    int n;
    int countFizzBuzz = 0, countFizz = 0, countBuzz = 0, countOther = 0;

    if (scanf("%d", &n) != 1)
        return 1;

    // loop through numbers 1 to n
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0)
            countFizzBuzz++;
        else if (i % 3 == 0)
            countFizz++;
        else if (i % 5 == 0)
            countBuzz++;
        else
            countOther++;
    }

    printf("Count FizzBuzz (by 15): %d\n", countFizzBuzz);
    printf("Count Fizz (by 3 only): %d\n", countFizz);
    printf("Count Buzz (by 5 only): %d\n", countBuzz);
    printf("Count Other: %d\n", countOther);

    return 0;
}
