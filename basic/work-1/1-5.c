#include <stdio.h>

int main()
{
    int number;
    int evensum = 0;
    int oddsum = 0;

    if (scanf("%d", &number) != 1)
    {
        return 1;
    }

    while (number != 0)
    {
        if (number % 2 == 0)
        {
            evensum = evensum + number;
        }
        else
        {
            oddsum = oddsum + number;
        }

        if (scanf("%d", &number) != 1)
        {
            return 1;
        }
    }

    printf("Even Sum: %d\n", evensum);
    printf("Odd Sum: %d\n", oddsum);

    return 0;
}