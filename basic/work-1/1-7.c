#include <stdio.h>

int main()
{
    int customerType;
    double consumption_kwh, totalBill;

    printf("Enter customer type (1 or 2): ");
    scanf("%d", &customerType);

    printf("Enter consumption (kWh): ");
    scanf("%lf", &consumption_kwh);

    if (customerType == 1)
    {
        if (consumption_kwh <= 100)
        {
            totalBill = consumption_kwh * 3.0;
        }
        else
        {
            totalBill = consumption_kwh * 4.0;
        }
    }
    else if (customerType == 2)
    {
        if (consumption_kwh <= 500)
        {
            totalBill = consumption_kwh * 5.0;
        }
        else
        {
            totalBill = consumption_kwh * 6.5;
        }
    }
    else
    {
        printf("Invalid Customer Type\n");
        return 1;
    }

    printf("Total Bill: %.2f\n", totalBill);
    return 0;
}
