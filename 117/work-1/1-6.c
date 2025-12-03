#include <stdio.h>
#include <stdlib.h> // For malloc

// Declare the prototype of the GetMatrix function
int* GetMatrix(int *row, int *col);

int main() {
    int *data, m, n;

    // Get the matrix from user input and print it
    data = GetMatrix(&m, &n);

    return 0;
}

int* GetMatrix(int *row, int *col) {
    // Ask the user for the number of rows and columns
    printf("Enter number of rows: ");
    scanf("%d", row);
    printf("Enter number of columns: ");
    scanf("%d", col);

    // Dynamically allocate memory for the matrix
    int *matrix = (int *)malloc((*row) * (*col) * sizeof(int));

    // Ask the user to input the values for the matrix
    printf("Enter the values for the matrix:\n");
    for (int i = 0; i < (*row); i++) {
        for (int j = 0; j < (*col); j++) {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i * (*col) + j]);
        }
    }

    // Print the matrix without showing [0][0] explicitly
    printf("The matrix you entered is:\n");
    for (int i = 0; i < (*row); i++) {
        for (int j = 0; j < (*col); j++) {
            if (i == 0 && j == 0) continue; // Skip printing [0][0] explicitly
            printf("%d ", matrix[i * (*col) + j]);
        }
        printf("\n");
    }

    return matrix;
}
