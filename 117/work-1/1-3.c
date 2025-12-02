#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *num);

int main()
{
    int *data, num;
    data = GetSet(&num);
    return 0;
}

int *GetSet(int *num)
{
    printf("Enter the number of elements in the set: ");
    scanf("%d", num);

    // Allocate memory dynamically for the set
    int *set = (int *)malloc((*num) * sizeof(int));

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < *num; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &set[i]);
    }

    return set; // Return pointer to the dynamically allocated array
}
