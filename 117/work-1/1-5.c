#include <stdio.h>
#include <stdlib.h>

// ประกาศฟังก์ชัน GetMatrix ก่อน
void GetMatrix(int **value, int *row, int *col);

int main()
{
    int *data, m, n;

    // เรียกใช้ฟังก์ชัน GetMatrix
    GetMatrix(&data, &m, &n);

    return 0;
}

void GetMatrix(int **value, int *row, int *col)
{
    // รับจำนวนแถวและคอลัมน์จากผู้ใช้
    printf("Enter the number of rows: ");
    scanf("%d", row);
    printf("Enter the number of columns: ");
    scanf("%d", col);

    // จองพื้นที่ให้กับเมทริกซ์
    *value = (int *)malloc((*row) * (*col) * sizeof(int));

    // รับค่าเมทริกซ์จากผู้ใช้
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *col; j++)
        {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &(*value)[i * (*col) + j]); // เก็บค่าในเมทริกซ์แบบ 1D
        }
    }

    // การแสดงผลเมทริกซ์
    printf("The entered matrix is:\n");
    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *col; j++)
        {
            printf("%d ", (*value)[i * (*col) + j]);
        }
        printf("\n");
    }
}
