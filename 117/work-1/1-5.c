#include <stdio.h>

// Function to get matrix values and display it
void GetMatrix(int value[], int *row, int *col);

int main() {
    int m, n;               // Number of rows and columns
    int data[100];          // Matrix data
    GetMatrix(data, &m, &n); // Call function to get and display matrix

    return 0;
}

// Function to input matrix values and display the matrix
void GetMatrix(int value[], int *row, int *col) {
    // Get number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", row);
    printf("Enter the number of columns: ");
    scanf("%d", col);

    // Get matrix values from user
    int total_elements = (*row) * (*col);
    for (int i = 0; i < total_elements; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value[i]);
    }

    // Display the matrix
    printf("The matrix is:\n");
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            printf("%d ", value[i * (*col) + j]);
        }
        printf("\n");
    }
}
