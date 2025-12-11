#include <stdio.h>
#include <stdlib.h>  // For malloc

// Declare GetSet function
int GetSet(int **data);

int main() {
    int *data, num;
    
    // Call GetSet function
    num = GetSet(&data);
    
    return 0;
}

// GetSet function to get user input
int GetSet(int **data) {
    int num;
    
    // Allocate memory for 100 integers
    *data = (int *)malloc(sizeof(int) * 100);  // Allocate memory for 100 integers
    
    // Check if memory allocation is successful
    if (*data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }
    
    // Get the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &num);
    
    // Get the values of each element
    printf("Enter the elements:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &(*data)[i]);
    }

    // Print number and values of elements
    printf("Number of elements: %d\n", num);
    printf("Elements are:\n");
    for (int i = 0; i < num; i++) {
        printf("%d ", (*data)[i]);
    }
    printf("\n");
    
    return num;  // Return the number of elements
}
