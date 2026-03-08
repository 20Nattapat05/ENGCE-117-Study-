#include <stdio.h>

/* function prototypes */
long SumLoop(int n);
long SumRecur(int n);

int main()
{
    printf("SumLoop(n) = %ld\n", SumLoop(10));
    printf("SumRecur(n) = %ld\n", SumRecur(10));

    return 0;
}

/* calculate sum using loop */
long SumLoop(int n)
{
    long total = 0;

    while (n > 0)
    {
        total += n;   // add current n
        n--;          // decrease n
    }

    return total;
}

/* calculate sum using recursion */
long SumRecur(int n)
{
    if (n <= 1)
        return n;     // base case

    int mid = n / 2;  // divide problem

    return SumRecur(mid) + SumRecur(n) - SumRecur(mid - 1);
}