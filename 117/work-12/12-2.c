#include <stdio.h>
#include <stdlib.h>

/* function prototype */
int *KnapsackGreedy(int *w, int *v, int n, int wx);

/* Greedy Knapsack algorithm */
int *KnapsackGreedy(int *w, int *v, int n, int wx)
{
    int i, j;

    int *choose = (int*)calloc(n, sizeof(int));   // chosen items
    float *score = (float*)malloc(n * sizeof(float)); // value/weight ratio

    /* calculate ratio */
    for(i = 0; i < n; i++)
        score[i] = (float)v[i] / w[i];

    /* sort by ratio (descending) */
    for(i = 0; i < n - 1; i++)
    {
        int best = i;

        for(j = i + 1; j < n; j++)
        {
            if(score[j] > score[best])
                best = j;
        }

        if(best != i)
        {
            /* swap score */
            float ts = score[i];
            score[i] = score[best];
            score[best] = ts;

            /* swap weight */
            int tw = w[i];
            w[i] = w[best];
            w[best] = tw;

            /* swap value */
            int tv = v[i];
            v[i] = v[best];
            v[best] = tv;
        }
    }

    int capacity = 0;

    /* choose items while capacity allows */
    for(i = 0; i < n; i++)
    {
        if(capacity + w[i] <= wx)
        {
            choose[i] = 1;
            capacity += w[i];
        }
    }

    return choose;
}

int main()
{
    int n = 5;
    int wx = 11;   // max weight

    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackGreedy(w, v, n, wx);

    /* print result */
    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}