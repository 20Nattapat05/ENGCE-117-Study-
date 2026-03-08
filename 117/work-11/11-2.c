#include <stdio.h>

/* function prototypes */
void mergesort(int arr[], int size);
void merge(int *left, int m, int *right, int n, int *temp);

/* Merge Sort algorithm */
void mergesort(int arr[], int size)
{
    if(size < 2)
        return;   // base case

    int leftSize = size / 2;
    int rightSize = size - leftSize;

    /* sort left and right halves */
    mergesort(arr, leftSize);
    mergesort(arr + leftSize, rightSize);

    int buffer[size];

    /* merge sorted halves */
    merge(arr, leftSize, arr + leftSize, rightSize, buffer);

    /* copy back to original array */
    for(int i = 0; i < size; i++)
        arr[i] = buffer[i];
}

/* merge two sorted arrays */
void merge(int *left, int m, int *right, int n, int *temp)
{
    int i = 0, j = 0, k = 0;

    while(i < m || j < n)
    {
        if(i < m && (j >= n || left[i] <= right[j]))
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }
}

int main()
{
    int data[7] = {4, 6, 1, 2, 5, 1, 8};
    int n = 7;

    mergesort(data, n);

    /* print sorted result */
    for(int i = 0; i < n; i++)
        printf("%d ", data[i]);

    return 0;
}