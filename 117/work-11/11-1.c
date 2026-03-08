#include <stdio.h>

/* function prototype */
int binarySearch(int arr[], int size, int target);

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 7};
    int length = 6;
    int key = 5;

    /* search value */
    int result = binarySearch(numbers, length, key);

    if(result >= 0)
        printf("Value %d found at index %d\n", key, result);
    else
        printf("Value not found\n");

    return 0;
}

/* Binary Search algorithm */
int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int mid = (start + end) / 2;   // middle index

        if(arr[mid] == target)
            return mid;

        if(target > arr[mid])
            start = mid + 1;   // search right
        else
            end = mid - 1;     // search left
    }

    return -1;   // not found
}