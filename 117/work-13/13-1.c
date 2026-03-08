#include <stdio.h>
#include <stdlib.h>

/* Dynamic Programming Knapsack */
int *KnapsackDP(int *weight, int *value, int itemCount, int capacity)
{
    int i, w;

    /* create DP table */
    int **table = (int**)malloc((itemCount + 1) * sizeof(int*));

    for(i = 0; i <= itemCount; i++)
        table[i] = (int*)malloc((capacity + 1) * sizeof(int));

    /* initialize table with 0 */
    for(i = 0; i <= itemCount; i++)
        for(w = 0; w <= capacity; w++)
            table[i][w] = 0;

    /* fill DP table */
    for(i = 1; i <= itemCount; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            table[i][w] = table[i-1][w];   // not take item

            if(weight[i-1] <= w)
            {
                int candidate = value[i-1] +
                                table[i-1][w - weight[i-1]];

                if(candidate > table[i][w])
                    table[i][w] = candidate;   // take item
            }
        }
    }

    /* find selected items */
    int *result = (int*)calloc(itemCount, sizeof(int));

    int remainingWeight = capacity;

    for(i = itemCount; i > 0; i--)
    {
        if(table[i][remainingWeight] != table[i-1][remainingWeight])
        {
            result[i-1] = 1;
            remainingWeight -= weight[i-1];
        }
    }

    return result;
}

int main()
{
    int n = 5;
    int wx = 11;   // max capacity

    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackDP(w, v, n, wx);

    /* print result */
    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}