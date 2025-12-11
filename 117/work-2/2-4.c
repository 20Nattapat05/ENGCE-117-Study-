#include <stdio.h>
#include <stdlib.h>

// Return dynamic matrix, row/col via pointer
int *GetMatrix(int *row, int *col);

int main()
{
    int *data, m, n;

    data = GetMatrix(&m, &n);

    return 0;
}

// ---------------------------

int *GetMatrix(int *r, int *c)
{
    printf("Enter Rows: ");
    scanf("%d", r);

    printf("Enter Cols: ");
    scanf("%d", c);

    if (*r <= 0 || *c <= 0)
        return NULL; // invalid size

    int size = (*r) * (*c);
    int *mat = malloc(size * sizeof(int));
    if (!mat)
        return NULL; // malloc failed

    printf("Input elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &mat[i]); // fill data
    }

    // Print the matrix after input
    printf("\n--- Result ---\n");
    printf("Matrix Size: %d x %d\n", *r, *c);

    for (int i = 0; i < size; i++) {
        printf("%d ", mat[i]);
        if ((i + 1) % (*c) == 0) {
            printf("\n");  // Print a new line after each row
        }
    }

    return mat; // return pointer to matrix
}
