#include <stdio.h>
#include <stdlib.h>

/* Backtracking Knapsack */
int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x)
{
    if(i == n)          // no more items
        return 0;

    int bestValue = 0;

    /* case 1: not choose item i */
    x[i] = 0;
    int value1 = KnapsackBT(w, v, n, wx, i + 1, x);

    bestValue = value1;

    /* case 2: choose item i (if weight allows) */
    if(w[i] <= wx)
    {
        x[i] = 1;

        int value2 = v[i] +
                     KnapsackBT(w, v, n, wx - w[i], i + 1, x);

        if(value2 > bestValue)
            bestValue = value2;
        else
            x[i] = 0;   // revert choice
    }

    return bestValue;
}

int main()
{
    int n = 5, wx = 11;

    int w[5] = {1,2,5,6,7};
    int v[5] = {1,6,18,22,28};

    int *x, vx;

    x = (int*)malloc(n * sizeof(int));

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d ", vx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}