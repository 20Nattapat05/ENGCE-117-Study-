#include <stdio.h>

#define MONTHS 3

typedef enum {
    FAIL = 0,
    SUCCESS = 1
} BusinessState;

void readValues(int data[], int size, const char *title);
long getTotal(int data[], int size);
BusinessState checkProfit(int earn[], int spend[], int size, int *balance);

int main()
{
    int earn[MONTHS];
    int spend[MONTHS];
    int balance = 0;

    readValues(earn, MONTHS, "INCOME");
    readValues(spend, MONTHS, "COST");

    BusinessState result = checkProfit(earn, spend, MONTHS, &balance);

    printf("\n==== 3 MONTH SUMMARY ====\n");
    printf("TOTAL INCOME : %ld\n", getTotal(earn, MONTHS));
    printf("TOTAL COST   : %ld\n", getTotal(spend, MONTHS));
    printf("NET BALANCE  : %d\n", balance);

    printf("STATUS: ");
    printf(result == SUCCESS ? "PROFITABLE\n" : "NOT PROFITABLE\n");

    return 0;
}

/* -------- FUNCTIONS -------- */

void readValues(int data[], int size, const char *title)
{
    printf("\nEnter %s for %d months\n", title, size);

    for(int i = 0; i < size; i++)
    {
        printf("Month %d: ", i + 1);
        scanf("%d", &data[i]);
    }
}

long getTotal(int data[], int size)
{
    long sum = 0;
    int i = 0;

    while(i < size)
    {
        sum += data[i++];
    }

    return sum;
}

BusinessState checkProfit(int earn[], int spend[], int size, int *balance)
{
    int temp = 0;

    for(int i = 0; i < size; i++)
    {
        temp += earn[i] - spend[i];
    }

    *balance = temp;

    return (temp >= 0) ? SUCCESS : FAIL;
}
