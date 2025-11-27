#include <stdio.h>

int main()
{
    int dayCode, hour;

    scanf("%d", &dayCode);
    scanf("%d", &hour);

    if (dayCode >= 1 && dayCode <= 5)
    {
        if (hour >= 8 && hour <= 17)
            printf("System Running (Workday)\n");
        else
            printf("System Idle (Off-hours)\n");
    }
    else if (dayCode == 6 || dayCode == 7)
    {
        printf("Weekend Relax Mode\n");
    }
    else
    {
        printf("Invalid Day Code\n");
    }

    return 0;
}
